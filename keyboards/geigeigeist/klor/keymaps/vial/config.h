/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0xFC, 0x26, 0xF3, 0xFD, 0xCF, 0x8B, 0x89, 0xF6}

#define VIAL_UNLOCK_COMBO_ROWS {2, 6}
#define VIAL_UNLOCK_COMBO_COLS {5, 5}

#define DYNAMIC_KEYMAP_MACRO_COUNT 32
#define VIAL_COMBO_ENTRIES 32               // number of combos used, each entry take 10 byte in EEPROM
#define VIAL_TAP_DANCE_ENTRIES 48           // number of tap dances used, each entry take 10 byte in EEPROM
#define VIAL_KEY_OVERRIDE_ENTRIES 8         // number of key override used, each entry take 10 byte in EEPROM
