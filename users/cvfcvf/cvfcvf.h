// ESto no sé qué hace, pero estaba en el fichero de ejemplo. Se
// cierra al final.
#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

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
    BUFFER,
};

// Layer shorthand
enum _layer {
  _BASE,
  _QWERTY,
  _MEDIA,
  _NAV,
  _SYM,
  _NUM,
  _EMACS,
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
};

#endif
