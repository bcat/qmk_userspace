// Copyright 2019 Jonathan Rascher
// SPDX-License-Identifier: ISC

#include QMK_KEYBOARD_H

#include "bcat.h"

#define KY_LOCK LGUI(KC_L) // Chrome OS: Lock screen
#define KY_MICM LSG(KC_1)  // Meet Shortcuts: Mute mic
#define KY_MICU LSG(KC_2)  // Meet Shortcuts: Unmute mic
#define KY_RHAND LSG(KC_3) // Meet Shortcuts: Raise/lower hand

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [LAYER_DEFAULT] = LAYOUT(
        KC_MPLY,  KC_VOLU,  KY_RHAND,
        KY_LOCK,  KC_VOLD,  KY_MICU,
        TL_LOWR,  KC_MUTE,  KY_MICM
    ),
    [LAYER_LOWER ... LAYER_ADJUST] = LAYOUT(
        EE_CLR,   _______,  QK_BOOT,
        _______,  _______,  _______,
        _______,  _______,  _______
    ),
    // clang-format on
};
