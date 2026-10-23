---
tags: [gotcha, engineering]
---

# Gotchas

## Layout space exhaustion

- On 2026-10-23, Lan Mouse's 700px minimum height exhausted a tiled
  column. Unsigned subtraction in `tile()` produced a 2,147,483,628px
  Alacritty window; scaling its border overflowed and triggered wlroots'
  rectangle-size assertion, aborting dwl.
- Keep tile/deck dimensions and remaining-space arithmetic signed; clamp
  calculated slot heights to at least 1 before `resize()`. Client minimums
  may still require overlapping windows, but must not wrap to huge sizes.
- Verified with a normal build and an isolated UBSan harness exercising
  the actual tile/deck functions with oversized minimums and tiny outputs.
  Live compositor verification is still needed after installing/restarting.

Related: [[Home]].
