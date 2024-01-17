#include "homerow.h"

#undef COMBO_TERM
#define COMBO_TERM 1
#define EXTRA_SHORT_COMBOS

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM et_combo[] = {KC_E, KC_T, COMBO_END};
const uint16_t PROGMEM wr_combo[] = {KC_W, KC_R, COMBO_END};

const uint16_t PROGMEM xc_combo[] = {KC_X, KC_C, COMBO_END};

const uint16_t PROGMEM io_combo[] = {KC_O, KC_I, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM yi_combo[] = {KC_Y, KC_I, COMBO_END};

const uint16_t PROGMEM sf_combo[] = {M_LG(KC_S), M_LC(KC_F), COMBO_END};
const uint16_t PROGMEM ef_combo[] = {KC_E, M_LC(KC_F), COMBO_END};
const uint16_t PROGMEM se_combo[] = {M_LG(KC_S), KC_E, COMBO_END};

const uint16_t PROGMEM cmdt_cmb[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    /*                           en ru */
    COMBO(we_combo, KC_EXLM), // !
    COMBO(er_combo, KC_EQL),  // =
    COMBO(et_combo, KC_GRV),  // ` ё
    COMBO(wr_combo, KC_AT),   // @ "

    COMBO(xc_combo, KC_BSLS), // backslash

    COMBO(io_combo, KC_MINS), // -
    COMBO(ui_combo, KC_CIRC), // ^ :
    COMBO(yi_combo, KC_LBRC), // [ х

    COMBO(sf_combo, KC_QUES), // ? ,
    COMBO(ef_combo, KC_AMPR), // & ?
    COMBO(se_combo, KC_PIPE), // | /

    //    ,.
    COMBO(cmdt_cmb, KC_ASTR), // *
};
