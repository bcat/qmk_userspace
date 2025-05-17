// Copyright 2020 Jonathan Rascher
// SPDX-License-Identifier: ISC

#pragma once

#include <stdbool.h>

#include "quantum_keycodes.h"

// Layer numbers shared across keymaps.
enum user_layer {
    LAYER_DEFAULT,
    LAYER_LOWER,
    LAYER_RAISE,
    LAYER_ADJUST,
};

// Custom keycodes shared across keymaps.
enum user_keycode {
    CC_ALTT = SAFE_RANGE,
    KEYMAP_SAFE_RANGE,
};

// Keycode aliases shared across keymaps.
#define KY_CSPC LCTL(KC_SPC)

#define KY_ZMIN LCTL(KC_EQL)
#define KY_ZMOUT LCTL(KC_MINS)
#define KY_ZMRST LCTL(KC_0)

#define KY_M1 LCTL(LSFT(KC_1))
#define KY_M2 LCTL(LSFT(KC_2))
#define KY_M3 LCTL(LSFT(KC_3))
#define KY_M4 LCTL(LSFT(KC_4))
#define KY_M5 LCTL(LSFT(KC_5))
#define KY_M6 LCTL(LSFT(KC_6))
#define KY_M7 LCTL(LSFT(KC_7))
#define KY_M8 LCTL(LSFT(KC_8))
#define KY_M9 LCTL(LSFT(KC_9))
