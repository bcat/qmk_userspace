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
