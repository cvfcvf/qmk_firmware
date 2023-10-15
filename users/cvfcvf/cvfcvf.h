// ESto no sé qué hace, pero estaba en el fichero de ejemplo. Se
// cierra al final.
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// Configuraciones para TAPPING TERM
#ifdef TAPPING_TERM
  #undef TAPPING_TERM
#endif

#define TAPPING_TERM 180  // Delay for tap modifiers until it is considered a hold
#define TAPPING_TERM_PER_KEY
#define TAPPING_TERM_LARGO 250

// #define IGNORE_MOD_TAP_INTERRUPT          // Enable ignore mod tap interrupt: https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt // Parece que ya no es necesario y da un error al compilar

//#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY  // Allows configuration of ignore mod tap interrupt per key in keymap.c

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

//#define COMBO_COUNT 2  // Number of defined combos
//#define COMBO_TERM 20  // Delay for combo keys to be chained together

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY


// Alias personales

//#define CAPS_NUM LT(_NAV2,KC_CAPS)
#define TABmed LT(_MEDIA,KC_TAB)
#define TABsym LT(_SYM,KC_TAB)
#define ESCmed LT(_MEDIA,KC_ESC)
#define MNUmed LT(_MEDIA,KC_APP)
#define SPC_NAV LT(_NAV,KC_SPC)
//#define CAPSgui MT(KC_LGUI,KC_CAPS)
#define CAPSgui LGUI_T(KC_CAPS)
#define CAPSsym1 LT(_SYM,KC_CAPS)

#define CTLEFT LCTL(KC_LEFT)
#define CTRGHT LCTL(KC_RGHT)

#define NUBSemacs LT(_EMACS,KC_NUBS)
#define MINSemacs LT(_EMACS,KC_SLSH)

#define GRVnum LT(_NUM,KC_GRV)

#define miEURO ALGR(KC_E)

// Alias para acortar los códigos de TAP DANCE
#define LS_CAP TD(TD_LSFT_CAPS)
#define LC_INS TD(TD_LCTL_INS)
#define CTL_QWY TD(TD_QWERTY)
//#define LS_CAP TD()

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

enum custom_keycodes {
    MAGIT = SAFE_RANGE,
    ORGPDF,
    OPEN,
    SAVE,
    SAVE_AS,
    BUFFER,
    RECENT,
    KILL,
    DIVH,
    DIVV,
    NODIV,
};

// Layer shorthand
enum _layer {
  _BASE,
  _NUM,
  _QWERTY,
  _NAV,
  _SYM,
  _EMACS,
  _MEDIA,
  //_BLANK
};

// Tap Dance declarations
enum {
    TD_ESC_CAPS,
    TD_ENiE_INS,
    TD_LSFT_CAPS,
    TD_LCTL_INS,
    TD_QWERTY,
    TD_BASE,
    TD_UPR_NUM,
};

// Combos
enum combos{
    FJ_TILDE,
    JK_BSPC,
    COMBO_LENGTH // este siempre el último
    };
//uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!


// Ajustes de tecla UPPER, con tap dance
// Define a type for as many tap dance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
td_state_t cur_dance(tap_dance_state_t *state);

// Functions associated with individual tap dances
void ql_finished(tap_dance_state_t *state, void *user_data);
void ql_reset(tap_dance_state_t *state, void *user_data);
#endif

