/* Copyright 2019 MechMerlin
 * Copyright 2023 @Ex3c4Def
 * Copyright 2023 @ben_roe (keycapsss.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/* Select hand configuration */
// #define MASTER_LEFT
// #define MASTER_RIGHT
#define EE_HANDS

#define OLED_FONT_H "keyboards/keycapsss/kimiko/rev1/keymaps/vial/glcdfont.c"


#ifdef RGB_MATRIX_ENABLE
/* RGB Matrix replaces the older RGBLIGHT backend.
   `g_led_config` (60 LEDs, 30 per half) lives in keyboards/keycapsss/kimiko/kimiko.c */
#   define RGB_MATRIX_SLEEP /* turn the LEDs off when the host goes to sleep */

/* Required by SOLID_REACTIVE_WIDE: reactive effects are compiled out entirely
   unless RGB_MATRIX_KEYPRESSES (or _KEYRELEASES) is defined. */
#   define RGB_MATRIX_KEYPRESSES

/* Effects are opt-in and each one costs flash. The Pro Micro / Elite-C image is
   nearly full, so this list is deliberately short - add more only if
   `make keycapsss/kimiko/rev1:vial` still reports free space. */
#   define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#   define ENABLE_RGB_MATRIX_MULTISPLASH

#   define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT
#endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

#define VIAL_KEYBOARD_UID {0x80, 0x9F, 0xA5, 0x3D, 0x0D, 0xCD, 0x43, 0xA4}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 9 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 4 }
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
