# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
BACKLIGHT_DRIVER = custom
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = yes

CUSTOM_MATRIX = yes
SRC += indicator_leds.c \
			 matrix.c duck_led/duck_led.c
