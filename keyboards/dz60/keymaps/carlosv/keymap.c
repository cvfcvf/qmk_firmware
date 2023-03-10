#include QMK_KEYBOARD_H

#include "keymap_spanish.h"
// Alias personales

//#define CAPS_NUM LT(_NAV2,KC_CAPS)
#define TABmed LT(_MEDIA,KC_TAB)
//#define TABsym LT(_SYM,KC_TAB)
#define MNUmed LT(_MEDIA,KC_APP)
#define SPC_NAV LT(_NAV,KC_SPC)
//#define CAPSgui MT(KC_LGUI,KC_CAPS)
#define CAPSgui LGUI_T(KC_CAPS)
//#define CAPSsym LT(_SYM,KC_CAPS)

#define CTLEFT LCTL(KC_LEFT)
#define CTRGHT LCTL(KC_RGHT)

// Alias para acortar los códigos de TAP DANCE
#define LS_CAP TD(TD_LSFT_CAPS)
#define LC_INS TD(TD_LCTL_INS)
//#define LS_CAP TD()

#define CAPS_NUM LT(_NUM,KC_CAPS)

// Left-hand home row mods
#define HR_A LGUI_T(KC_A)
#define HR_S LALT_T(KC_S)
#define HR_D LCTL_T(KC_D)
#define HR_F LSFT_T(KC_F)

// Right-hand home row mods
#define HR_J RSFT_T(KC_J)
#define HR_K RCTL_T(KC_K)
#define HR_L LALT_T(KC_L)
#define HR_SCLN RGUI_T(KC_SCLN)


// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_ENiE_INS,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_ENiE_INS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_INS),
};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * _______ can be used in place of KC_TRNS (transparent) *
 * XXXXXXX can be used in place of KC_NO (No Operation)  *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
// Layer shorthand
enum _layer {
	     _BASE,
	     _MEDIA,
	     _NAV,
	     _NUM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* ISO 6u layout layer 0 (UK Layout shown)
   * ,-----------------------------------------------------------.
   * |Esc|1 !|2 "|3 £|4 $|5 %|6 ^|7 &|8 *|9 (|0 )|- _|= +| Bksp  |
   * |-----------------------------------------------------------|
   * | Tab | Q | W | E | R | T | Y | U | I | O | P |[ {|] }|Enter|
   * |------------------------------------------------------.    |
   * | Fn1  | A | S | D | F | G | H | J | K | L |; :|' @|# ~|    |
   * |-----------------------------------------------------------|
   * |Sft |\ || Z | X | C | V | B | N | M |, <|. >|/ ?|  Shift   |
   * |-----------------------------------------------------------|
   * |Ctrl |GUI|Alt  |         Space         |Alt  |GUI|Fn2|Ctrl |
   * `-----------------------------------------------------------'
   */
  [_BASE] = LAYOUT_60_iso(
    KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS,          KC_EQL,     KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_LBRC,          KC_RBRC,
    CAPS_NUM, HR_A,    HR_S,    HR_D,    HR_F,    KC_G,    KC_H,    HR_J,    HR_K,    HR_L,    HR_SCLN,         KC_QUOT,          KC_NUHS,    KC_ENT,
    KC_LSFT,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,          KC_SLSH,          KC_RSFT,
    KC_LCTL,  KC_LGUI, KC_LALT,                            SPC_NAV,                            KC_RALT,         LT(_NUM,KC_APP), MO(_MEDIA), KC_RCTL),

  [_NAV] = LAYOUT_60_iso(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_UP,   KC_PGUP, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_END , KC_INS , KC_PGDN, XXXXXXX, XXXXXXX,
    _______, _______, _______,                            XXXXXXX,                            _______, XXXXXXX, XXXXXXX, _______),

  [_NUM] = LAYOUT_60_iso(
    KC_GRV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, KC_DEL , KC_BSPC,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P4 ,  KC_P5  , KC_P6 ,  XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PMNS, KC_P1  , KC_P2  , KC_P3  , XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PPLS, KC_P0  , XXXXXXX, KC_PDOT, XXXXXXX, _______,
    _______, _______, _______,                            _______,                            _______, _______, _______, _______),

  [_MEDIA] = LAYOUT_60_iso(
    KC_GRV,  KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______,                            XXXXXXX,                            _______, _______, _______, _______),

};
