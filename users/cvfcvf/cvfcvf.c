#include "keymap_spanish.h"
#include "cvfcvf.h"

#define _LOWER _SYM
#define _RAISE _NUMPAD

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_ENiE_INS] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_INS),
    [TD_LSFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS),
    [TD_LCTL_INS] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_INS),
    [TD_QWERTY] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RCTL, _QWERTY),
    [TD_UPR_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset)
};


// Ajustes de macros
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
    break;
  case OPEN:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xf"));
    }
    break;
  case SAVE:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xs"));
    }
    break;
  case BUFFER:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") SS_TAP(X_B));
    }
    break;
  case RECENT:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xr"));
    }
    break;
  case NODIV:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") SS_TAP(X_1));
    }
    break;
  case DIVH:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") SS_TAP(X_2));
    }
    break;
  case DIVV:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") SS_TAP(X_3));
    }
    break;
  case KILL:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("x") SS_TAP(X_K));
    }
    break;
  case SAVE_AS:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("xw"));
    }
    break;
  case esBQUOT:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_LBRC) SS_TAP(X_SPC));
    }
    break;
  case TeXnERR:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL("c") SS_TAP(X_LBRC) SS_TAP(X_SPC));// Esto es lo mismo que esBQUOT, habría que encontrar la forma de llamar directamente a ese keycode
    }
    break;
    // Esto viene de la configuración del sofle RGB, mejor como un condicional.
  case KC_QWERTY:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_QWERTY);
    }
    return false;
  case KC_COLEMAK:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_COLEMAK);
    }
    return false;
  case KC_COLEMAKDH:
    if (record->event.pressed) {
      set_single_persistent_default_layer(_COLEMAKDH);
    }
    return false;
  case KC_LOWER:
    if (record->event.pressed) {
      layer_on(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_LOWER);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
  case KC_RAISE:
    if (record->event.pressed) {
      layer_on(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    } else {
      layer_off(_RAISE);
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
    }
    return false;
  case KC_ADJUST:
    if (record->event.pressed) {
      layer_on(_ADJUST);
    } else {
      layer_off(_ADJUST);
    }
    return false;
  case KC_D_MUTE:
    if (record->event.pressed) {
      register_mods(mod_config(MOD_MEH));
      register_code(KC_UP);
    } else {
      unregister_mods(mod_config(MOD_MEH));
      unregister_code(KC_UP);
    }

    /* case : */
    /*   if (record->event.pressed) { */
    /*     SEND_STRING(); */
    /*   } */
    /*   break; */
  }
  return true;
};
 
// Ajustes de HRM
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case symA:
        case HR_A:
        case HR_S:
        case HR_L:
        case HR_SCLN:
        case symSCLN:
            return TAPPING_TERM_LARGO;
        default:
            return TAPPING_TERM;
    }
}   

/* bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case LT(_FUNC,KC_ESC): */
/*         case LT(_NUMPAD, KC_ENTER): */
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

/* // Combos */
/* uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead! */
/* const uint16_t PROGMEM fj_combo[] = {HR_F, HR_J, COMBO_END}; */

/* combo_t key_combos[] = { */
/*   [FJ_TILDE] = COMBO(fj_combo, ES_ACUT), */
/*   }; */

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void ql_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            tap_code(KC_ENT);
            break;
        case TD_SINGLE_HOLD:
            layer_on(_NUMPAD);
            break;
        case TD_DOUBLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_NUMPAD)) {
                // If already set, then switch it off
                layer_off(_NUMPAD);
            } else {
                // If not already set, then switch the layer on
                layer_on(_NUMPAD);
            }
            break;
        default:
            break;
    }
}

void ql_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        layer_off(_NUMPAD);
    }
    ql_tap_state.state = TD_NONE;
}

/* // Associate our tap dance key with its functionality */
/* tap_dance_action_t tap_dance_actions[] = { */
/*     [QUOT_LAYR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ql_finished, ql_reset) */
/* }; */

/* // Set a long-ish tapping term for tap-dance keys */
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case QK_TAP_DANCE ... QK_TAP_DANCE_MAX: */
/*             return 275; */
/*         default: */
/*             return TAPPING_TERM; */
/*     } */
/* } */

// Ajustes del CAPS_WORD
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
