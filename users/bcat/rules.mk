# Enable critical features on all keyboards.
BOOTMAGIC_ENABLE = yes
EXTRAKEY_ENABLE = yes
NKRO_ENABLE = yes
TRI_LAYER_ENABLE = yes

# Enable link-time optimization and jump relaxing to reduce binary size.
LTO_ENABLE = yes
AVR_CFLAGS += -mrelax

# Include common utilities shared across all our keymaps.
SRC += bcat.c

# Include additional utilities that extend optional QMK features only enabled
# on some keyboards.
ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += bcat_oled.c
	WPM_ENABLE = yes  # for WPM and animated "keyboard pet" widgets

	# OLED pets (animated critters that react to typing) take up a lot of
	# firmware space, so only compile one, and only if requested.
	BCAT_OLED_PET ?= no
	ifneq ($(strip $(BCAT_OLED_PET)), no)
		SRC += bcat_oled_pet_$(strip $(BCAT_OLED_PET)).c
		OPT_DEFS += -DBCAT_OLED_PET
	endif
endif

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
	SRC += bcat_rgblight.c
endif

# Disable unwanted build options on all keyboards. (Mouse keys are turned off
# due to https://github.com/qmk/qmk_firmware/issues/8323, and the rest are
# turned off to reduce firmware size.)
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
MOUSEKEY_ENABLE = no

# Disable unwanted hardware options on all keyboards. (Some keyboards turn
# these features on by default even though they aren't actually required.)
MIDI_ENABLE = no
SLEEP_LED_ENABLE = no

# Disable other unused options on all keyboards.
AUTOCORRECT_ENABLE = no
AUTO_SHIFT_ENABLE = no
CAPS_WORD_ENABLE = no
COMBO_ENABLE = no
DEBUG_ENABLE = no
DYNAMIC_TAPPING_TERM_ENABLE = no
GRAVE_ESC_ENABLE = no
KEY_LOCK_ENABLE = no
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no
MAGIC_ENABLE = no
PROGRAMMABLE_BUTTON_ENABLE = no
REPEAT_KEY_ENABLE = no
SECURE_ENABLE = no
SPACE_CADET_ENABLE = no
STENO_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no
UCIS_ENABLE = no
UNICODEMAP_ENABLE = no
UNICODE_ENABLE = no
