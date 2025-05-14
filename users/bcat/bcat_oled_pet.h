// Copyright 2021 Jonathan Rascher
// SPDX-License-Identifier: ISC

// Common interface for an OLED pet (animated critter that reacts to typing).
// Please link exactly one accompanying .c file to implement these functions.

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "bcat_oled.h"

// Opaque token representing a single frame of the OLED pet animation.
// Different pet implementations have different valid state values, but the
// zero value must always represent the default state of the pet at startup.
typedef uint16_t oled_pet_state_t;

// Returns the number of bytes used to represent the animation frame (in
// oled_write_raw_P format). Note that every state the pet supports is expected
// to have the same frame size.
uint16_t oled_pet_frame_bytes(void);

// Returns the number of lines of the OLED occupied by the animation. Note that
// every state the pet supports is expected to have the same frame size. The
// returned value does not include the one line of padding that render_oled_pet
// uses to account for "jumping".
uint8_t oled_pet_frame_lines(void);

// Returns whether or not the OLED pet should "jump" when the spacebar is
// pressed. (The render_oled_pet implementation shifts the animation frame up
// one line when this happens.)
bool oled_pet_can_jump(void);

// Returns the delay before the next animation frame should be displayed.
uint16_t oled_pet_update_millis(const oled_keyboard_state_t *keyboard_state);

// Returns the state of the pet to be animated on the next animation tick.
oled_pet_state_t oled_pet_next_state(oled_pet_state_t state, const oled_keyboard_state_t *keyboard_state);

// Called after the OLED pet is rendered during each OLED task invocation.
// Receives the same keyboard state as render_oled_pet. The redraw param
// indicates whether or not an OLED frame was just redrawn, allowing a specific
// pet implementation to draw custom things atop its animation frames.
//
// When this function is called, the cursor will be in an unspecified location,
// not necessarily the top-left corner of the OLED pet.
void oled_pet_post_render(uint8_t col, uint8_t line, const oled_keyboard_state_t *keyboard_state, bool redraw);

// Returns a PROGMEM pointer to the specified frame buffer for the specified
// state. The animation frame has length given by oled_pet_frame_bytes and is
// formatted as expected by oled_write_raw_P.
const char *oled_pet_frame(oled_pet_state_t state);
