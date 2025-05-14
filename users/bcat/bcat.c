// Copyright 2019 Jonathan Rascher
// SPDX-License-Identifier: ISC

#include "bcat.h"

#include "quantum.h"

// Weak functions to further delegate QMK's built-in hooks:

__attribute__((weak)) void process_record_oled(uint16_t keycode, const keyrecord_t *record) {}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

// Custom keycode implementations:

static const int8_t NO_LAYER = -1;

static int8_t alt_tab_layer = NO_LAYER;

// Process single-key Alt+Tab keycode that holds Alt until the current layer is
// released. This allows a layer key to be pressed along with the Alt+Tab
// keycode to open the system's window switcher. The Alt+Tab key can then be
// released, and the window switcher can be navigated as long as the layer key
// is still held down.
static void process_alt_tab(keyrecord_t *record) {
    if (record->event.pressed) {
        if (alt_tab_layer == NO_LAYER) {
            alt_tab_layer = layer_switch_get_layer(record->event.key);
            register_code(KC_LALT);
        }
        register_code(KC_TAB);
    } else {
        unregister_code(KC_TAB);
    }
}

static void layer_state_set_alt_tab(layer_state_t state) {
    if (alt_tab_layer != NO_LAYER && !layer_state_cmp(state, alt_tab_layer)) {
        unregister_code(KC_LALT);
        alt_tab_layer = NO_LAYER;
    }
}

// QMK hooks:

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_record_oled(keycode, record);
    if (!process_record_keymap(keycode, record)) {
        return false;
    }
    switch (keycode) {
        case CC_ALTT:
            process_alt_tab(record);
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = layer_state_set_keymap(state);
    layer_state_set_alt_tab(state);
    return state;
}
