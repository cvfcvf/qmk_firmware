/* Copyright 2020 Christopher Ko <chriskopher@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TAPPING_TERM 180  // Delay for tap modifiers until it is considered a hold
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM_LARGO 250

#define IGNORE_MOD_TAP_INTERRUPT          // Enable ignore mod tap interrupt: https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
//#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY  // Allows configuration of ignore mod tap interrupt per key in keymap.c

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

//#define COMBO_COUNT 2  // Number of defined combos
//#define COMBO_TERM 20  // Delay for combo keys to be chained together

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define LED_CAPS_LOCK_PIN B0
#define LED_PIN_ON_STATE 0
