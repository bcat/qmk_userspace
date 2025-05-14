// Copyright 2021 Jonathan Rascher
// SPDX-License-Identifier: ISC

#include QMK_KEYBOARD_H

#include "bcat.h"

#if defined(OLED_ENABLE)
#    include "bcat_oled.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [LAYER_DEFAULT] = LAYOUT(
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                         KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                         KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                      KC_MPLY,  KC_LCTL,  TL_LOWR,  KC_SPC,   KC_ENT,   TL_UPPR,  KC_RALT,  KC_MUTE
    ),
    [LAYER_LOWER] = LAYOUT(
        CC_ALTT,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                      KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  _______,
        KY_CSPC,  KY_ZMRST, KY_ZMOUT, KY_ZMIN,  KC_WBAK,  KC_WFWD,                      KC_PIPE,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_TILD,
        _______,  KC_APP,   KC_PSCR,  KC_SCRL,  KC_PAUS,  KC_LGUI,                      KC_BSLS,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_GRV,
                                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
    [LAYER_RAISE] = LAYOUT(
        KC_CAPS,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                        KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F11,   KC_DEL,
        _______,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,                       KC_HOME,  KC_PGDN,  KC_PGUP,  KC_END,   KC_F12,   KC_INS,
                                      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
    [LAYER_ADJUST] = LAYOUT(
        _______,  MU_TOGG,  KC_MPLY,  KC_VOLU,  KC_MSTP,  _______,                      EE_CLR,   QK_BOOT,  _______,  _______,  _______,  _______,
        _______,  MU_NEXT,  KC_MPRV,  KC_VOLD,  KC_MNXT,  _______,                      RGB_RMOD, RGB_VAD,  RGB_VAI,  RGB_MOD,  RGB_SPI,  _______,
        _______,  _______,  _______,  KC_MUTE,  _______,  _______,                      RGB_HUI,  RGB_SAD,  RGB_SAI,  RGB_HUD,  RGB_SPD,  _______,
                                      _______,  _______,  _______,  _______,  RGB_TOG,  _______,  _______,  _______
    ),
    // clang-format on
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
            /* Left encoder (scrolling) */
            tap_code(clockwise ? KC_PGDN : KC_PGUP);
            return false;
        case 1:
            /* Right encoder (volume) */
            tap_code(clockwise ? KC_VOLU : KC_VOLD);
            return false;
        default:
            return true;
    }
}

#if defined(OLED_ENABLE)
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_keymap(const oled_keyboard_state_t *keyboard_state) {
    render_oled_layers();
    oled_advance_page(/*clearPageRemainder=*/false);
    oled_advance_page(/*clearPageRemainder=*/false);
    render_oled_wpm(keyboard_state->wpm);
    render_oled_pet(/*col=*/0, /*line=*/6, keyboard_state);
}
#endif
