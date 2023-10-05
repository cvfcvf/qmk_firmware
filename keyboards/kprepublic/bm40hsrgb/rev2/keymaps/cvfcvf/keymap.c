/* Copyright 2020 tominabox1
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
#include QMK_KEYBOARD_H

#include "keymap_spanish.h"
#include "cvfcvf.h"

/* enum layers { */
/*   _QWRTY, */
/*   _LOWER, */
/*   _RAISE, */
/*   _NAVIG, */
/*   _ADJUST */
/* }; */

//#define TL_LOWR MO(_SYM)
#define TL_LOWR LT(_SYM, KC_ENT)

#define TL_UPPR MO(_NUM)
//#define TL_UPPR LT(_NUM,KC_ENT)

#define em_Z LT(_EMACS,KC_Z)

#define _QWRTY _BASE
#define _LOWER _SYM
#define _RAISE _NUM
#define _ADJUST _MEDIA
#define _NAVIG _NAV

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTog| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
//[_QWRTY] = LAYOUT_ortho_4x12_1x2uC(
[_BASE] = LAYOUT_ortho_4x12_1x2uC(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  HR_A,    HR_S,    HR_D,    HR_F,    KC_G,    KC_H,    HR_J,    HR_K,    HR_L,    HR_SCLN, KC_QUOT,
    KC_LSFT, em_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  MINSemacs, KC_ENT ,
    KC_LCTL, DF(_NUM),KC_LGUI, KC_LALT, TL_LOWR,      SPC_NAV,     TL_UPPR, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

[_NAV] = LAYOUT_ortho_4x12_1x2uC(
    KC_GRV , XXXXXXX, XXXXXXX, KC_APP , XXXXXXX, KC_INS , KC_PGUP, CTLEFT,  KC_UP,   CTRGHT,  XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, CW_TOGG, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL , XXXXXXX,
    _______, KC_UNDO, XXXXXXX, KC_WBAK, KC_WFWD, XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END , XXXXXXX, KC_ENT ,
    KC_LCTL, DF(_NUM),KC_LGUI, KC_LALT, TL_LOWR,      SPC_NAV,     KC_RALT, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
//[_LOWER] = LAYOUT_ortho_4x12_1x2uC(
[_SYM] = LAYOUT_ortho_4x12_1x2uC(
    _______, ES_EXLM, ES_DQUO, ES_BULT, ES_DLR,  ES_PERC, ES_AMPR, ES_IEXL,    ES_LBRC,    ES_RBRC, ES_EXLM, KC_BSPC,
    KC_DEL,  ES_EQL,  ES_PLUS, ES_ASTR, ES_SLSH, ES_CIRC, ES_BSLS, ES_IQUE,    ES_LPRN,    ES_RPRN, ES_QUES, ES_CCED,
    _______, miEURO , ES_LABK, ES_RABK, ES_PIPE, ES_QUOT, XXXXXXX, ES_HASH,    ES_LCBR,    ES_RCBR, ES_AT  , _______,
    _______, _______ ,_______, _______, _______,      _______,     _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
//[_RAISE] = LAYOUT_ortho_4x12_1x2uC(
[_NUM] = LAYOUT_ortho_4x12_1x2uC(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4   , KC_5,    KC_6   , ES_MINS, KC_BSLS,
    KC_LSFT, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1   , KC_2,    KC_3   , ES_PLUS, KC_ENT ,
    KC_LCTL,DF(_BASE),KC_LGUI, KC_LALT, TL_LOWR,      SPC_NAV,     _______, KC_0,    KC_DOT , KC_VOLU, KC_MPLY
),

[_EMACS] = LAYOUT_ortho_4x12_1x2uC(
/*    ESC  ,    Q   ,    W   ,    E   ,    R   ,    T   ,    Y   ,    U   ,    I   ,    O   ,    P   ,    BS    */
    XXXXXXX, XXXXXXX, SAVE_AS, XXXXXXX, RECENT , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, ORGPDF , XXXXXXX, 
    XXXXXXX, XXXXXXX, SAVE   , XXXXXXX, OPEN   , MAGIT  , XXXXXXX, XXXXXXX, KILL   , XXXXXXX, XXXXXXX, XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, BUFFER , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),
/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
//[_ADJUST] = LAYOUT_ortho_4x12_1x2uC(
[_MEDIA] = LAYOUT_ortho_4x12_1x2uC(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SYM, _NUM, _MEDIA);
}

// Combos
#include "combos.c"

// Todo esto debería estar en un fichero más general
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case ES_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}
