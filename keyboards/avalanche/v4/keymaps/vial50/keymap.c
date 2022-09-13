// Copyright 2022 vitvlkv (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk compile -kb avalanche/v3 -km default_v3
qmk flash -kb avalanche/v3 -km default_v3
*/

#include QMK_KEYBOARD_H

enum layer {
    LAYER_0,
    LAYER_1,
    LAYER_2,
};

#define FN_1 MO(LAYER_1)
#define LFN_2 LT(LAYER_2, KC_GRV)
#define RFN_2 MO(LAYER_2)
#define LFN_3 LSFT_T(KC_EQL)
#define RFN_3 RSFT_T(KC_MINS)
#define EN_LALT LALT_T(KC_ENT)
#define EN_RALT RALT_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_0] = LAYOUT(
                 KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSLS,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        KC_CAPS, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_RBRC,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_DEL,  KC_LGUI, KC_INS,  KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                                            KC__MUTE,LFN_2,   LFN_3,   KC_SPC,  EN_LALT, EN_RALT, FN_1,    RFN_3,   RFN_2,   KC_PSCR
    ),
    [LAYER_1] = LAYOUT(
                 _______, KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,                                     KC_DEL,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
        _______, _______, KC_APP,  XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,                                      KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, XXXXXXX, KC_F12,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [LAYER_2] = LAYOUT(
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                 _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_BSPC,                                     KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, KC_LPRN,
        _______, _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_DEL,                                      KC_BSPC, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX, KC_RPRN,
                 _______, KC_0,    KC_7,    KC_8,    KC_9,    KC_DOT,  _______, _______, _______, _______, XXXXXXX, KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

#ifdef OLED_ENABLE


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    static const char PROGMEM pacman[] = {
        128,224,248,252,254,254,252,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,248,252,254,254,252,248,224,128,  0,255,255,255,255,255,255,199,139,147,131,199,255,255,254,252,248,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,  0,  0,  3, 15, 31, 63,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127, 63, 31, 15,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  7,  7, 15, 15, 15, 15, 15, 15, 15,  7,  7,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    static const char PROGMEM ball_empty[] = {
        0,  0,  0,  0,  0,  0,  0,  0,224, 24,  4,  2,  2,  1,  1,  1,  1,  1,  2,  2,  4, 24,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 12, 16, 32, 32, 64, 64, 64, 64, 64, 32, 32, 16, 12,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };
    static const char PROGMEM ball_full[] = {
        0,  0,  0,  0,  0,  0,  0,  0,224,248,252,254,254,255,255,255,255,255,254,254,252,248,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3, 15, 31, 63, 63,127,127,127,127,127, 63, 63, 31, 15,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };

    int position = 10;

    int layer = get_highest_layer(layer_state) - 1;

    for (int i = 0; i < 4; i++)
    {
        oled_set_cursor(0, position);

        if (layer >= 0 && layer >= i)
        {
            oled_write_raw_P(ball_full, sizeof(ball_full));
        }
        else
        {
            oled_write_raw_P(ball_empty, sizeof(ball_empty));
        }

        position -= 3;
    }

    oled_set_cursor(0, 12);
    oled_write_raw_P(pacman, sizeof(pacman));

    return false;
}

#endif
