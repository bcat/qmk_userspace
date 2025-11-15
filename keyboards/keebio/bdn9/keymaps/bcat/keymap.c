// Copyright 2019 Jonathan Rascher
// SPDX-License-Identifier: ISC

#include QMK_KEYBOARD_H

#include "bcat.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [LAYER_DEFAULT] = LAYOUT(
        KC_MUTE,  TL_LOWR,  BL_BRTG,
        KC_F4,    KC_F5,    KC_F6,
        KC_F1,    KC_F2,    KC_F3
    ),
    [LAYER_LOWER ... LAYER_ADJUST] = LAYOUT(
        EE_CLR,   _______,  QK_BOOT,
        KC_F10,   KC_F11,   KC_F12,
        KC_F7,    KC_F8,    KC_F9
    ),
    // clang-format on
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [LAYER_DEFAULT... LAYER_ADJUST] =
        {
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            ENCODER_CCW_CW(BL_DOWN, BL_UP),
        },
};
