# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Base optimization
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
COMBO_ENABLE = no
GRAVE_ESC_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
RGBLIGHT_ENABLE = no
QMK_SETTINGS = no

# Build Options
SPLIT_KEYBOARD = yes
BOOTMAGIC_ENABLE = lite
ENCODER_ENABLE = yes
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

LTO_ENABLE = yes

ifeq ($(strip $(BOOTMAGIC_ENABLE)), lite)
    SRC += ../common/bootmagic_lite.c
endif
