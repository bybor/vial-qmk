VIA_ENABLE = yes
VIAL_ENABLE = yes
VIAL_INSECURE = yes

# ENCODERS
VIAL_ENCODERS_ENABLE = yes

EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes

RGBLIGHT_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += ../common/oled.c
endif
