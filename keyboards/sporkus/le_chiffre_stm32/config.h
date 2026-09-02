// Copyright 2023 sporkus
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define WS2812_DI_PIN A15

/* The bitbang driver's ns->loop conversion rounds up, and on this APM32F072 a
 * loop iteration is ~229ns rather than the 312ns it assumes. The default
 * WS2812_T0H of 350 compiles to two iterations (~458ns), long enough that the
 * SK6812s sample every 0 bit as a 1 and latch full white. One iteration
 * (~229ns) sits in the middle of the 0-bit window. T1H is unchanged. */
#define WS2812_T0H 300
#define RGB_MATRIX_LED_COUNT 11

// Comment these out if you don't want front indicators leds
#define RGB_MODS_INDICATOR_ENABLE
#define RGB_LAYER_INDICATOR_ENABLE

#define RGB_FRONT_BRIGHTNESS_SCALE 3  // Front indicator brightness scaling (0-10)
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES
#define RGB_TRIGGER_ON_KEYDOWN
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#define RGB_MATRIX_HUE_STEP 8
#define RGB_MATRIX_SAT_STEP 8
#define RGB_MATRIX_VAL_STEP 8
#define RGB_MATRIX_SPD_STEP 16
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_HUE_WAVE
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 255
#define RGB_MATRIX_DEFAULT_VAL 100
#define RGB_MATRIX_DEFAULT_SPD 32

#define ENABLE_RGB_MATRIX_BREATHING
#define ENABLE_RGB_MATRIX_BAND_SAT
#define ENABLE_RGB_MATRIX_BAND_VAL
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN

#define ENABLE_RGB_MATRIX_HUE_BREATHING
#define ENABLE_RGB_MATRIX_HUE_WAVE
#define ENABLE_RGB_MATRIX_PIXEL_FLOW
#define ENABLE_RGB_MATRIX_PIXEL_RAIN
#define ENABLE_RGB_MATRIX_STARLIGHT
#define ENABLE_RGB_MATRIX_STARLIGHT_SMOOTH
#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
#define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
#define ENABLE_RGB_MATRIX_RIVERFLOW

#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
