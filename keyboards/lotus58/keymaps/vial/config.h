/*
Copyright 2022 AgiosAndreas

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// clang-format off

#pragma once

#define VIAL_KEYBOARD_UID {0xAE, 0x5E, 0xC7, 0x5F, 0x6A, 0xAF, 0xB3, 0x50}

// #define MASTER_RIGHT

#ifdef MASTER_RIGHT
    #define VIAL_UNLOCK_COMBO_ROWS { 6, 8 }
    #define VIAL_UNLOCK_COMBO_COLS { 5, 5 }
#else
    #define VIAL_UNLOCK_COMBO_ROWS { 1, 3 }
    #define VIAL_UNLOCK_COMBO_COLS { 5, 5 }
#endif


#ifdef ENCODER_ENABLE
    #define ENCODER_DIRECTION_FLIP
    #undef ENCODER_RESOLUTION
    #define ENCODER_RESOLUTION 2
#endif

#ifdef VIAL_ENCODERS_ENABLE
    #define VIAL_ENCODER_DEFAULT { KC_VOLD, KC_VOLU, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
#endif

#ifdef RGBLIGHT_ENABLE
    #undef RGBLIGHT_ANIMATIONS
    #undef RGBLIGHT_EFFECT_BREATHING
    #undef RGBLIGHT_EFFECT_RAINBOW_MOOD
    #undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #undef RGBLIGHT_EFFECT_SNAKE
    #undef RGBLIGHT_EFFECT_KNIGHT
    #undef RGBLIGHT_EFFECT_CHRISTMAS
    #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
    #undef RGBLIGHT_EFFECT_ALTERNATING
    #undef RGBLIGHT_EFFECT_TWINKLE

    #undef RGBLED_NUM
    #define RGBLED_NUM 12
    #define RGBLED_SPLIT { 6, 6 }
    #define RGB_DI_PIN D3

    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_DEFAULT_VAL 125
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL
#endif
