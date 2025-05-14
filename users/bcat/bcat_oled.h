// Copyright 2021 Jonathan Rascher
// SPDX-License-Identifier: ISC

#pragma once

#include <stdbool.h>
#include <stdint.h>

#include "led.h"

/* Keyboard status passed to the oled_task_keymap function and used by the
 * various keyboard pet implementations.
 */
typedef struct {
    uint8_t mods;
    led_t   leds;
    uint8_t wpm;
} oled_keyboard_state_t;

/* Note: Functions below assume a vertical OLED that is 32px (5 chars) wide. */

/* Renders layer status at the cursor. Occupies 5x1 character cells. */
void render_oled_layers(void);

/* Renders LED indicators (Num/Caps/Scroll Lock) at the cursor. Occupies 5x3
 * character cells.
 */
void render_oled_indicators(led_t leds);

/* Renders calculated WPM count at the cursor. Occupies 5x2 character cells. */
void render_oled_wpm(uint8_t wpm);

#if defined(BCAT_OLED_PET)
/* Renders an animated critter at the cursor that can respond to keystrokes,
 * typing speed, etc. Should be about 5 character cells wide, but exact height
 * varies depending on the specific OLED pet implementation linked in.
 *
 * The rendered image will be one line taller than the OLED pet's animation
 * frame height to accommodate pets that "jump" when the spacebar is pressed.
 */
void render_oled_pet(uint8_t col, uint8_t line, const oled_keyboard_state_t *keyboard_state);
#endif
