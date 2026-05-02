# EK-TM4C129EXL Holder

This folder contains printable holder variants for the EK-TM4C129EXL Crypto Connected LaunchPad.

Documented source facts from `Documents/launchpad.pdf` Figure A-1:

- The overall board outline is `4.9 in x 2.2 in`.
- The drawing includes a `0.125 in` mounting-hole callout, which is `3.175 mm`.

Chosen standard screw size:

- `M3`
- Reason: `3.175 mm` is effectively an M3 clearance-size hole, and M3 is the most common metric electronics fastener to source and print around.

Inference used for the first screw-ready version:

- The figure is clear enough to infer three mounting-hole centers, but not crisp enough to claim CAD-grade certainty.
- V1 uses inferred hole centers relative to the lower-left board corner at approximately:
	- `(1.15 in, 0.75 in)`
	- `(3.35 in, 2.05 in)`
	- `(3.75 in, 0.95 in)`
- Because those centers are inferred from the drawing, the V1 holder uses oversized square M3 clearance slots in the standoffs to absorb small placement error.

Variants:

- `ek_tm4c129exl_holder.stl`: original outline-based bench cradle.
- `ek_tm4c129exl_holder_m3_v1.stl`: first screw-ready version using M3 hardware and three integrated standoffs.

Recommended hardware for V1:

- `3 x M3 x 14 mm` or `M3 x 16 mm` pan-head screws
- `3 x M3 washers`
- `3 x M3 nuts`

Print notes:

- Print flat on the base.
- No support should be required.
- If your board has unusually long underside pins, increase the stand-off height constant in the corresponding generator and regenerate.

To regenerate the original cradle:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_holder/ek_tm4c129exl_holder.py"
```

To regenerate the M3 first version:

```powershell
py "d:/git/EK-TM4C129EXL/Documents/3d_models/ek_tm4c129exl_holder/ek_tm4c129exl_holder_m3_v1.py"
```