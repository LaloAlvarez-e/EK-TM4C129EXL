# EK-TM4C129EXL Case

This folder contains enclosure-style case variants for the EK-TM4C129EXL based on the EAGLE board design in `Documents/schematics/CCLP Design Package`.

Source facts extracted from `EK-TM4C129EXL REV A.brd`:

- Board outline on layer 20: `124.46 mm x 55.88 mm`
- Mounting holes:
  - `H4` at `(21.59, 16.51)` mm with `3.2 mm` hole
  - `H1` at `(95.25, 21.59)` mm with `3.2 mm` hole
  - `H6` at `(82.55, 52.07)` mm with `3.2 mm` hole
- Edge connector/package bounds used for wall cutouts:
  - `U14` RJ45 on the left edge
  - `U7` target USB Micro-AB on the left edge
  - `U22` debug USB Micro-B on the right edge
  - `U6` external debug header on the right edge

Design choice for V1 tray:

- This is an open-top tray case, not a closed-lid box.
- Reason: the design package gives accurate 2D mechanical and footprint data, but not trustworthy component-height data for a closed cover.
- The board mounts to three exact standoffs aligned to the real PCB holes.
- The tray has side walls and edge cutouts sized from the connector footprints.
- The M3 fasteners use bottom nut pockets in the tray so the board can be screwed down from the top.

Design choice for the closed-lid revision:

- The closed lid is intentionally conservative on vertical clearance.
- It uses a deep cap-style cover with a generous internal cavity so it can clear the known tall connectors without requiring a measured full 3D board model.
- The lid includes top access holes for `USR_SW1`, `USR_SW2`, `RESET`, and `WAKE`.
- The revised tray adds bottom openings under the board header footprints so the tray does not block the protruding header/pin regions.

Recommended hardware:

- `3 x M3 x 12 mm` pan-head screws
- `3 x M3 nuts`
- `3 x M3 washers` optional

Recommended hardware for the locking lid:

- `3 x M3 x 35 mm` pan-head screws
- `3 x M3 nuts`
- `3 x M3 washers` optional

Generated artifacts:

- `ek_tm4c129exl_case_tray_v1.stl`
- `ek_tm4c129exl_case_tray_v2.stl`
- `ek_tm4c129exl_case_tray_v3.stl`
- `ek_tm4c129exl_case_tray_v4.stl`
- `ek_tm4c129exl_case_lid_v1.stl`
- `ek_tm4c129exl_case_lid_v2.stl`
- `ek_tm4c129exl_case_lid_v3.stl`
- `ek_tm4c129exl_case_lid_v4.stl`

Why the previous lid showed material in the Ethernet and USB holes:

- `ek_tm4c129exl_case_lid_v1` only opened the side cutouts through the lower skirt band.
- That left a bottom lip and upper wall material above each connector opening, which can look like support or blocked geometry in Fusion 360.
- `ek_tm4c129exl_case_lid_v2` fixes that by extending the connector cutouts from the bottom edge of the lid up to the underside of the roof.
- `ek_tm4c129exl_case_lid_v2` also adds screw locking by reusing the board's three real mounting holes so the lid, PCB, and tray clamp together.

Snap-lock revision notes:

- `ek_tm4c129exl_case_tray_v3` adds snap-catch windows in the tray walls.
- `ek_tm4c129exl_case_lid_v3` replaces screw locking with snap tabs.
- `ek_tm4c129exl_case_lid_v3` also adds roof openings over the four BoosterPack header-row areas so 180-degree header pins remain exposed.
- `ek_tm4c129exl_case_lid_v3` adds a roof window over the four user LEDs so they remain visible.

External mounting revision notes:

- `ek_tm4c129exl_case_tray_v4` keeps the tray-v3 snap geometry and header bottom openings.
- `ek_tm4c129exl_case_tray_v4` adds external side mounting supports with screw holes so the enclosure can be fastened to another surface.
- Use `ek_tm4c129exl_case_tray_v4` together with `ek_tm4c129exl_case_lid_v3`.

180-degree header side-clearance revision notes:

- `ek_tm4c129exl_case_lid_v4` keeps the tray/lid snap-lock geometry from lid v3.
- `ek_tm4c129exl_case_lid_v4` keeps the roof openings over the BoosterPack header-row regions and the LED window.
- `ek_tm4c129exl_case_lid_v4` also opens the long side walls at those header-row regions so right-angle 180-degree header pins can exit through the side.
- Use `ek_tm4c129exl_case_lid_v4` with `ek_tm4c129exl_case_tray_v4` when side header clearance is needed.

To regenerate the original tray:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_case/ek_tm4c129exl_case_tray_v1.py"
```

To regenerate the revised tray with header openings:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_case/ek_tm4c129exl_case_tray_v2.py"
```

To regenerate the snap-lock tray:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_case/ek_tm4c129exl_case_tray_v3.py"
```

To regenerate the snap-lock tray with external mounting supports:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_case/ek_tm4c129exl_case_tray_v4.py"
```

To regenerate the closed lid:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_case/ek_tm4c129exl_case_lid_v1.py"
```

To regenerate the locking closed lid:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_case/ek_tm4c129exl_case_lid_v2.py"
```

To regenerate the snap-lock closed lid with header and LED windows:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_case/ek_tm4c129exl_case_lid_v3.py"
```

To regenerate the snap-lock closed lid with side clearance for right-angle headers:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_case/ek_tm4c129exl_case_lid_v4.py"
```

Remaining limitation:

- The lid height is a conservative first estimate, not a measured component-envelope model.
- If you later want a tighter or lower-profile lid, the next step is still measured tallest-component heights or a board STEP/3D source.