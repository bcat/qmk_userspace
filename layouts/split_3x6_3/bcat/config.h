// Copyright 2019 Jonathan Rascher
// SPDX-License-Identifier: ISC

#pragma once

#if defined(KEYBOARD_crkbd_rev1)
#    define EE_HANDS

#    if defined(OLED_ENABLE)
#        undef OLED_FONT_H
#        define OLED_FONT_H "lib/glcdfont.c"
#    endif
#endif
