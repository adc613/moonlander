# MCU name
MCU = at90usb1286

# Bootloader selection
BOOTLOADER = halfkay

# Build Options
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE   = yes  # Mouse keys
EXTRAKEY_ENABLE   = yes  # Audio control and System control
CONSOLE_ENABLE    = yes  # Console for debug
COMMAND_ENABLE    = yes  # Commands for debug and configuration
NKRO_ENABLE       = yes  # USB Nkey Rollover
BACKLIGHT_ENABLE  = no   # Enable keyboard backlight functionality
AUDIO_ENABLE      = no   # Audio output
CUSTOM_MATRIX     = yes  # We definitely have a nonstandard matrix

# Project specific files
SRC = matrix.c
