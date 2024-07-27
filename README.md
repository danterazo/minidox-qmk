# Dante's QMK Firmware for Dactyl Minidox
## Repository Directory
- [Compiled Firmware](./compiled/)
- [QMK Source Code](./keymaps/)
  - [Via](./keymaps/via/)
  - [Vial](./keymaps/vial/)
- [Vial Layouts](./layouts/)
- [Global Minidox Config](./config.h)
- [Global Minidox Keymap](./dactyl_minidox.c)
- [QMK Info JSON](./info.json)

## Background
I bought a used, partially-built Dactyl Minidox on eBay, but it arrived with missing maps and unusable keybinds. It also lacked [Via](https://usevia.app/) support. Long story short, I had to DIY the firmware for this thing and switched to [Vial](https://get.vial.today/). With only 36 keys, custom firmware, layers, and creativity were a must!

This repo contains compiled firmware for both Via and Vial, custom keyboard definitions, layout definitions, and other QMK-related files.

**DISCLAIMER:** It's entirely possible that my board was wired wrong, and that my firmware files / binaries won't work for your Minidox.

TODO: Add pictures of board.

### Part 0: Some Assembly Required
The board was cheap and didn't require DIY. Everything was pre-solded — it just needed switches, keycaps, a TRS cable, and a USB-A to A cable.

### Part 1: Via
After assembling the board, I flashed Via's official Minidox firmware (link [below](#compiled-firmware)). The keyboard was incorrectly displayed as a `Dactyl Manuform (5x6-5)` in Via. The matrix was incorrect, and keybinds weren't properly assigned.

To solve this, I wrote my own [Via V3 keyboard definition](./keymaps/via/definition.json). This is heavily inspired by other `3x5_3` layouts, but it inverts the column sequence on the right half of the board. For example, the top-left key on my board (`[4,4]`) should have been mapped to `[4,0]`. Even though the layout was seemingly correct in Via, tapping this key (`Y` on the standard QWERTY base layer) yielded `P` instead. My keyboard definition fixes that and some quirks with the thumb cluster mapping.

### Part 2: Vial
It soon became apparent that 4 layers weren't enough for a 36-key board. The plan was to flash custom, Via-compatible firmware with support for more layers. But then Vial crossed my radar — the [Tap Dance](https://docs.qmk.fm/features/tap_dance) concept stood out to me in particular. If I had to flash custom firmware anyway, why not use Vial?

Vial has its own unique set of requirements. Those, plus new features, meant larger firmware and a harder time meeting the Arduino Pro Micro's EEPROM constraints. That kicked off almost 4 hours of tuning and re-compiling firmware. The end result is just shy (22 bytes!) of the maximum supported file size. To make it happen, I disabled certain features (see [info.json](./info.json) and [rules.mk](./keymaps/vial/rules.mk)), enabled [Link Time Optimization (LTO)](https://gcc.gnu.org/wiki/LinkTimeOptimization), and more.

The compiled Vial-compatible firmware has the following features:
- 7 layers
- 12 tap-dance slots
- 16 macro slots
- 8 combo slots
- 8 key override slots
- ...and more!

An incomplete version of my layout is available at [layouts/minidox.vil](layouts/minidox.vil). I am still evaluating, tweaking, and tuning it, but it could serve as a base or inspiration for your own Minidox. Note that this file is only compatible with Vial.

## Compiled Firmware
Compiled, Vial-compatible firmware is available in [compiled/](./compiled/). For Via's official Minidox firmware, see [their website](https://www.caniusevia.com/docs/download_firmware) and search for `handwired_dactyl_minidox_via.hex`.

## Generic Keyboard Information
![DactylMinidox](https://i.imgur.com/PqjgeRfh.jpg)

A 36 key (3x5+3), split bodied keyboard derived from the [Dactyl ManuForm](/keyboards/handwired/dactyl_manuform/).

* Keyboard Maintainer: [Dan Ford](https://github.com/dlford)
* Hardware Supported: Pro Micro controller, or clone of
* Hardware Availability: [Build Guide](https://www.dlford.io/keyboard-build-guide-per-key-rgb-leds/)

Make example for this keyboard (after setting up your build environment):

    make handwired/dactyl_minidox:default

Flashing example for this keyboard:

    make handwired/dactyl_minidox:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
