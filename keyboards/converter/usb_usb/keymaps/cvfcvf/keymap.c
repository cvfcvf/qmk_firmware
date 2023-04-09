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

#include "cvfcvf.h"
// Esto hay que corregirlo
#define  XXXXXX KC_NO


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
    [_BASE] = LAYOUT_fullsize_iso(
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,    KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    ESCmed,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,           KC_DEL,  KC_END,  KC_PGDN,    KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    TABsym,  HR_A,    HR_S,    HR_D,    HR_F,    KC_G,   KC_H,   HR_J,   HR_K,    HR_L,    HR_SCLN, KC_QUOT, KC_NUHS, KC_ENT,                                 KC_P4,   KC_P5,   KC_P6,
    LS_CAP,  NUBSemacs, KC_Z,  KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  MINSemacs,        KC_RSFT,           KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    LC_INS,  KC_LGUI, KC_LALT,                           SPC_NAV,                          KC_RALT, KC_RGUI, MNUmed,  CTL_QWY,  KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),
    
    [_QWERTY] = LAYOUT_fullsize_iso(
    KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR, KC_SCRL, KC_PAUS,
    KC_GRV ,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,  KC_HOME, KC_PGUP,   KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,              KC_DEL,  KC_END,  KC_PGDN,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,    KC_ENT,                                KC_P4,   KC_P5,   KC_P6,           
    KC_LSFT,  KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,                      KC_UP,               KC_P1,   KC_P2,   KC_P3,   KC_PENT,
    KC_LCTL,  KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT,  KC_RGUI,  KC_APP,     CTL_QWY, KC_LEFT, KC_DOWN, KC_RGHT,    KC_P0,            KC_PDOT
    ),

    [_NAV] = LAYOUT_fullsize_iso(
    QK_BOOT,          ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,    ______,______,______,
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,    ______,______,______,   ______,______,______,______,
    ______,  XXXXXXX, XXXXXXX, KC_APP , XXXXXXX, KC_INS , KC_PGUP, CTLEFT,  KC_UP,   CTRGHT,  XXXXXXX, XXXXXXX, XXXXXXX,	    ______,______,______,   ______,______,______,______,
    KC_LGUI, ______,  ______,  ______,  ______,  KC_CAPS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , XXXXXXX, XXXXXXX, XXXXXXX,                           ______,______,______,       
    ______,  XXXXXXX, KC_UNDO, XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END , KC_ENT ,          XXXXXXX,          ______,          ______,______,______,______,
    ______,  ______,  ______,                             XXXXXXX,                            ______,  XXXXXXX, XXXXXXX, ______,   KC_WBAK,______,KC_WFWD,  ______,       ______
    ),

    [_SYM] = LAYOUT_fullsize_iso(
    ______,           ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______, ______,   ______,  ______,   ______,______,______,
    ______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ______,  ______,  ______,  ______,  XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC,  ______,______,______,   ______,______,______,______,
    ______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ______,  ES_LBRC, ES_RBRC, ______,  XXXXXXX, XXXXXXX, XXXXXXX,	   ______,______,______,   ______,______,______,______,
    ______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ES_IQUE, ES_LPRN, ES_RPRN, ES_QUES, XXXXXXX, XXXXXXX, XXXXXXX, ______,                           ______,______,______,       
    ______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ______,  ______,  ES_LCBR, ES_RCBR, XXXXXXX, XXXXXXX, ______, 	          ______,          ______,______,______,______,
    ______,  ______,  ______,                             ______,                             ______,  ______,  ______,  ______,   ______,______,______,   ______,       ______        
				 ),
    [_MEDIA] = LAYOUT_fullsize_iso(
    QK_BOOT,          ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______, ______,   ______,  ______,   ______,______,______,
    ______,  KC_MPLY, KC_MSTP, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,  ______,______,______,   ______,______,______,______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,	   ______,______,______,   ______,______,______,______,
    ______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          ______,______,______,
    ______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,	          KC_VOLU,         ______,______,______,______,
    ______,  ______,  ______,                             XXXXXXX,                            ______,  ______,  ______,  _______,  KC_MPRV,KC_VOLD,KC_MNXT,______,       ______
				   ),

    [_EMACS] = LAYOUT_fullsize_iso(
    XXXXXXX,          ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______, ______,   ______,  ______,   ______,______,______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  ______,______,______,   ______,______,______,______,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ORGPDF,  XXXXXXX, XXXXXXX,           ______,______,______,   ______,______,______,______,
    XXXXXXX, XXXXXXX, SAVE  ,  XXXXXXX, OPEN  ,  MAGIT ,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                          ______,______,______,
    XXXXXXX, ______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BUFFER,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ______,  XXXXXXX,	          ______,          ______,______,______,______,
    XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  ______,______,______,   ______,       ______
				   ),
};

/*

    [_BLANK] = LAYOUT_fullsize_iso(
                      ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,
    ______,           ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______,             ______,______,______,    ______,______,______,______,    ______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______, ______,         ______,     ______,______,______,    ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,                              ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______, ______, ______,  ______,  ______, ______,  ______, ______,         ______, ______,            ______,           ______,______,______,______,    ______,______,
    ______,  ______,  ______,  ______,  ______,         ______,           ______, ______,  ______, ______, ______, ______, ______,     ______,______,______,    ______,       ______,______,    ______,______
    ),
*/

