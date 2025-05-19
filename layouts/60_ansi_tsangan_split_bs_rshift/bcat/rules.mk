ifeq ($(strip $(KEYBOARD)), ai03/polaris)
	# Disable RGB underglow since case hides it.
	RGBLIGHT_ENABLE = no
endif
