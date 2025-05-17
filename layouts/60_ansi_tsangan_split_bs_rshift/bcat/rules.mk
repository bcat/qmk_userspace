ifeq ($(strip $(KEYBOARD)), ai03/polaris)
	# Disable RGB underglow since solid case completely hides it.
	RGBLIGHT_ENABLE = no
endif
