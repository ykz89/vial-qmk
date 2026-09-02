// Copyright 2023 sporkus
// Copyright 2024 @ykz89
// SPDX-License-Identifier: GPL-2.0-or-later
//
// Thin adapter over the shared keymap in users/ykz89/. The le_chiffre has a
// center key on the top row and a knob; a wrapper splices the center key into
// the shared 3x10 core.
//
// Only 4 thumbs (2 left, 2 right), so the canonical third thumb of each hand
// is reached by chording that hand's two thumbs:
//   left  thumbs (SPC_NAV + TAB_FUN) -> ESC_MED
//   right thumbs (ENT_SYM + BSP_NUM) -> KC_DEL
// users/ykz89/ykz89_combos.c cannot provide these here -- Vial owns key_combos[]
// (quantum/vial.c) whenever COMBO_ENABLE is set, so they are defined separately.
//
// No pointing device on this board, so the pointer layer is absent entirely
// (see POINTING_DEVICE_ENABLE in users/ykz89/ykz89.h).

#include QMK_KEYBOARD_H
#include "ykz89.h"

// clang-format off
// Splice the top-row center key into the shared core, then 4 thumbs.
//   core (30) , CENTER (1) , thumbs (4)
#define LC_WRAP_IMPL(                                         \
    l00, l01, l02, l03, l04, r05, r06, r07, r08, r09,         \
    l10, l11, l12, l13, l14, r15, r16, r17, r18, r19,         \
    l20, l21, l22, l23, l24, r25, r26, r27, r28, r29,         \
    CENTER, t0, t1, t2, t3)                                   \
    l00, l01, l02, l03, l04, CENTER, r05, r06, r07, r08, r09, \
    l10, l11, l12, l13, l14,         r15, r16, r17, r18, r19, \
    l20, l21, l22, l23, l24,         r25, r26, r27, r28, r29, \
                            t0, t1,           t2, t3
#define LC_WRAP(...) LC_WRAP_IMPL(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_wrapper(LC_WRAP(
    HOME_ROW_MOD_GACS(LAYOUT_LAYER_BASE),
    RGB_TOG,   SPC_NAV, TAB_FUN, ENT_SYM, BSP_NUM)),
  [LAYER_FUNCTION]   = LAYOUT_wrapper(LC_WRAP(LAYOUT_LAYER_FUNCTION,   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX)),
  [LAYER_NAVIGATION] = LAYOUT_wrapper(LC_WRAP(LAYOUT_LAYER_NAVIGATION, _______, XXXXXXX, _______,  KC_ENT, KC_BSPC)),
  [LAYER_MEDIA]      = LAYOUT_wrapper(LC_WRAP(LAYOUT_LAYER_MEDIA,      _______, KC_MPLY, KC_MSTP, KC_MSTP, KC_MPLY)),
  [LAYER_NUMERAL]    = LAYOUT_wrapper(LC_WRAP(LAYOUT_LAYER_NUMERAL,    _______, KC_MINS,    KC_0, XXXXXXX, _______)),
  [LAYER_SYMBOLS]    = LAYOUT_wrapper(LC_WRAP(LAYOUT_LAYER_SYMBOLS,    _______,  KC_GRV, KC_UNDS, _______, XXXXXXX)),
};
// clang-format on

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [LAYER_BASE]       = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LAYER_FUNCTION]   = { ENCODER_CCW_CW(KC_LEFT, KC_RGHT) },
    [LAYER_NAVIGATION] = { ENCODER_CCW_CW(KC_PGDN, KC_PGUP) },
    [LAYER_MEDIA]      = { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [LAYER_NUMERAL]    = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [LAYER_SYMBOLS]    = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD) },
};
// clang-format on
#endif
