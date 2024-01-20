#include "homerow.h"
#include "layers.h"

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM et_combo[] = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};

const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};

const uint16_t PROGMEM io_combo[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM yi_combo[] = {KC_Y, KC_I, COMBO_END};

const uint16_t PROGMEM df_combo[] = {M_LC(KC_F), M_LA(KC_D), COMBO_END};
const uint16_t PROGMEM sd_combo[] = {M_LA(KC_D), M_LG(KC_S), COMBO_END};
const uint16_t PROGMEM sf_combo[] = {M_LG(KC_S), M_LC(KC_F), COMBO_END};
const uint16_t PROGMEM ef_combo[] = {KC_E, M_LC(KC_F), COMBO_END};
const uint16_t PROGMEM se_combo[] = {M_LG(KC_S), KC_E, COMBO_END};

const uint16_t PROGMEM jk_combo[] = {M_LC(KC_J), M_LA(KC_K), COMBO_END};
const uint16_t PROGMEM kl_combo[] = {M_LA(KC_K), M_LG(KC_L), COMBO_END};

const uint16_t PROGMEM cmdt_cmb[] = {KC_COMM, KC_DOT, COMBO_END};

enum {
  we,
  er,
  et,
  wr,
  xc,
  io,
  ui,
  yi,
  df,
  sd,
  sf,
  ef,
  se,
  jk,
  kl,
  cmdt,
};

combo_t key_combos[] = {
    /*                           en ru */
    [we] = COMBO(we_combo, KC_EXLM), // !
    [er] = COMBO(er_combo, KC_EQL),  // =
    [et] = COMBO(et_combo, KC_GRV),  // ` ё
    [wr] = COMBO(wr_combo, KC_AT),   // @ "

    [xc] = COMBO(xc_combo, KC_BSLS), // backslash

    [df] = COMBO(df_combo, KC_RPRN), // )
    [sd] = COMBO(sd_combo, KC_LPRN), // (
    [io] = COMBO(io_combo, KC_MINS), // -
    [ui] = COMBO(ui_combo, KC_CIRC), // ^ :
    [yi] = COMBO(yi_combo, KC_LBRC), // [ х

    [sf] = COMBO(sf_combo, KC_QUES), // ? ,
    [ef] = COMBO(ef_combo, KC_AMPR), // & ?
    [se] = COMBO(se_combo, KC_PIPE), // | /

    [jk] = COMBO(jk_combo, KC_UNDS), // _
    [kl] = COMBO(kl_combo, KC_DLR),  // $ ;

    //    ,.
    [cmdt] = COMBO(cmdt_cmb, KC_ASTR), // *
};

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
    case wr:
    case et:
    case sf:
    case ef:
    case se:
    case yi:
      return 50;
  }
  return COMBO_TERM;
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
  // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
  uint16_t key;
  uint8_t  idx = 0;
  while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
    switch (key) {
      case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        return true;
    }
    idx += 1;
  }
  return false;
}

bool combo_should_trigger(uint16_t index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(_CLR)) {
    switch (index) {
      case et:
      case yi:
        return true;
      default:
        return false;
    }
  }

  return true;
}
