from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


INCH_TO_MM = 25.4

BOARD_LENGTH_MM = 4.9 * INCH_TO_MM
BOARD_WIDTH_MM = 2.2 * INCH_TO_MM
BOARD_THICKNESS_MM = 1.6

XY_CLEARANCE_MM = 0.6
BASE_MARGIN_MM = 8.0
BASE_THICKNESS_MM = 3.0
SUPPORT_HEIGHT_MM = 4.0
GUIDE_WALL_THICKNESS_MM = 2.4
GUIDE_LENGTH_MM = 11.0
SUPPORT_PAD_SIZE_MM = 8.0
SUPPORT_PAD_INSET_MM = 2.0
UNDERCUT_END_MARGIN_MM = 14.0
UNDERCUT_SIDE_MARGIN_MM = 7.0
GUIDE_TOP_CLEARANCE_MM = 1.0


@dataclass(frozen=True)
class Box:
    x0: float
    x1: float
    y0: float
    y1: float
    z0: float
    z1: float

    def contains(self, x: float, y: float, z: float) -> bool:
        return self.x0 <= x < self.x1 and self.y0 <= y < self.y1 and self.z0 <= z < self.z1


def mm(value: float) -> float:
    return round(value, 4)


def facet(normal: tuple[float, float, float], vertices: list[tuple[float, float, float]]) -> str:
    lines = [
        f"  facet normal {normal[0]:.6f} {normal[1]:.6f} {normal[2]:.6f}",
        "    outer loop",
    ]
    for vertex in vertices:
        lines.append(f"      vertex {vertex[0]:.6f} {vertex[1]:.6f} {vertex[2]:.6f}")
    lines.extend(["    endloop", "  endfacet"])
    return "\n".join(lines)


def quad_to_facets(
    normal: tuple[float, float, float],
    p0: tuple[float, float, float],
    p1: tuple[float, float, float],
    p2: tuple[float, float, float],
    p3: tuple[float, float, float],
) -> list[str]:
    return [facet(normal, [p0, p1, p2]), facet(normal, [p0, p2, p3])]


def build_model() -> tuple[list[Box], list[Box], tuple[float, float, float]]:
    pocket_length = BOARD_LENGTH_MM + XY_CLEARANCE_MM
    pocket_width = BOARD_WIDTH_MM + XY_CLEARANCE_MM
    base_length = pocket_length + (2.0 * BASE_MARGIN_MM)
    base_width = pocket_width + (2.0 * BASE_MARGIN_MM)
    total_height = BASE_THICKNESS_MM + SUPPORT_HEIGHT_MM + BOARD_THICKNESS_MM + GUIDE_TOP_CLEARANCE_MM

    pocket_x0 = BASE_MARGIN_MM
    pocket_y0 = BASE_MARGIN_MM
    board_x0 = pocket_x0 + (XY_CLEARANCE_MM / 2.0)
    board_y0 = pocket_y0 + (XY_CLEARANCE_MM / 2.0)
    pocket_x1 = pocket_x0 + pocket_length
    pocket_y1 = pocket_y0 + pocket_width
    board_x1 = board_x0 + BOARD_LENGTH_MM
    board_y1 = board_y0 + BOARD_WIDTH_MM

    positives: list[Box] = [
        Box(0.0, base_length, 0.0, base_width, 0.0, BASE_THICKNESS_MM),
    ]

    negatives: list[Box] = [
        Box(
            pocket_x0 + UNDERCUT_END_MARGIN_MM,
            pocket_x1 - UNDERCUT_END_MARGIN_MM,
            pocket_y0 + UNDERCUT_SIDE_MARGIN_MM,
            pocket_y1 - UNDERCUT_SIDE_MARGIN_MM,
            0.0,
            BASE_THICKNESS_MM,
        )
    ]

    support_z0 = BASE_THICKNESS_MM
    support_z1 = BASE_THICKNESS_MM + SUPPORT_HEIGHT_MM
    guide_z1 = total_height

    pad_left_x0 = board_x0 + SUPPORT_PAD_INSET_MM
    pad_left_x1 = pad_left_x0 + SUPPORT_PAD_SIZE_MM
    pad_right_x1 = board_x1 - SUPPORT_PAD_INSET_MM
    pad_right_x0 = pad_right_x1 - SUPPORT_PAD_SIZE_MM
    pad_bottom_y0 = board_y0 + SUPPORT_PAD_INSET_MM
    pad_bottom_y1 = pad_bottom_y0 + SUPPORT_PAD_SIZE_MM
    pad_top_y1 = board_y1 - SUPPORT_PAD_INSET_MM
    pad_top_y0 = pad_top_y1 - SUPPORT_PAD_SIZE_MM

    positives.extend(
        [
            Box(pad_left_x0, pad_left_x1, pad_bottom_y0, pad_bottom_y1, support_z0, support_z1),
            Box(pad_left_x0, pad_left_x1, pad_top_y0, pad_top_y1, support_z0, support_z1),
            Box(pad_right_x0, pad_right_x1, pad_bottom_y0, pad_bottom_y1, support_z0, support_z1),
            Box(pad_right_x0, pad_right_x1, pad_top_y0, pad_top_y1, support_z0, support_z1),
        ]
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


def build_mesh(positives: list[Box], negatives: list[Box]) -> list[str]:
    xs = sorted({box.x0 for box in positives + negatives} | {box.x1 for box in positives + negatives})
    ys = sorted({box.y0 for box in positives + negatives} | {box.y1 for box in positives + negatives})
    zs = sorted({box.z0 for box in positives + negatives} | {box.z1 for box in positives + negatives})

    def occupied(i: int, j: int, k: int) -> bool:
        cx = (xs[i] + xs[i + 1]) / 2.0
        cy = (ys[j] + ys[j + 1]) / 2.0
        cz = (zs[k] + zs[k + 1]) / 2.0
        inside_positive = any(box.contains(cx, cy, cz) for box in positives)
        inside_negative = any(box.contains(cx, cy, cz) for box in negatives)
        return inside_positive and not inside_negative

    occupancy = {
        (i, j, k): occupied(i, j, k)
        for i in range(len(xs) - 1)
        for j in range(len(ys) - 1)
        for k in range(len(zs) - 1)
    }

    facets: list[str] = []

    for (i, j, k), is_filled in occupancy.items():
        if not is_filled:
            continue

        x0, x1 = xs[i], xs[i + 1]
        y0, y1 = ys[j], ys[j + 1]
        z0, z1 = zs[k], zs[k + 1]

        if not occupancy.get((i - 1, j, k), False):
            facets.extend(
                quad_to_facets(
                    (-1.0, 0.0, 0.0),
                    (x0, y0, z0),
                    (x0, y1, z0),
                    (x0, y1, z1),
                    (x0, y0, z1),
                )
            )
        if not occupancy.get((i + 1, j, k), False):
            facets.extend(
                quad_to_facets(
                    (1.0, 0.0, 0.0),
                    (x1, y0, z0),
                    (x1, y0, z1),
                    (x1, y1, z1),
                    (x1, y1, z0),
                )
            )
        if not occupancy.get((i, j - 1, k), False):
            facets.extend(
                quad_to_facets(
                    (0.0, -1.0, 0.0),
                    (x0, y0, z0),
                    (x0, y0, z1),
                    (x1, y0, z1),
                    (x1, y0, z0),
                )
            )
        if not occupancy.get((i, j + 1, k), False):
            facets.extend(
                quad_to_facets(
                    (0.0, 1.0, 0.0),
                    (x0, y1, z0),
                    (x1, y1, z0),
                    (x1, y1, z1),
                    (x0, y1, z1),
                )
            )
        if not occupancy.get((i, j, k - 1), False):
            facets.extend(
                quad_to_facets(
                    (0.0, 0.0, -1.0),
                    (x0, y0, z0),
                    (x1, y0, z0),
                    (x1, y1, z0),
                    (x0, y1, z0),
                )
            )
        if not occupancy.get((i, j, k + 1), False):
            facets.extend(
                quad_to_facets(
                    (0.0, 0.0, 1.0),
                    (x0, y0, z1),
                    (x0, y1, z1),
                    (x1, y1, z1),
                    (x1, y0, z1),
                )
            )

    return facets


def write_stl(output_path: Path) -> None:
    positives, negatives, extents = build_model()
    facets = build_mesh(positives, negatives)
    lines = ["solid ek_tm4c129exl_holder"]
    lines.extend(facets)
    lines.append("endsolid ek_tm4c129exl_holder")
    output_path.write_text("\n".join(lines) + "\n", encoding="ascii")
    print(f"Wrote {output_path}")
    print(f"Triangle count: {len(facets) * 1}")
    print(
        "Bounding box mm: "
        f"{mm(extents[0])} x {mm(extents[1])} x {mm(extents[2])}"
    )


if __name__ == "__main__":
    write_stl(Path(__file__).with_suffix(".stl"))