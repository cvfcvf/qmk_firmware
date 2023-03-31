#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
#undef TAPPING_TERM
#define  TAPPING_TERM 200  // Delay for tap modifiers until it is considered a hold

#define IGNORE_MOD_TAP_INTERRUPT          // Enable ignore mod tap interrupt: https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
//#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY  // Allows configuration of ignore mod tap interrupt per key in keymap.c

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

//#define COMBO_COUNT 2  // Number of defined combos
//#define COMBO_TERM 20  // Delay for combo keys to be chained together

