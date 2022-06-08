#include "lotus58.h"

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
