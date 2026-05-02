from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


BOARD_LENGTH_MM = 124.46
BOARD_WIDTH_MM = 55.88
BOARD_CLEARANCE_MM = 1.0

WALL_THICKNESS_MM = 2.4
BASE_THICKNESS_MM = 3.0
CASE_HEIGHT_MM = 18.0
STANDOFF_HEIGHT_MM = 8.0
STANDOFF_SIZE_MM = 9.0

M3_CLEARANCE_SQUARE_MM = 3.4
M3_NUT_POCKET_MM = 6.2
M3_NUT_POCKET_DEPTH_MM = 2.5

PORT_MARGIN_MM = 1.0
BOTTOM_HEADER_MARGIN_MM = 0.8
PORT_CUTOUT_Z0_MM = BASE_THICKNESS_MM + STANDOFF_HEIGHT_MM - 1.0

SNAP_WINDOW_X_RANGES_MM = [
    (17.0, 27.0),
    (70.0, 80.0),
]
SNAP_WINDOW_Z0_MM = 11.5
SNAP_WINDOW_Z1_MM = 15.5

MOUNT_SUPPORT_EXTENSION_MM = 12.0
MOUNT_SUPPORT_END_MARGIN_MM = 12.0
MOUNT_SUPPORT_HOLE_MM = 4.2
MOUNT_SUPPORT_BOSS_SIZE_MM = 10.0
MOUNT_SUPPORT_BOSS_HEIGHT_MM = 6.0
MOUNT_SUPPORT_HOLE_X_OFFSETS_MM = [20.0, 20.0]

BOARD_X0_MM = WALL_THICKNESS_MM + BOARD_CLEARANCE_MM
BOARD_Y0_MM = WALL_THICKNESS_MM + BOARD_CLEARANCE_MM
OUTER_LENGTH_MM = BOARD_LENGTH_MM + (2.0 * (WALL_THICKNESS_MM + BOARD_CLEARANCE_MM))
OUTER_WIDTH_MM = BOARD_WIDTH_MM + (2.0 * (WALL_THICKNESS_MM + BOARD_CLEARANCE_MM))

MOUNT_HOLES_MM = [
    (21.59, 16.51),
    (95.25, 21.59),
    (82.55, 52.07),
]

LEFT_PORT_BBOXES_MM = [
    (-1.724, 36.805, 14.026, 54.635),
    (0.025, 18.825, 5.021, 28.825),
]

RIGHT_PORT_BBOXES_MM = [
    (119.635, 37.851, 124.46, 47.137),
    (116.988, 13.599, 123.596, 26.533),
]

BOTTOM_HEADER_BBOXES_MM = [
    (83.935, 12.571, 88.785, 30.609),
    (35.431, 50.915, 61.089, 55.765),
    (35.431, 7.735, 61.089, 12.585),
    (98.931, 50.915, 124.589, 55.765),
    (98.931, 7.735, 124.589, 12.585),
    (-0.129, 0.115, 124.589, 4.965),
    (116.988, 13.599, 123.596, 26.533),
]


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


def quad_to_facets(normal, p0, p1, p2, p3):
    return [facet(normal, [p0, p1, p2]), facet(normal, [p0, p2, p3])]


def board_to_case_x(x_mm: float) -> float:
    return BOARD_X0_MM + x_mm


def board_to_case_y(y_mm: float) -> float:
    return BOARD_Y0_MM + y_mm


def build_model() -> tuple[list[Box], list[Box], tuple[float, float, float]]:
    positives: list[Box] = [
        Box(0.0, OUTER_LENGTH_MM, 0.0, OUTER_WIDTH_MM, 0.0, BASE_THICKNESS_MM),
        Box(0.0, WALL_THICKNESS_MM, 0.0, OUTER_WIDTH_MM, BASE_THICKNESS_MM, CASE_HEIGHT_MM),
        Box(OUTER_LENGTH_MM - WALL_THICKNESS_MM, OUTER_LENGTH_MM, 0.0, OUTER_WIDTH_MM, BASE_THICKNESS_MM, CASE_HEIGHT_MM),
        Box(0.0, OUTER_LENGTH_MM, 0.0, WALL_THICKNESS_MM, BASE_THICKNESS_MM, CASE_HEIGHT_MM),
        Box(0.0, OUTER_LENGTH_MM, OUTER_WIDTH_MM - WALL_THICKNESS_MM, OUTER_WIDTH_MM, BASE_THICKNESS_MM, CASE_HEIGHT_MM),
    ]

    negatives: list[Box] = []
    standoff_z0 = BASE_THICKNESS_MM
    standoff_z1 = BASE_THICKNESS_MM + STANDOFF_HEIGHT_MM
    half_standoff = STANDOFF_SIZE_MM / 2.0
    half_clearance = M3_CLEARANCE_SQUARE_MM / 2.0
    half_nut = M3_NUT_POCKET_MM / 2.0

    for hole_x_mm, hole_y_mm in MOUNT_HOLES_MM:
        center_x = board_to_case_x(hole_x_mm)
        center_y = board_to_case_y(hole_y_mm)
        positives.append(Box(center_x - half_standoff, center_x + half_standoff, center_y - half_standoff, center_y + half_standoff, standoff_z0, standoff_z1))
        negatives.append(Box(center_x - half_clearance, center_x + half_clearance, center_y - half_clearance, center_y + half_clearance, M3_NUT_POCKET_DEPTH_MM, standoff_z1))
        negatives.append(Box(center_x - half_nut, center_x + half_nut, center_y - half_nut, center_y + half_nut, 0.0, M3_NUT_POCKET_DEPTH_MM))

    for x0_mm, y0_mm, x1_mm, y1_mm in LEFT_PORT_BBOXES_MM:
        negatives.append(Box(-1.0, board_to_case_x(x1_mm + PORT_MARGIN_MM), board_to_case_y(y0_mm - PORT_MARGIN_MM), board_to_case_y(y1_mm + PORT_MARGIN_MM), PORT_CUTOUT_Z0_MM, CASE_HEIGHT_MM + 1.0))
    for x0_mm, y0_mm, x1_mm, y1_mm in RIGHT_PORT_BBOXES_MM:
        negatives.append(Box(board_to_case_x(x0_mm - PORT_MARGIN_MM), OUTER_LENGTH_MM + 1.0, board_to_case_y(y0_mm - PORT_MARGIN_MM), board_to_case_y(y1_mm + PORT_MARGIN_MM), PORT_CUTOUT_Z0_MM, CASE_HEIGHT_MM + 1.0))
    for x0_mm, y0_mm, x1_mm, y1_mm in BOTTOM_HEADER_BBOXES_MM:
        negatives.append(Box(board_to_case_x(x0_mm - BOTTOM_HEADER_MARGIN_MM), board_to_case_x(x1_mm + BOTTOM_HEADER_MARGIN_MM), board_to_case_y(y0_mm - BOTTOM_HEADER_MARGIN_MM), board_to_case_y(y1_mm + BOTTOM_HEADER_MARGIN_MM), 0.0, BASE_THICKNESS_MM + 0.1))

    for x0_mm, x1_mm in SNAP_WINDOW_X_RANGES_MM:
        negatives.append(Box(x0_mm, x1_mm, -0.5, WALL_THICKNESS_MM + 0.5, SNAP_WINDOW_Z0_MM, SNAP_WINDOW_Z1_MM))
        negatives.append(Box(x0_mm, x1_mm, OUTER_WIDTH_MM - WALL_THICKNESS_MM - 0.5, OUTER_WIDTH_MM + 0.5, SNAP_WINDOW_Z0_MM, SNAP_WINDOW_Z1_MM))

    support_x0 = MOUNT_SUPPORT_END_MARGIN_MM
    support_x1 = OUTER_LENGTH_MM - MOUNT_SUPPORT_END_MARGIN_MM
    positives.append(Box(support_x0, support_x1, -MOUNT_SUPPORT_EXTENSION_MM, 0.0, 0.0, BASE_THICKNESS_MM))
    positives.append(Box(support_x0, support_x1, OUTER_WIDTH_MM, OUTER_WIDTH_MM + MOUNT_SUPPORT_EXTENSION_MM, 0.0, BASE_THICKNESS_MM))

    hole_positions = [MOUNT_SUPPORT_HOLE_X_OFFSETS_MM[0], OUTER_LENGTH_MM - MOUNT_SUPPORT_HOLE_X_OFFSETS_MM[1]]
    half_boss = MOUNT_SUPPORT_BOSS_SIZE_MM / 2.0
    half_mount_hole = MOUNT_SUPPORT_HOLE_MM / 2.0
    bottom_support_center_y = -MOUNT_SUPPORT_EXTENSION_MM / 2.0
    top_support_center_y = OUTER_WIDTH_MM + (MOUNT_SUPPORT_EXTENSION_MM / 2.0)

    for center_x in hole_positions:
        positives.append(Box(center_x - half_boss, center_x + half_boss, bottom_support_center_y - half_boss, bottom_support_center_y + half_boss, 0.0, MOUNT_SUPPORT_BOSS_HEIGHT_MM))
        positives.append(Box(center_x - half_boss, center_x + half_boss, top_support_center_y - half_boss, top_support_center_y + half_boss, 0.0, MOUNT_SUPPORT_BOSS_HEIGHT_MM))
        negatives.append(Box(center_x - half_mount_hole, center_x + half_mount_hole, bottom_support_center_y - half_mount_hole, bottom_support_center_y + half_mount_hole, 0.0, MOUNT_SUPPORT_BOSS_HEIGHT_MM + 0.1))
        negatives.append(Box(center_x - half_mount_hole, center_x + half_mount_hole, top_support_center_y - half_mount_hole, top_support_center_y + half_mount_hole, 0.0, MOUNT_SUPPORT_BOSS_HEIGHT_MM + 0.1))

    return positives, negatives, (OUTER_LENGTH_MM, OUTER_WIDTH_MM + (2.0 * MOUNT_SUPPORT_EXTENSION_MM), CASE_HEIGHT_MM)


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

    occupancy = {(i, j, k): occupied(i, j, k) for i in range(len(xs) - 1) for j in range(len(ys) - 1) for k in range(len(zs) - 1)}
    facets: list[str] = []

    for (i, j, k), is_filled in occupancy.items():
        if not is_filled:
            continue
        x0, x1 = xs[i], xs[i + 1]
        y0, y1 = ys[j], ys[j + 1]
        z0, z1 = zs[k], zs[k + 1]
        if not occupancy.get((i - 1, j, k), False):
            facets.extend(quad_to_facets((-1.0, 0.0, 0.0), (x0, y0, z0), (x0, y1, z0), (x0, y1, z1), (x0, y0, z1)))
        if not occupancy.get((i + 1, j, k), False):
            facets.extend(quad_to_facets((1.0, 0.0, 0.0), (x1, y0, z0), (x1, y0, z1), (x1, y1, z1), (x1, y1, z0)))
        if not occupancy.get((i, j - 1, k), False):
            facets.extend(quad_to_facets((0.0, -1.0, 0.0), (x0, y0, z0), (x0, y0, z1), (x1, y0, z1), (x1, y0, z0)))
        if not occupancy.get((i, j + 1, k), False):
            facets.extend(quad_to_facets((0.0, 1.0, 0.0), (x0, y1, z0), (x1, y1, z0), (x1, y1, z1), (x0, y1, z1)))
        if not occupancy.get((i, j, k - 1), False):
            facets.extend(quad_to_facets((0.0, 0.0, -1.0), (x0, y0, z0), (x1, y0, z0), (x1, y1, z0), (x0, y1, z0)))
        if not occupancy.get((i, j, k + 1), False):
            facets.extend(quad_to_facets((0.0, 0.0, 1.0), (x0, y0, z1), (x0, y1, z1), (x1, y1, z1), (x1, y0, z1)))
    return facets


def write_stl(output_path: Path) -> None:
    positives, negatives, extents = build_model()
    facets = build_mesh(positives, negatives)
    lines = ["solid ek_tm4c129exl_case_tray_v4"]
    lines.extend(facets)
    lines.append("endsolid ek_tm4c129exl_case_tray_v4")
    output_path.write_text("\n".join(lines) + "\n", encoding="ascii")
    print(f"Wrote {output_path}")
    print(f"Triangle count: {len(facets)}")
    print(f"Bounding box mm: {mm(extents[0])} x {mm(extents[1])} x {mm(extents[2])}")


if __name__ == "__main__":
    write_stl(Path(__file__).with_suffix(".stl"))