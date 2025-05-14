// Copyright 2019 Jonathan Rascher
// SPDX-License-Identifier: ISC

#pragma once

/* Use an extra LED on the right side since it's wider on the 65% PCB. */
#undef RGBLIGHT_LED_COUNT
#define RGBLIGHT_LED_COUNT 17

/* Set up RGB lighting so it works with either side as master. */
#undef RGBLED_SPLIT
#define RGBLED_SPLIT \
    { 8, 9 }
