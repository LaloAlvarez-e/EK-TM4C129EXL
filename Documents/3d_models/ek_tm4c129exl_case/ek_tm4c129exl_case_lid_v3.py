from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


TRAY_OUTER_LENGTH_MM = 131.26
TRAY_OUTER_WIDTH_MM = 62.68
TRAY_HEIGHT_MM = 18.0

TRAY_WALL_THICKNESS_MM = 2.4
BOARD_CLEARANCE_MM = 1.0
BOARD_X0_IN_TRAY_MM = TRAY_WALL_THICKNESS_MM + BOARD_CLEARANCE_MM
BOARD_Y0_IN_TRAY_MM = TRAY_WALL_THICKNESS_MM + BOARD_CLEARANCE_MM

LID_WALL_THICKNESS_MM = 2.4
LID_ROOF_THICKNESS_MM = 2.4
LID_TRAY_CLEARANCE_MM = 0.5
LID_HEIGHT_MM = 28.0
LID_SKIRT_DEPTH_MM = 9.0
LID_STOP_THICKNESS_MM = 1.2
LID_STOP_DEPTH_MM = 1.6

OUTER_LENGTH_MM = TRAY_OUTER_LENGTH_MM + (2.0 * (LID_WALL_THICKNESS_MM + LID_TRAY_CLEARANCE_MM))
OUTER_WIDTH_MM = TRAY_OUTER_WIDTH_MM + (2.0 * (LID_WALL_THICKNESS_MM + LID_TRAY_CLEARANCE_MM))

PORT_MARGIN_MM = 1.0
PORT_CUTOUT_Z0_MM = 0.0
PORT_CUTOUT_Z1_MM = LID_HEIGHT_MM - LID_ROOF_THICKNESS_MM + 0.1
SWITCH_MARGIN_MM = 0.8
HEADER_WINDOW_MARGIN_MM = 1.2
LED_WINDOW_MARGIN_MM = 1.4

SNAP_WINDOW_X_RANGES_TRAY_MM = [
    (17.0, 27.0),
    (70.0, 80.0),
]
SNAP_TAB_INSET_MM = 1.5
SNAP_TAB_PROTRUSION_MM = 1.8
SNAP_TAB_Z0_MM = 2.5
SNAP_TAB_Z1_MM = 6.5
SNAP_SLIT_WIDTH_MM = 1.0
SNAP_SLIT_Z1_MM = 8.5

LEFT_PORT_BBOXES_MM = [
    (-1.724, 36.805, 14.026, 54.635),
    (0.025, 18.825, 5.021, 28.825),
]

RIGHT_PORT_BBOXES_MM = [
    (119.635, 37.851, 124.46, 47.137),
    (116.988, 13.599, 123.596, 26.533),
]

SWITCH_BBOXES_MM = [
    (-0.076, 7.782, 7.645, 15.789),
    (8.433, 7.782, 16.154, 15.789),
    (13.624, 28.423, 21.631, 36.144),
    (1.686, 28.423, 9.693, 36.144),
]

HEADER_BBOXES_MM = [
    (35.431, 50.915, 61.089, 55.765),
    (35.431, 7.735, 61.089, 12.585),
    (98.931, 50.915, 124.589, 55.765),
    (98.931, 7.735, 124.589, 12.585),
]

LED_ROW_BBOX_MM = (23.63, 5.835, 32.25, 8.135)


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


def tray_to_lid_x(x_mm: float) -> float:
    return LID_WALL_THICKNESS_MM + LID_TRAY_CLEARANCE_MM + x_mm


def tray_to_lid_y(y_mm: float) -> float:
    return LID_WALL_THICKNESS_MM + LID_TRAY_CLEARANCE_MM + y_mm


def board_to_lid_x(x_mm: float) -> float:
    return tray_to_lid_x(BOARD_X0_IN_TRAY_MM + x_mm)


def board_to_lid_y(y_mm: float) -> float:
    return tray_to_lid_y(BOARD_Y0_IN_TRAY_MM + y_mm)


def build_model() -> tuple[list[Box], list[Box], tuple[float, float, float]]:
    roof_z0 = LID_HEIGHT_MM - LID_ROOF_THICKNESS_MM
    positives: list[Box] = [
        Box(0.0, OUTER_LENGTH_MM, 0.0, OUTER_WIDTH_MM, 0.0, LID_HEIGHT_MM),
        Box(LID_WALL_THICKNESS_MM, OUTER_LENGTH_MM - LID_WALL_THICKNESS_MM, LID_WALL_THICKNESS_MM, LID_WALL_THICKNESS_MM + LID_STOP_DEPTH_MM, LID_SKIRT_DEPTH_MM, LID_SKIRT_DEPTH_MM + LID_STOP_THICKNESS_MM),
        Box(LID_WALL_THICKNESS_MM, OUTER_LENGTH_MM - LID_WALL_THICKNESS_MM, OUTER_WIDTH_MM - LID_WALL_THICKNESS_MM - LID_STOP_DEPTH_MM, OUTER_WIDTH_MM - LID_WALL_THICKNESS_MM, LID_SKIRT_DEPTH_MM, LID_SKIRT_DEPTH_MM + LID_STOP_THICKNESS_MM),
    ]

    negatives: list[Box] = [
        Box(LID_WALL_THICKNESS_MM, OUTER_LENGTH_MM - LID_WALL_THICKNESS_MM, LID_WALL_THICKNESS_MM, OUTER_WIDTH_MM - LID_WALL_THICKNESS_MM, 0.0, roof_z0)
    ]

    inner_top_y = OUTER_WIDTH_MM - LID_WALL_THICKNESS_MM
    inner_bottom_y = LID_WALL_THICKNESS_MM

    for x0_tray, x1_tray in SNAP_WINDOW_X_RANGES_TRAY_MM:
        x0 = tray_to_lid_x(x0_tray + SNAP_TAB_INSET_MM)
        x1 = tray_to_lid_x(x1_tray - SNAP_TAB_INSET_MM)

        positives.append(Box(x0, x1, inner_bottom_y, inner_bottom_y + SNAP_TAB_PROTRUSION_MM, SNAP_TAB_Z0_MM, SNAP_TAB_Z1_MM))
        positives.append(Box(x0, x1, inner_top_y - SNAP_TAB_PROTRUSION_MM, inner_top_y, SNAP_TAB_Z0_MM, SNAP_TAB_Z1_MM))

        negatives.append(Box(x0 - SNAP_SLIT_WIDTH_MM, x0, -0.5, inner_bottom_y + SNAP_TAB_PROTRUSION_MM + 0.5, 0.0, SNAP_SLIT_Z1_MM))
        negatives.append(Box(x1, x1 + SNAP_SLIT_WIDTH_MM, -0.5, inner_bottom_y + SNAP_TAB_PROTRUSION_MM + 0.5, 0.0, SNAP_SLIT_Z1_MM))
        negatives.append(Box(x0 - SNAP_SLIT_WIDTH_MM, x0, inner_top_y - SNAP_TAB_PROTRUSION_MM - 0.5, OUTER_WIDTH_MM + 0.5, 0.0, SNAP_SLIT_Z1_MM))
        negatives.append(Box(x1, x1 + SNAP_SLIT_WIDTH_MM, inner_top_y - SNAP_TAB_PROTRUSION_MM - 0.5, OUTER_WIDTH_MM + 0.5, 0.0, SNAP_SLIT_Z1_MM))

    for x0_mm, y0_mm, x1_mm, y1_mm in LEFT_PORT_BBOXES_MM:
        negatives.append(Box(-1.0, board_to_lid_x(x1_mm + PORT_MARGIN_MM), board_to_lid_y(y0_mm - PORT_MARGIN_MM), board_to_lid_y(y1_mm + PORT_MARGIN_MM), PORT_CUTOUT_Z0_MM, PORT_CUTOUT_Z1_MM))

    for x0_mm, y0_mm, x1_mm, y1_mm in RIGHT_PORT_BBOXES_MM:
        negatives.append(Box(board_to_lid_x(x0_mm - PORT_MARGIN_MM), OUTER_LENGTH_MM + 1.0, board_to_lid_y(y0_mm - PORT_MARGIN_MM), board_to_lid_y(y1_mm + PORT_MARGIN_MM), PORT_CUTOUT_Z0_MM, PORT_CUTOUT_Z1_MM))

    for x0_mm, y0_mm, x1_mm, y1_mm in SWITCH_BBOXES_MM:
        negatives.append(Box(board_to_lid_x(x0_mm - SWITCH_MARGIN_MM), board_to_lid_x(x1_mm + SWITCH_MARGIN_MM), board_to_lid_y(y0_mm - SWITCH_MARGIN_MM), board_to_lid_y(y1_mm + SWITCH_MARGIN_MM), roof_z0 - 0.1, LID_HEIGHT_MM + 1.0))

    for x0_mm, y0_mm, x1_mm, y1_mm in HEADER_BBOXES_MM:
        negatives.append(Box(board_to_lid_x(x0_mm - HEADER_WINDOW_MARGIN_MM), board_to_lid_x(x1_mm + HEADER_WINDOW_MARGIN_MM), board_to_lid_y(y0_mm - HEADER_WINDOW_MARGIN_MM), board_to_lid_y(y1_mm + HEADER_WINDOW_MARGIN_MM), roof_z0 - 0.1, LID_HEIGHT_MM + 1.0))

    led_x0, led_y0, led_x1, led_y1 = LED_ROW_BBOX_MM
    negatives.append(Box(board_to_lid_x(led_x0 - LED_WINDOW_MARGIN_MM), board_to_lid_x(led_x1 + LED_WINDOW_MARGIN_MM), board_to_lid_y(led_y0 - LED_WINDOW_MARGIN_MM), board_to_lid_y(led_y1 + LED_WINDOW_MARGIN_MM), roof_z0 - 0.1, LID_HEIGHT_MM + 1.0))

    return positives, negatives, (OUTER_LENGTH_MM, OUTER_WIDTH_MM, LID_HEIGHT_MM)


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
    lines = ["solid ek_tm4c129exl_case_lid_v3"]
    lines.extend(facets)
    lines.append("endsolid ek_tm4c129exl_case_lid_v3")
    output_path.write_text("\n".join(lines) + "\n", encoding="ascii")
    print(f"Wrote {output_path}")
    print(f"Triangle count: {len(facets)}")
    print(f"Bounding box mm: {mm(extents[0])} x {mm(extents[1])} x {mm(extents[2])}")


if __name__ == "__main__":
    write_stl(Path(__file__).with_suffix(".stl"))