// Copyright 2023 sporkus
// Copyright 2024 @ykz89
/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0xC9, 0xD4, 0x38, 0x79, 0x25, 0x61, 0x35, 0x00}

/* Hold the outer two keys of the top row to unlock */
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 9 }

/* Vial's dynamic combo engine defines key_combos[], so users/ykz89's static
 * combo table is left out of this build (see users/ykz89/rules.mk). Recreate
 * the two "third thumb" combos in Vial's combo editor:
 *   SPC_NAV + TAB_FUN -> LT(LAYER_MEDIA, KC_ESC)
 *   ENT_SYM + BSP_NUM -> KC_DEL
 * 50ms (the default) is tight for a two-thumb roll. */
#define VIAL_COMBO_ENTRIES 64
#define COMBO_TERM 60

/* CHORDAL_HOLD and FLOW_TAP_TERM are already supplied on the command line by
 * builddefs/build_vial.mk when QMK_SETTINGS is on (the default for Vial), so
 * they must not be redefined here. Chordal Hold reads the handedness table
 * generated from the "hand" annotations in keyboard.json -- LAYOUT is listed
 * first there so the table covers the centre key. */

#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define TAPPING_TERM 200
