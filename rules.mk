OLED_ENABLE = yes
OLED_DRIVER = SSD1306

EXTRAKEY_ENABLE    = yes  # Audio and System control
NKRO_ENABLE        = yes  # Nkey Rollover
# DYNAMIC_MACRO_ENABLE = yes

MOUSEKEY_ENABLE    = no   # Mouse keys
RGBLIGHT_ENABLE    = no   # WS2812 RGB underlight
BOOTMAGIC_ENABLE   = no   # Virtual DIP switch configuration
CONSOLE_ENABLE     = no   # Console for debug
COMMAND_ENABLE     = no   # Commands for debug and configuration
BACKLIGHT_ENABLE   = no   # Keyboard backlight functionality
MIDI_ENABLE        = no   # MIDI controls
AUDIO_ENABLE       = no   # Audio output on port C6
UNICODE_ENABLE     = no   # Unicode
BLUETOOTH_ENABLE   = no   # Bluetooth
SWAP_HANDS_ENABLE  = no   # One-hand typing

WPM_ENABLE         = no   # wpm meter
RGB_MATRIX_ENABLE  = yes  # WS2812 RGB matrix

EXTRAFLAGS+=-flto  # Linking go brrrrr
AVR_CFLAGS=-Wno-array-bounds

SRC += features/achordion.c
