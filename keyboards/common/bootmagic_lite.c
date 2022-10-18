 /* Copyright 2022 Andrei Gaevskii
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

#include QMK_KEYBOARD_H

// Work around to fix issue with incorrect pin state
void bootmagic_lite(void) {
    matrix_scan();
    wait_ms(100);
    matrix_scan();

    if (matrix_get_row(BOOTMAGIC_LITE_ROW) & (1 << BOOTMAGIC_LITE_COLUMN)) {
      // Jump to bootloader.
      bootloader_jump();
    }

    #if defined(SPLIT_KEYBOARD) && defined(BOOTMAGIC_LITE_ROW_RIGHT) && defined(BOOTMAGIC_LITE_COLUMN_RIGHT)
    if (matrix_get_row(BOOTMAGIC_LITE_ROW_RIGHT) & (1 << BOOTMAGIC_LITE_COLUMN_RIGHT)) {
        // Jump to bootloader.
        bootloader_jump();
    }
    #endif
}
