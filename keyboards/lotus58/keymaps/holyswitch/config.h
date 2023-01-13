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

#undef TAPPING_TERM
#define TAPPING_TERM 150

#ifdef ENCODER_ENABLE
    #define ENCODER_DIRECTION_FLIP
    #undef ENCODER_RESOLUTION
    #define ENCODER_RESOLUTION 4
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

    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL

    #ifndef ENCODER_ENABLE
    #   define RGBLIGHT_EFFECT_BREATHING
    #   define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #   define RGBLIGHT_EFFECT_SNAKE
    #   define RGBLIGHT_EFFECT_KNIGHT
    #   define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #   define RGBLIGHT_EFFECT_ALTERNATING
    #endif

    #undef RGBLED_NUM
    #ifdef RGBLIGHT_MODE_UNDERGLOW
    #   define RGBLED_NUM 6*2
    #endif
    #ifdef RGBLIGHT_MODE_BACKLIGHT
    #   define RGBLED_NUM 29*2
    #endif
    #ifdef RGBLIGHT_MODE_FULL
    #   define RGBLED_NUM 35*2
    #endif

    #define RGBLED_SPLIT { RGBLED_NUM/2, RGBLED_NUM/2 }

    #define RGBLIGHT_LIMIT_VAL 125
    #define RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL + 1
#endif


#define IGNORE_MOD_TAP_INTERRUPT  
#define PERMISSIVE_HOLD  
#define TAPPING_FORCE_HOLD  

#define MOUSEKEY_DELAY 16
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 8
#define MOUSEKEY_WHEEL_DELAY 16
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100


//#define MK_KINETIC_SPEED
//#define MOUSEKEY_DELAY     0
//#define MOUSEKEY_INTERVAL     4     
//#define MOUSEKEY_MOVE_DELTA     4
//#define MOUSEKEY_INITIAL_SPEED     5
//#define MOUSEKEY_BASE_SPEED     1250
//#define MOUSEKEY_DECELERATED_SPEED     200
//#define MOUSEKEY_ACCELERATED_SPEED     750
//#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS     4
//#define MOUSEKEY_WHEEL_BASE_MOVEMENTS     8
//#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS     12
//#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS     2
