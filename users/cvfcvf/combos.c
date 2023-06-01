#include "keymap_spanish.h"
#include "cvfcvf.h"

// Combos
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!
const uint16_t PROGMEM fj_combo[] = {HR_F, HR_J, COMBO_END};

combo_t key_combos[] = {
  [FJ_TILDE] = COMBO(fj_combo, ES_ACUT),
  };
