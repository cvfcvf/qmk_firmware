#include QMK_KEYBOARD_H

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
	     _NAV1,
	     _NAV2
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
    KC_ESC,           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,            KC_MINS,          KC_EQL,     KC_BSPC,
    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,            KC_LBRC,          KC_RBRC,
    LT(_NAV2,KC_CAPS),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    TD(TD_ENiE_INS), KC_QUOT,          KC_NUHS,    KC_ENT,
    KC_LSFT,          KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,          KC_SLSH,          KC_RSFT,
    KC_LCTL,          KC_LGUI, KC_LALT,                            LT(_NAV1,KC_SPC),                   KC_RALT,         LT(_NAV2,KC_APP), MO(_MEDIA), KC_RCTL),


  [_MEDIA] = LAYOUT_60_iso(
    KC_GRV,  KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
    XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL, KC_LGUI, KC_LGUI,                            XXXXXXX,                            KC_RALT, KC_RGUI, _______, KC_RCTL),

  [_NAV1] = LAYOUT_60_iso(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______,
    _______, _______, _______, _______, KC_PGDN, KC_PGUP, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LGUI, KC_LALT,                            _______,                            _______, _______, _______, _______),

  [_NAV2] = LAYOUT_60_iso(
    _______, KC_F13 , KC_F14 , KC_F15 , KC_F16 , KC_F17 , KC_F18 , KC_F19 , KC_F20 , KC_F21 , KC_F22 , KC_F23 , KC_F24 , KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_PGUP, KC_END,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_PGDN, KC_RGHT, _______, _______, _______, _______,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LCTL, KC_LGUI, KC_LALT,                            _______,                            _______, _______, _______, _______),

};
