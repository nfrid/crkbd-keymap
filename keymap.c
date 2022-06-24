#include QMK_KEYBOARD_H
#include <stdio.h>

enum { _DEF = 0, _CLR, _GM0, _GM1, _MOV, _SYM, _WTF };

enum my_keycodes {
    KC_TGSF = SAFE_RANGE,
    KC_TGSP,
    KC_TGAL,
    KC_TGCT,
    KC_CLRM,
    KC_TGMM,
};

#define M_LS(kc) MT(MOD_LSFT, kc)
#define M_LG(kc) MT(MOD_LGUI, kc)
#define M_LA(kc) MT(MOD_LALT, kc)
#define M_LC(kc) MT(MOD_LCTL, kc)

#define M_RS(kc) MT(MOD_RSFT, kc)
#define M_RG(kc) MT(MOD_RGUI, kc)
#define M_RA(kc) MT(MOD_RALT, kc)
#define M_RC(kc) MT(MOD_RCTL, kc)

/* clang-format off */
#define HRM_LAYOUT_split_3x6_3( \
    k0a, k00, k01, k02, k03, k04,       k05, k06, k07, k08, k09, k0b, \
    k1a, k10, k11, k12, k13, k14,       k15, k16, k17, k18, k19, k1b, \
    k2a, k20, k21, k22, k23, k24,       k25, k26, k27, k28, k29, k2b, \
                     k32, k33, k34,   k35, k36, k37 \
) LAYOUT_split_3x6_3( \
    k0a,       k00,       k01,       k02,       k03, k04,       k05,       k06,       k07,       k08,       k09, k0b, \
    k1a, M_LS(k10), M_LG(k11), M_LA(k12), M_LC(k13), k14,       k15, M_LC(k16), M_LA(k17), M_LG(k18), M_LS(k19), k1b, \
    k2a,       k20,       k21,       k22,       k23, k24,       k25,       k26,       k27,       k28,       k29, k2b, \
                                             k32, k33, k34,   k35, k36, k37 \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = HRM_LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
                                     TT(_CLR), MO(_SYM), KC_SPC,    KC_ENT, MO(_MOV), KC_BSPC
  ),

  [_SYM] = LAYOUT_split_3x6_3(
       KC_F11,   KC_AT, KC_PIPE, KC_MINS,  KC_EQL,  KC_GRV,             XXXXXXX, KC_PLUS, KC_MINS,  KC_EQL, XXXXXXX, XXXXXXX,
     TG(_SYM), KC_EXLM, KC_AMPR, KC_LPRN, KC_RPRN, KC_QUES,             KC_DLR, KC_LCBR, KC_RCBR, KC_UNDS, KC_CIRC, XXXXXXX,
      KC_LCTL,  KC_DLR, KC_PERC, KC_BSLS, KC_HASH, XXXXXXX,             KC_ASTR, KC_LBRC, KC_RBRC, KC_ASTR, KC_BSLS, XXXXXXX,
                                     TT(_CLR), _______, KC_SPC,     KC_ENT, MO(_WTF), KC_DEL
  ),

  [_MOV] = HRM_LAYOUT_split_3x6_3(
       KC_TAB, KC_COMM,    KC_7,    KC_8,    KC_9, KC_TILD,             XXXXXXX, XXXXXXX,  KC_INS, XXXXXXX, XXXXXXX, XXXXXXX,
     TG(_MOV),  KC_TAB,    KC_4,    KC_5,    KC_6,  KC_DOT,             KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
      KC_LSFT,    KC_0,    KC_1,    KC_2,    KC_3, KC_COMM,             KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
                                   TT(_CLR), MO(_WTF), KC_SPC,      KC_ENT, _______, KC_BSPC
  ),

  [_WTF] = LAYOUT_split_3x6_3(
        RESET,  KC_F10,   KC_F7,   KC_F8,   KC_F9,  KC_F20,             KC_TGMM, KC_TGCT, KC_TGAL, KC_TGSP, RGB_HUI, RGB_TOG,
     TG(_WTF),  KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_F21,             KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, KC_TGSF, RGB_MOD,
      KC_CLRM,  KC_F12,   KC_F1,   KC_F2,   KC_F3,  KC_F22,             KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, RGB_VAI, RGB_SPI,
                                     TT(_CLR), _______, KC_SPC,     KC_ENT, _______, KC_BSPC
  ),

  [_CLR] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TG(_GM0),
                                     TT(_CLR), MO(_SYM), KC_SPC,    KC_ENT, MO(_MOV), KC_BSPC
  ),

  [_GM0] = LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, TG(_GM0),
                                     KC_LALT, MO(_GM1), KC_SPC,    KC_ENT, MO(_MOV), KC_BSPC
  ),

  [_GM1] = LAYOUT_split_3x6_3(
       KC_F11,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F1,              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
       KC_F12,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
      KC_LCTL,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
                                     KC_LALT,  _______,  KC_ENT,    KC_ENT, MO(_MOV), KC_BSPC
  ),
};
/* clang-format on */

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TT(_CLR):
        case M_LC(KC_J):
        case M_LA(KC_K):
        case M_LG(KC_L):
        case M_LC(KC_DOWN):
        case M_LA(KC_UP):
        case M_LG(KC_RGHT):
        case M_LS(KC_TAB):
            return false;
        default:
            return true;
    }
}

bool shift_locked = false;
bool super_locked = false;
bool alt_locked   = false;
bool ctrl_locked  = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TGSF:
            if (record->event.pressed) {
                shift_locked = !shift_locked;
                if (shift_locked) {
                    add_mods(MOD_MASK_SHIFT);
                } else {
                    del_mods(MOD_MASK_SHIFT);
                }
            }
            return false;
        case KC_TGSP:
            if (record->event.pressed) {
                super_locked = !super_locked;
                if (super_locked) {
                    add_mods(MOD_MASK_GUI);
                } else {
                    del_mods(MOD_MASK_GUI);
                }
            }
            return false;
        case KC_TGAL:
            if (record->event.pressed) {
                alt_locked = !alt_locked;
                if (alt_locked) {
                    add_mods(MOD_MASK_ALT);
                } else {
                    del_mods(MOD_MASK_ALT);
                }
            }
            return false;
        case KC_TGCT:
            if (record->event.pressed) {
                ctrl_locked = !ctrl_locked;
                if (ctrl_locked) {
                    add_mods(MOD_MASK_CTRL);
                } else {
                    del_mods(MOD_MASK_CTRL);
                }
            }
            return false;
        case KC_CLRM:
            if (record->event.pressed) {
                shift_locked = false;
                super_locked = false;
                alt_locked   = false;
                ctrl_locked  = false;
                clear_mods();
            }
            return false;
        case KC_TGMM:
            if (record->event.pressed) {
                shift_locked = true;
                super_locked = true;
                alt_locked   = true;
                ctrl_locked  = true;
                set_mods(MOD_MASK_CSAG);
            }
            return false;
        default:
            return true;
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }
    return OLED_ROTATION_270;
}

void oled_render_layer_state(void) {
    oled_write_P(PSTR("@:"), false);
    switch (biton32(layer_state)) {
        case _MOV:
            oled_write_P(PSTR("mov"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("sym"), false);
            break;
        case _WTF:
            oled_write_P(PSTR("wtf"), false);
            break;
        case _CLR:
            oled_write_P(PSTR("clr"), true);
            break;
        case _GM0:
            oled_write_P(PSTR("gm0"), false);
            break;
        case _GM1:
            oled_write_P(PSTR("gm1"), false);
            break;
        default:
            oled_write_P(PSTR("def"), false);
            break;
    }
}

// through caps lock indicator
void oled_render_layout(void) {
    oled_write_P(PSTR("lt:"), false);
    if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
        oled_write_P(PSTR("ru"), true);
    } else {
        oled_write_P(PSTR("us"), false);
    }
}

void oled_render_rgbinfo(void) {
    oled_write_P(PSTR("m:"), false);
    if (rgb_matrix_is_enabled()) {
        switch (rgb_matrix_get_mode()) {
            case 2:
                oled_write_P(PSTR("rsm"), false);
                break;
            case 3:
                oled_write_P(PSTR("rsl"), false);
                break;
            case 4:
                oled_write_P(PSTR("rwd"), false);
                break;
            case 5:
                oled_write_P(PSTR("rnx"), false);
                break;
            case 6:
                oled_write_P(PSTR("spl"), false);
                break;
            case 7:
                oled_write_P(PSTR("ssp"), false);
                break;
            default:
                oled_write_P(PSTR("sld"), false);
                break;
        }
    } else {
        oled_write_P(PSTR("off"), true);
    }

    char hsv[16];
    /* clang-format off */
    sprintf(hsv, "h:%3ds:%3dv:%3d",
            rgb_matrix_get_hue(),
            rgb_matrix_get_speed(),
            rgb_matrix_get_val());
    /* clang-format on */
    oled_write(hsv, false);
}

uint8_t mod_state;

void oled_render_mods(void) {
    mod_state = get_mods();
    if (mod_state & MOD_MASK_GUI)
        oled_write_P(PSTR("super"), super_locked);
    else
        oled_write_P(PSTR("     "), false);
    if (mod_state & MOD_MASK_CTRL)
        oled_write_P(PSTR(" ctrl"), ctrl_locked);
    else
        oled_write_P(PSTR("     "), false);
    if (mod_state & MOD_MASK_ALT)
        oled_write_P(PSTR("  alt"), alt_locked);
    else
        oled_write_P(PSTR("     "), false);
    if (mod_state & MOD_MASK_SHIFT)
        oled_write_P(PSTR("shift"), shift_locked);
    else
        oled_write_P(PSTR("     "), false);
}

void oled_render_logo(void) {
    /* clang-format off */
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
    0 };
    /* clang-format on */
    oled_write_P(logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("-----"), false);
        oled_render_layer_state();
        oled_write_P(PSTR("-----"), false);
        oled_render_layout();
        oled_write_P(PSTR("-----"), false);
        oled_render_rgbinfo();
        oled_write_P(PSTR("-----"), false);
        oled_render_mods();
    } else {
        oled_render_logo();
    }

  return false;
}

#if false
RGB get_rgb(HSV clr) {
    clr.s *= s_coef;
    clr.v *= v_coef;
    RGB rgb = hsv_to_rgb(clr);
    return rgb;
}

void set_clr(int index, HSV clr) {
    RGB rgb = get_rgb(clr);
    rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}
void set_clr_all(HSV clr) {
    RGB rgb = get_rgb(clr);
    rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}

void loop_clrset(int *mask, HSV clr) {
    for (; *mask != -1; ++mask) {
        set_clr(*mask, clr);
    }
}

/* clang-format off */
/* 24, 23, 18, 17, 10, 9,           36, 37, 44, 45, 50, 51, \ */
/* 25, 22, 19, 16, 11, 8,           35, 38, 43, 46, 49, 52, \ */
/* 26, 21, 20, 15, 12, 7,           34, 39, 42, 47, 48, 53, \ */
/*                 14, 13, 6, 33, 40, 41, \ */
/*      2,      1,      0,           27,      28,      29, \ */
/*      3,      4,      5,           32,      31,      30 \ */
enum {
L_BL1, L_BL2, L_BL3, L_BL4, L_BL5, L_BL6,
L_LF, L_B, L_G, L_T, L_R, L_F, L_V, L_LM, L_LN,
L_C, L_D, L_E, L_W, L_S, L_X, L_Z, L_A, L_Q, L_TAB, L_ESC, L_SFT,
L_BR1, L_BR2, L_BR3, L_BR4, L_BR5, L_BR6,
L_RF, L_N, L_H, L_Y, L_U, L_J, L_M, L_RM, L_RN,
L_COM, L_K, L_I, L_O, L_L, L_DOT, L_SL, L_COL, L_P, L_OB, L_QU, L_CB
};
/* clang-format on */

/* enum { _DEF, _MOV, _SYM, _CLR, _WTF }; */
/* clang-format off */
int L_BL[] = {
    L_BL1, L_BL2, L_BL3, L_BL4, L_BL5, L_BL6,
    -1
};
int R_BL[] = {
    L_BR1, L_BR2, L_BR3, L_BR4, L_BR5, L_BR6,
    -1
};
int L_HOME[] = {L_A, L_S, L_D, L_F, -1};
int R_HOME[] = {L_J, L_K, L_L, L_COL, -1};
int L_LET[]  = {
    L_Q, L_W, L_E, L_R, L_T,
    L_A, L_S, L_D, L_F, L_G,
    L_Z, L_X, L_C, L_V, L_B,
    -1
};

int R_LET[]  = {
    L_Y, L_U, L_I, L_O, L_P, L_OB,
    L_H, L_J, L_K, L_L, L_COL, L_QU,
    L_N, L_M, L_COM, L_DOT, L_SL, L_CB,
    -1
};
int NUMPAD[] = {
    L_W, L_E, L_R,
    L_S, L_D, L_F,
    L_Z, L_X, L_C, L_V,
    -1
};
/* clang-format on */

HSV black = {0, 0, 0};
HSV white = {0, 0, 127};

HSV red    = {0, 255, 127};
HSV orange = {21, 255, 127};
HSV yellow = {43, 255, 127};
HSV lgreen = {64, 255, 127};
HSV green  = {85, 255, 127};
HSV bgreen = {106, 255, 127};
HSV cyan   = {127, 255, 127};
HSV azure  = {148, 255, 127};
HSV blue   = {169, 255, 127};
HSV blue2  = {180, 255, 127};
HSV purple = {201, 255, 127};
HSV pink   = {222, 255, 127};

#    define DEF_S_COEF 1
#    define DEF_V_COEF .5

#    define C_BASE black

#    define C_PRIM cyan
#    define C_PRIM2 purple
#    define C_SEC purple
#    define C_SEC2 azure

#    define C_MOD yellow
#    define C_MOD_T orange

#    define C_STICKY green
#    define C_STICKY_T orange

#    define C_ESC lgreen
#    define C_ESC_T orange

#    define C_THUMB white

#    define C_KILL red

/* #    define USE_BL */

void rgb_matrix_indicators_user(void) {
    set_clr_all(C_BASE);

    loop_clrset(L_LET, C_PRIM);
    loop_clrset(L_HOME, C_SEC);

    loop_clrset(R_LET, C_SEC);
    loop_clrset(R_HOME, C_PRIM);

#    ifdef USE_BL
    loop_clrset(L_BL, C_PRIM2);
    loop_clrset(R_BL, C_SEC2);
#    endif

    set_clr(L_LF, C_THUMB);
    set_clr(L_RF, C_THUMB);

    set_clr(L_LM, C_MOD);
    set_clr(L_RM, C_MOD);

    set_clr(L_LN, C_STICKY);
    set_clr(L_RN, C_KILL);

    set_clr(L_ESC, C_ESC_T);

    set_clr(L_SFT, shift_locked ? C_STICKY_T : C_PRIM2);
    set_clr(L_TAB, C_PRIM2);

    switch (biton32(layer_state)) {
        default:
            v_coef = DEF_V_COEF;
            set_clr(L_ESC, C_ESC);
            break;

        case _SYM:
            set_clr(L_LM, C_MOD_T);
            break;

        case _MOV:
            set_clr(L_RM, C_MOD_T);
            loop_clrset(NUMPAD, C_PRIM2);
            break;

        case _WTF:
            set_clr(L_LM, C_MOD_T);
            set_clr(L_RM, C_MOD_T);
            break;

        case _CLR:
            loop_clrset(L_HOME, C_PRIM);
            loop_clrset(R_HOME, C_SEC);
            set_clr(L_LN, C_STICKY_T);
            break;
    }
}
#endif
