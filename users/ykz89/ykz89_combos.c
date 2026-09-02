// Copyright 2024 @ykz89
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Combo definitions, kept separate from ykz89.c so QMK's keymap introspection
// can see `key_combos` (it #includes this via INTROSPECTION_KEYMAP_C; see
// users/ykz89/rules.mk). This file is NOT added to SRC -- it is only ever
// #included into the introspection translation unit, so the array is defined
// exactly once.
//
// Synthesize the "third" thumb key on boards that don't have one. Boards with
// only two thumbs per hand opt in via config.h:
//   #define COMBO_ESC_MED   // left  thumbs -> ESC_MED (media layer)
//   #define COMBO_DEL       // right thumbs -> Delete
// and enable COMBO_ENABLE in their rules.mk.

#include QMK_KEYBOARD_H
#include "ykz89.h"

#ifdef COMBO_ENABLE
enum ykz89_combos {
#    ifdef COMBO_ESC_MED
    CMB_ESC_MED,
#    endif
#    ifdef COMBO_DEL
    CMB_DEL,
#    endif
    COMBO_LENGTH // last
};

#    ifdef COMBO_ESC_MED
const uint16_t PROGMEM combo_esc_med[] = {SPC_NAV, TAB_FUN, COMBO_END};
#    endif
#    ifdef COMBO_DEL
const uint16_t PROGMEM combo_del[] = {ENT_SYM, BSP_NUM, COMBO_END};
#    endif

combo_t key_combos[] = {
#    ifdef COMBO_ESC_MED
    [CMB_ESC_MED] = COMBO(combo_esc_med, ESC_MED),
#    endif
#    ifdef COMBO_DEL
    [CMB_DEL] = COMBO(combo_del, KC_DEL),
#    endif
};
#endif // COMBO_ENABLE
