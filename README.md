# bcat's QMK userspace

This repository holds the code and config for my mechanical keyboards using [QMK
Firmware](https://qmk.fm/). These files can be used as an [external
userspace](https://github.com/qmk/qmk_userspace) together with the main
[firmware repo](https://github.com/qmk/qmk_firmware). See the [QMK
documentation](https://docs.qmk.fm/#/newbs_external_userspace) for more details.

I use community layouts wherever possible, only writing keyboard-specific
keymaps for boards without standard layout support. I derive my keymaps from two
canonical ones (preferred for typing and gaming, respectively).

## Canonical keymaps

* [3x6+3 split layout](layouts/split_3x6_3/bcat)
  * Used on: Crkbd
  * Columnar-staggered split ergo layout, preferred for typing

* [60% ANSI Tsangan layout with split Backspace and Right
  Shift](layouts/60_ansi_tsangan_split_bs_rshift/bcat)
  * Used on: ai03 Polaris, CannonKeys AN-C, CannonKeys Instant60, DZ60
  * Row-staggered layout, preferred for gaming

## Additional keymaps

### Ergo

* [Lily58 layout](keyboards/lily58/keymaps/bcat)
* [Unicorne layout](keyboards/yanghu/unicorne/keymaps/bcat)

### Ortho

* [Eco layout](keyboards/eco/keymaps/bcat)

### Traditional

* [60% ANSI layout with split Backspace and Right
  Shift](layouts/60_ansi_split_bs_rshift/bcat)
  * Used on: DZ60

* [65% ANSI layout with blocker and split
  Backspace](layouts/65_ansi_blocker_split_bs/bcat)
  * Used on: KBDfans KBD67 hotswap

* [Keebio Quefrency 65% layout](keyboards/keebio/quefrency/keymaps/bcat)

### Macropads

* [9-Key layout](keyboards/9key/keymaps/bcat)

* [Keebio BDN9 layout](keyboards/keebio/bdn9/keymaps/bcat)

## License

QMK Firmware is licensed under the
[GPL-2.0-or-later](https://spdx.org/licenses/GPL-2.0-or-later.html) license, and
any code in this repo originating from QMK is licensed under these terms.

To promote reuse in projects with more permissive licenses, anything in this
repo authored by me (e.g., the `keyboards`, `layouts`, and `users` directories)
is licensed under the [ISC](https://spdx.org/licenses/ISC.html) license instead,
with the following exceptions:

* `users/bcat/bcat_oled_pet_isda.c` incorporates artwork licensed under the
  GPL-2.0-or-later.
* `users/bcat/bcat_oled_pet_luna.c` incorporates code and artwork licensed under
  the GPL-2.0-or-later.

Consult the
[`SDPX-License-Identifier`](https://spdx.dev/learn/handling-license-info/)
comments to determine precisely what license applies to any particular file.
