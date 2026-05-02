from __future__ import annotations

from pathlib import Path

from ek_tm4c129exl_holder import (
    BOARD_LENGTH_MM,
    BOARD_THICKNESS_MM,
    BOARD_WIDTH_MM,
    Box,
    INCH_TO_MM,
    build_mesh,
    mm,
)


XY_CLEARANCE_MM = 0.6
BASE_MARGIN_MM = 8.0
BASE_THICKNESS_MM = 3.0
STANDOFF_HEIGHT_MM = 4.0
GUIDE_WALL_THICKNESS_MM = 2.4
GUIDE_LENGTH_MM = 11.0
GUIDE_TOP_CLEARANCE_MM = 1.0

DRAWING_MOUNT_HOLE_DIAMETER_MM = 0.125 * INCH_TO_MM
CHOSEN_SCREW_SIZE = "M3"
MOUNT_SLOT_SIZE_MM = 5.0
STANDOFF_SIZE_MM = 9.0

# First-version mounting centers inferred from Figure A-1, relative to the
# lower-left board corner. Slots are intentionally oversized to absorb figure
# reading uncertainty without requiring a CAD-exact hole extraction.
MOUNT_CENTERS_MM = [
    (1.15 * INCH_TO_MM, 0.75 * INCH_TO_MM),
    (3.35 * INCH_TO_MM, 2.05 * INCH_TO_MM),
    (3.75 * INCH_TO_MM, 0.95 * INCH_TO_MM),
]


def build_model() -> tuple[list[Box], list[Box], tuple[float, float, float]]:
    pocket_length = BOARD_LENGTH_MM + XY_CLEARANCE_MM
    pocket_width = BOARD_WIDTH_MM + XY_CLEARANCE_MM
    base_length = pocket_length + (2.0 * BASE_MARGIN_MM)
    base_width = pocket_width + (2.0 * BASE_MARGIN_MM)
    total_height = BASE_THICKNESS_MM + STANDOFF_HEIGHT_MM + BOARD_THICKNESS_MM + GUIDE_TOP_CLEARANCE_MM

    pocket_x0 = BASE_MARGIN_MM
    pocket_y0 = BASE_MARGIN_MM
    board_x0 = pocket_x0 + (XY_CLEARANCE_MM / 2.0)
    board_y0 = pocket_y0 + (XY_CLEARANCE_MM / 2.0)
    pocket_x1 = pocket_x0 + pocket_length
    pocket_y1 = pocket_y0 + pocket_width

    support_z0 = BASE_THICKNESS_MM
    support_z1 = BASE_THICKNESS_MM + STANDOFF_HEIGHT_MM
    guide_z1 = total_height

    positives: list[Box] = [
        Box(0.0, base_length, 0.0, base_width, 0.0, BASE_THICKNESS_MM),
    ]
    negatives: list[Box] = []

    for center_x_mm, center_y_mm in MOUNT_CENTERS_MM:
        center_x = board_x0 + center_x_mm
        center_y = board_y0 + center_y_mm
        half_standoff = STANDOFF_SIZE_MM / 2.0
        half_slot = MOUNT_SLOT_SIZE_MM / 2.0

        positives.append(
            Box(
                center_x - half_standoff,
                center_x + half_standoff,
                center_y - half_standoff,
                center_y + half_standoff,
                support_z0,
                support_z1,
            )
        )
        negatives.append(
            Box(
                center_x - half_slot,
                center_x + half_slot,
                center_y - half_slot,
                center_y + half_slot,
                0.0,
                support_z1,
            )
        )

    corner_specs = [
        (pocket_x0, pocket_y0, 1.0, 1.0),
        (pocket_x1, pocket_y0, -1.0, 1.0),
        (pocket_x0, pocket_y1, 1.0, -1.0),
        (pocket_x1, pocket_y1, -1.0, -1.0),
    ]

    for anchor_x, anchor_y, x_dir, y_dir in corner_specs:
        if x_dir > 0.0:
            wall_x0 = anchor_x - GUIDE_WALL_THICKNESS_MM
            wall_x1 = anchor_x
            span_x0 = anchor_x - GUIDE_WALL_THICKNESS_MM
            span_x1 = anchor_x + GUIDE_LENGTH_MM
        else:
            wall_x0 = anchor_x
            wall_x1 = anchor_x + GUIDE_WALL_THICKNESS_MM
            span_x0 = anchor_x - GUIDE_LENGTH_MM
            span_x1 = anchor_x + GUIDE_WALL_THICKNESS_MM

        if y_dir > 0.0:
            wall_y0 = anchor_y - GUIDE_WALL_THICKNESS_MM
            wall_y1 = anchor_y
            span_y0 = anchor_y - GUIDE_WALL_THICKNESS_MM
            span_y1 = anchor_y + GUIDE_LENGTH_MM
        else:
            wall_y0 = anchor_y
            wall_y1 = anchor_y + GUIDE_WALL_THICKNESS_MM
            span_y0 = anchor_y - GUIDE_LENGTH_MM
            span_y1 = anchor_y + GUIDE_WALL_THICKNESS_MM

        positives.append(Box(wall_x0, wall_x1, span_y0, span_y1, support_z0, guide_z1))
        positives.append(Box(span_x0, span_x1, wall_y0, wall_y1, support_z0, guide_z1))

    return positives, negatives, (base_length, base_width, total_height)


def write_stl(output_path: Path) -> None:
    positives, negatives, extents = build_model()
    facets = build_mesh(positives, negatives)
    lines = ["solid ek_tm4c129exl_holder_m3_v1"]
    lines.extend(facets)
    lines.append("endsolid ek_tm4c129exl_holder_m3_v1")
    output_path.write_text("\n".join(lines) + "\n", encoding="ascii")
    print(f"Wrote {output_path}")
    print(f"Triangle count: {len(facets)}")
    print(f"Nominal screw size: {CHOSEN_SCREW_SIZE}")
    print(f"Drawing hole callout mm: {mm(DRAWING_MOUNT_HOLE_DIAMETER_MM)}")
    print(
        "Bounding box mm: "
        f"{mm(extents[0])} x {mm(extents[1])} x {mm(extents[2])}"
    )


if __name__ == "__main__":
    write_stl(Path(__file__).with_suffix(".stl"))