// Copyright 2021 Jonathan Rascher
// SPDX-License-Identifier: ISC

#include <stdint.h>

#include "progmem.h"

/* Adjust RGB static hue ranges for shorter gradients than default. */
const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {255, 127, 63, 31, 15};
