 /* Copyright 2020 Josef Adamcik
  * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
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

//Sets up what the OLED screens display.

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM raw_logo[] = {
        0,  0,  0,  0,  0,  0,  0,  0, 16, 32, 32, 96, 96,192,192,128,128,  0,  0,  0,  0,  0,128,128,192,192,224,224,240,112,120, 60, 28,142,135,195,193, 96, 32,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0, 64, 64, 96, 96, 96, 48, 48, 49, 57, 59, 63,191,159,223,222,223,255,255,255,247,251,249,253,252,254,222,207,207,135,131,131,128,  0,  0,  0,  0,  0,  0,  0,255,255, 15, 62,248,224,128,  0,  0,255,255,255,  0,  0,  0,243,243,243,  0,  0,  0,192,224,112, 48, 48, 48, 48, 48, 48,  0,  0,  0,255,255,  0,128,192,192, 96,112, 48, 16,  0,  0,255,255,255,131,131,131,131,199,254,252,  0, 48, 48,254,254, 48, 48, 48, 48,  0,  0,243,243,  0,  0,  0,128,224,224,112, 48, 48, 48, 48, 48, 32,  0,  0,  0,
        0,  0,  0,  0,  0,  4,  4, 12, 12, 12, 28, 24, 24, 56,185,249,251,251,243,247,255,255,255,255,222,159,191, 63,127,127,247,243,227,227,195,129,  1,  1,  0,  0,  0,  0,  0,  0,255,255,  0,  0,  0,  3, 15, 63,124,255,255,255,  0,  0,  0,127,255,255,  0,  0,  0, 63,127,112,224,192,192,192,192, 96,  0,  0,  0,255,255,  7, 15, 29, 56,112,224,224,192,  0,  0,255,255,255,  3,  3,  3,  1,  1,  1,  0,  0,  0,  0,127,127,224,192,192,192,  0,  0,255,255,  0,  0,  0, 31, 63,125,224,192,192,192,192,224, 64,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0, 16,  0,  8, 12, 13,  7,  7,  3,  3,  1,  0,  0,  0,  1,  1,  3,  3,  7,  7, 15, 15, 30, 28, 60,121,113,225,195,131,  6,  4,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    };

    oled_write_raw_P(raw_logo, sizeof(raw_logo));
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);

    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Save"), false);
            break;
        case 1:
            oled_write_ln_P(PSTR("Get"), false);
            break;
        default:
            oled_write_P(PSTR("Print\n"), false);
            break;
    }
    oled_write_P(PSTR("\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("my"), false);
    switch (get_highest_layer(layer_state)) {
        case 0:
        case 1:
            oled_write_P(PSTR("Soul\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("Life"), false);
            break;
        case 3:
            oled_write_P(PSTR("Hell"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undead"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("NUMLK"), led_usb_state.num_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
