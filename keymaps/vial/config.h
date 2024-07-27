/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

// unique keyboard ID
#define VIAL_KEYBOARD_UID {0x2D, 0x52, 0xE3, 0xEC, 0x25, 0x4F, 0x48, 0xFA}

// firmware lock (Esc + Enter)
#define VIAL_UNLOCK_COMBO_ROWS {0, 6}
#define VIAL_UNLOCK_COMBO_COLS {0, 0}

// set limits to lower EEPROM usage
#define DYNAMIC_KEYMAP_LAYER_COUNT 7
#define VIAL_TAP_DANCE_ENTRIES 12
#define NO_ACTION_MACRO

// configure tapdance
#define TAPPING_TERM 150
