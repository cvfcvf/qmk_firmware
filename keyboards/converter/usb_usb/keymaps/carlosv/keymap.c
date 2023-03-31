/*
Copyright 2017 Balz Guenat <balz.guenat@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

//include "simbolos_ES.h"
#include "keymap_spanish.h"

// Esto hay que corregirlo
#define  XXXXXX KC_NO

// Alias personales

//#define CAPS_NUM LT(_NAV2,KC_CAPS)
#define TABmed LT(_MEDIA,KC_TAB)
#define TABsym LT(SYM1,KC_TAB)
#define ESCmed LT(_MEDIA,KC_ESC)
#define MNUmed LT(_MEDIA,KC_APP)
#define SPC_NAV LT(_NAV,KC_SPC)
//#define CAPSgui MT(KC_LGUI,KC_CAPS)
#define CAPSgui LGUI_T(KC_CAPS)
#define CAPSsym1 LT(SYM1,KC_CAPS)

#define CTLEFT LCTL(KC_LEFT)
#define CTRGHT LCTL(KC_RGHT)

#define NUBSemacs LT(_EMACS,KC_NUBS)
#define MINSemacs LT(_EMACS,KC_SLSH)
// Alias para acortar los códigos de TAP DANCE
#define LS_CAP TD(TD_LSFT_CAPS)
#define LC_INS TD(TD_LCTL_INS)
#define CTL_QWY TD(TD_QWERTY)
//#define LS_CAP TD()


// Alias para las teclas de símbolos

/* #undef KC_LPRN */
/* #define KC_LPRN LSFT(KC_8) */

// Layer shorthand
enum _layer {
             _BASE,
	     _QWERTY,
	     _MEDIA,
	     _NAV,
	     SYM1,
	     _EMACS,
	     //_BLANK
};

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
    TD_LSFT_CAPS,
    TD_LCTL_INS,
    TD_QWERTY,
    TD_BASE,
};

enum custom_keycodes {
    MAGIT = SAFE_RANGE,
    ORGPDF,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_ENiE_INS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_INS),
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_LCTL_INS] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_INS),
    [TD_QWERTY] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RCTL, _QWERTY)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MAGIT:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
	  SEND_STRING(SS_LCTL("x") SS_TAP(X_G));
        } else {
            // when keycode QMKBEST is released
        }
        break;
    case ORGPDF:
      if (record->event.pressed) {
	SEND_STRING(SS_LCTL("ce") SS_TAP(X_L) SS_TAP(X_P));
      }
    }
    return true;
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain Qwerty without layer switching
     *         ,---------------. ,---------------. ,---------------.
     *         |F13|F14|F15|F16| |F17|F18|F19|F20| |F21|F22|F23|F24|
     * ,---.   |---------------| |---------------| |---------------| ,-----------. ,---------------. ,-------.
     * |Esc|   |F1 |F2 |F3 |F4 | |F5 |F6 |F7 |F8 | |F9 |F10|F11|F12| |PrS|ScL|Pau| |VDn|VUp|Mut|Pwr| | Help  |
     * `---'   `---------------' `---------------' `---------------' `-----------' `---------------' `-------'
     * ,-----------------------------------------------------------. ,-----------. ,---------------. ,-------.
     * |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|JPY|Bsp| |Ins|Hom|PgU| |NmL|  /|  *|  -| |Stp|Agn|
     * |-----------------------------------------------------------| |-----------| |---------------| |-------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  | |Del|End|PgD| |  7|  8|  9|  +| |Mnu|Und|
     * |-----------------------------------------------------------| `-----------' |---------------| |-------|
     * |CapsL |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  :|  #|Retn|               |  4|  5|  6|KP,| |Sel|Cpy|
     * |-----------------------------------------------------------|     ,---.     |---------------| |-------|
     * |Shft|  <|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /| RO|Shift |     |Up |     |  1|  2|  3|KP=| |Exe|Pst|
     * |-----------------------------------------------------------| ,-----------. |---------------| |-------|
     * |Ctl|Gui|Alt|MHEN|HNJ| Space  |H/E|HENK|KANA|Alt|Gui|App|Ctl| |Lef|Dow|Rig| |  0    |  .|Ent| |Fnd|Cut|
     * `-----------------------------------------------------------' `-----------' `---------------' `-------'
     */
    [_BASE] = LAYOUT_all(
                      KC_F13,  KC_F14,  KC_F15,  KC_F16, KC_F17, KC_F18, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_INT3, KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN,
    ESCmed,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO,
    TABsym,  HR_A,    HR_S,    HR_D,    HR_F,    KC_G,   KC_H,   HR_J,   HR_K,    HR_L,    HR_SCLN, KC_QUOT,          KC_NUHS, KC_ENT,                                KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY,
    LS_CAP,  NUBSemacs, KC_Z,  KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  MINSemacs,        KC_INT1, KC_RSFT,          KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE,
    LC_INS,  KC_LGUI, KC_LALT, KC_INT5, KC_LNG2,         SPC_NAV,        KC_LNG1, KC_INT4, KC_INT2, KC_RALT, KC_RGUI, MNUmed,  CTL_QWY, KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT
    ),

    [_QWERTY] = LAYOUT_all(
                      KC_F13,  KC_F14,  KC_F15,  KC_F16, KC_F17, KC_F18, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUS,    KC_VOLD, KC_VOLU, KC_MUTE, KC_PWR,     KC_HELP,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_INT3, KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,    KC_STOP, KC_AGIN,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,          KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,    KC_MENU, KC_UNDO,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_NUHS, KC_ENT,                                KC_P4,   KC_P5,   KC_P6,   KC_PCMM,    KC_SLCT, KC_COPY,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_INT1,  KC_RSFT,          KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PEQL,    KC_EXEC, KC_PSTE,
    KC_LCTL, KC_LGUI, KC_LALT, KC_INT5, KC_LNG2,         KC_SPC,         KC_LNG1, KC_INT4, KC_INT2, KC_RALT, KC_RGUI, KC_APP,  CTL_QWY, KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT, KC_PENT,    KC_FIND, KC_CUT
    ),
    [_NAV] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    QK_BOOT,          ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, KC_PGUP, CTLEFT , KC_UP , CTRGHT,  KC_BSPC,______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    KC_LGUI, ______,  ______,  ______,  ______, ______, KC_PGDN, KC_LEFT,KC_DOWN,KC_RGHT,  KC_DEL, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______, KC_UNDO,  KC_CUT, KC_COPY,KC_PSTE, ______, ______,  KC_HOME, ______,  KC_END, KC_ENT,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     KC_WBAK,______,KC_WFWD,  ______,       ______,______,    ______,______
    ),

    [SYM1] = LAYOUT_all(
    ______,  ______,  ______, ______, ______,  ______,  ______,  ______,  ______, ______,  ______, ______,
    QK_BOOT,          ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ES_LBRC, ES_RBRC,______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ES_IQUE, ES_LPRN, ES_RPRN,ES_QUES, ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______, ES_LCBR,ES_RCBR,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),

    [_MEDIA] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    QK_BOOT,          ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  KC_VOLD,KC_MUTE,KC_VOLU,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  KC_MPRV,KC_MPLY,KC_MNXT,  ______, ______,         ______, ______,            KC_VOLU,          ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     KC_MPRV,KC_VOLD,KC_MNXT, ______,       ______,______,    ______,______
    ),

    [_EMACS] = LAYOUT_all(
                      XXXXXX,  XXXXXX,  XXXXXX, XXXXXX, XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,  XXXXXX, XXXXXX, XXXXXX, XXXXXX,
    XXXXXX,           XXXXXX,  XXXXXX,  XXXXXX, XXXXXX, XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,  XXXXXX, XXXXXX, XXXXXX, XXXXXX,             XXXXXX,XXXXXX,XXXXXX,    XXXXXX,XXXXXX,XXXXXX,XXXXXX,    XXXXXX,
    XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX, XXXXXX, XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,     XXXXXX,XXXXXX,XXXXXX,    XXXXXX,XXXXXX,XXXXXX,XXXXXX,    XXXXXX,XXXXXX,
    XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX, XXXXXX, XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,  ORGPDF, XXXXXX, XXXXXX,         XXXXXX,     XXXXXX,XXXXXX,XXXXXX,    XXXXXX,XXXXXX,XXXXXX,XXXXXX,    XXXXXX,XXXXXX,
    XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX, MAGIT , XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,  XXXXXX, XXXXXX,         XXXXXX, XXXXXX,                              XXXXXX,XXXXXX,XXXXXX,XXXXXX,    XXXXXX,XXXXXX,
    XXXXXX,  ______,  XXXXXX,  XXXXXX,  XXXXXX, XXXXXX, XXXXXX,  XXXXXX,  XXXXXX, XXXXXX,  XXXXXX, ______,         XXXXXX, XXXXXX,            XXXXXX,           XXXXXX,XXXXXX,XXXXXX,XXXXXX,    XXXXXX,XXXXXX,
    XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,  XXXXXX,         XXXXXX,           XXXXXX, XXXXXX,  XXXXXX, XXXXXX, XXXXXX, XXXXXX, XXXXXX,     XXXXXX,XXXXXX,XXXXXX,    XXXXXX,       XXXXXX,XXXXXX,    XXXXXX,XXXXXX
    ),
};

/*

    [_BLANK] = LAYOUT_all(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
*/

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case HR_A:
        case HR_S:
        case HR_L:
        case HR_SCLN: 
            return TAPPING_TERM_LARGO;
        default:
            return TAPPING_TERM;
    }
}   


/* bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case LT(_FUNC,KC_ESC): */
/*         case LT(_NUM, KC_ENTER): */
/*         //case LT(_MACRO, KC_BSPC): */
/*         //case LT(_SYM, KC_SPC): */
/*         case LT(_NAV, KC_TAB ): */
/*         case LT(_MEDIA, KC_DEL): */
/*         case TD(LT_BSPC): */

/*         // Immediately select the hold action when another key is pressed. */
/*             return true; */
/*         default: */
/*             // Do not select the hold action when another key is pressed. */
/*             return false; */
/*     } */
/* } */


bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {  
        case HR_D:
        case HR_F:
        case HR_J:
        case HR_K:
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}
