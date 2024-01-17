#include QMK_KEYBOARD_H
#include <stdio.h>

#include "layers.h"
#include "homerow.h"

#ifdef ACHORDION
#  include "features/achordion.h"
#endif
#ifdef COMBOS
#  include "combos.c"
#endif

enum my_keycodes {
  KC_TGSF = SAFE_RANGE,
  KC_TGSP,
  KC_TGAL,
  KC_TGCT,
  KC_TGMM,
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = HRM_LAYOUT_split_3x6_3(
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC,
       KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
OSM(MOD_LSFT),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RBRC,
                                     TT(_CLR), MO(_SYM), KC_SPC,    KC_ENT, LT(_MOV, KC_BSPC), OSM(MOD_LSFT)
  ),

  [_SYM] = LAYOUT_split_3x6_3(
       KC_F11,   KC_AT, KC_PIPE,   KC_AT,  KC_EQL,  KC_GRV,             XXXXXXX,  KC_PLUS, KC_MINS,  KC_EQL, XXXXXXX, XXXXXXX,
     TG(_SYM), KC_EXLM, KC_AMPR, KC_LPRN, KC_RPRN, KC_QUES,             KC_UNDS,  KC_LCBR, KC_RCBR,  KC_DLR, KC_CIRC, XXXXXXX,
      KC_LCTL,  KC_DLR, KC_PERC, KC_BSLS, KC_HASH, XXXXXXX,             KC_ASTR,  KC_LBRC, KC_RBRC, KC_ASTR, KC_BSLS, XXXXXXX,
                                     TT(_CLR), _______, KC_SPC,    KC_SCROLL_LOCK, LT(_WTF, KC_DEL), OSM(MOD_LSFT)
  ),

  [_MOV] = HRM_LAYOUT_split_3x6_3(
       KC_TAB, KC_COMM,    KC_7,    KC_8,    KC_9,  KC_TAB,             KC_COPY, XXXXXXX,  KC_INS, XXXXXXX, KC_PSTE, XXXXXXX,
     TG(_MOV),  KC_TAB,    KC_4,    KC_5,    KC_6,  KC_DOT,             KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
      KC_LSFT,    KC_0,    KC_1,    KC_2,    KC_3, KC_COMM,             KC_HOME, KC_PGDN, KC_PGUP,  KC_END, XXXXXXX, XXXXXXX,
                                  TT(_CLR), MO(_WTF), CW_TOGG,      KC_ENT, _______, KC_BSPC
  ),

  [_WTF] = LAYOUT_split_3x6_3(
       QK_RBT,  KC_F10,   KC_F7,   KC_F8,   KC_F9,  KC_F20,             KC_TGMM, KC_TGCT, KC_TGAL, KC_TGSP, RGB_HUI, RGB_TOG,
     TG(_WTF),  KC_F11,   KC_F4,   KC_F5,   KC_F6,  KC_F21,             KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR, KC_TGSF, RGB_MOD,
      KC_CAPS,  KC_F12,   KC_F1,   KC_F2,   KC_F3,  KC_F22,             KC_MSTP, KC_MPRV, KC_MNXT, KC_MPLY, RGB_VAI, RGB_SPI,
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

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t* record) {
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

#ifdef ACHORDION
void matrix_scan_user(void) {
  achordion_task();
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef ACHORDION
  if (!process_achordion(keycode, record)) {
    return false;
  }
#endif

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
    case KC_TGMM:
      if (record->event.pressed) {
        if (!get_mods()) {
          shift_locked = true;
          super_locked = true;
          alt_locked   = true;
          ctrl_locked  = true;
          set_mods(MOD_MASK_CSAG);
        } else {
          shift_locked = false;
          super_locked = false;
          alt_locked   = false;
          ctrl_locked  = false;
          clear_mods();
        }
      }
      return false;
    default:
      return true;
  }
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
    case KC_COMM:
    case KC_DOT:
      add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_MINS:
    case KC_UNDS:
      return true;

    default:
      return false; // Deactivate Caps Word.
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
  if (host_keyboard_led_state().num_lock) {
    oled_write_P(PSTR("ru"), true);
  } else {
    oled_write_P(PSTR("us"), false);
  }
}

void oled_render_rgbinfo(void) {
  char hsv[11];
  /* clang-format off */
    sprintf(hsv, "s:%3dv:%3d",
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
  if (host_keyboard_led_state().caps_lock)
    oled_write_P(PSTR(" caps"), true);
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

HSV  c_default = {120, 255, 255};
HSV  c_mov     = {90, 255, 255};
HSV  c_sym     = {160, 255, 255};
HSV  c_wtf     = {220, 255, 255};
HSV  c_clr     = {0, 0, 255};
HSV  c_gm0     = {0, 255, 255};
HSV  c_gm1     = {30, 255, 255};
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  HSV hsv;

  switch (biton32(layer_state)) {
    case _MOV:
      hsv = c_mov;
      break;
    case _SYM:
      hsv = c_sym;
      break;
    case _WTF:
      hsv = c_wtf;
      break;
    case _CLR:
      hsv = c_clr;
      break;
    case _GM0:
      hsv = c_gm0;
      break;
    case _GM1:
      hsv = c_gm1;
      break;
    default:
      hsv = c_default;
      break;
  }

  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }
  // RGB rgb = hsv_to_rgb(hsv);
  rgb_matrix_sethsv(hsv.h, hsv.s, hsv.v);

  // for (uint8_t i = led_min; i <= led_max; i++) {
  //   if (HAS_FLAGS(g_led_config.flags[i], 0x01)) { // 0x01 ==
  //   LED_FLAG_MODIFIER
  //     rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  //   }
  // }
  return false;
}
