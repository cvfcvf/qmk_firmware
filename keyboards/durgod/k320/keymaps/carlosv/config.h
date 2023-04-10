/* Copyright 2021 Don Kjer and Tyler Tidman
 * Copyright 2021 Simon Arlott
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

#include "config_common.h"

/* USB Device descriptor parameter */
#define PRODUCT_ID      0x3200
// Taurus K320 models:
//#define DEVICE_VER      0x0001 // Base (no backlight)
//#define DEVICE_VER      0x0002 // Corona (white led matrix)
//#define DEVICE_VER      0x0003 // Aurora (red & blue led matrix)
//#define DEVICE_VER      0x0004 // Nebula (rgb led matrix)

/* key matrix size (cols in generic keyboard config) */
#define MATRIX_ROWS 7

#define MATRIX_ROW_PINS { A0, A1, A2, A3, A4, A5, A6 }

/* Configuración de space cadet */
#define LSPO_KEY KC_8
#define RSPC_KEY KC_9

/* Configuración de Home Row Mods */

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 250

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

