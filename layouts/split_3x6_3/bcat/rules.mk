ifeq ($(strip $(KEYBOARD)), crkbd/rev1)
	BOOTLOADER = atmel-dfu  # Elite-C

	OLED_ENABLE = yes  # Dual 128x32 OLED screens

	# Per-key RGB and underglow:
	RGBLIGHT_ENABLE = no
	RGB_MATRIX_ENABLE = yes

	BCAT_OLED_PET = luna
endif
