/* Copyright 2021 iuchim
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
#include <stdio.h>

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

// keycode aliases
#define TP_SPC    LT(_LOWER, KC_SPC)
#define TP_ENT    LT(_RAISE, KC_ENT)
#define MO_AJST   MO(_ADJUST)
#define TP_QUOT   RCTL_T(KC_QUOT)
#define TP_BSLS   RSFT_T(KC_BSLS)
#define TP_PDOT   LGUI_T(KC_PDOT)
#define TP_KP_0   LALT_T(KC_KP_0)

// keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
      KC_ESC , KC_GRV , KC_PSCR,                                                       KC_MINS, KC_EQL , KC_BSPC,
      KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC,
      KC_LCTL, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, TP_QUOT,
      KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, TP_BSLS,
      /*            */  KC_LGUI, KC_LALT, TP_SPC , TP_ENT , TP_ENT , TP_SPC , KC_RALT, MO_AJST
      ),

  [_LOWER] = LAYOUT(
      KC_BSPC, KC_TILD, _______,                                                       KC_UNDS, KC_PLUS, _______,
      _______, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_RBRC,
      _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
      /*            */  _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_RAISE] = LAYOUT(
      KC_DEL , KC_F11 , KC_F12 ,                                                       _______, KC_INS , KC_DEL ,
      _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
      _______, KC_PGUP, KC_HOME, KC_UP  , KC_END , _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_PGUP, _______,
      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT,KC_LANG2,KC_LANG1, _______, KC_HOME, KC_END , KC_PGDN, _______,
      /*            */  _______, _______, _______, _______, _______, _______, _______, _______
      ),

  [_ADJUST] = LAYOUT(
      RESET  , XXXXXXX, XXXXXXX,                                                      RGB_RMOD, RGB_MOD, RGB_TOG,
      XXXXXXX, XXXXXXX, KC_KP_7, KC_KP_8, KC_KP_9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAI, RGB_SAI, RGB_HUI,
      XXXXXXX, XXXXXXX, KC_KP_4, KC_KP_5, KC_KP_6, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_VAD, RGB_SAD, RGB_HUD,
      XXXXXXX, XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      /*            */  TP_PDOT, TP_KP_0, KC_SPC , KC_PENT, _______, _______, _______, _______
      )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

#ifdef OLED_DRIVER_ENABLE
static void render_logo(void) {
  static const char PROGMEM qmk_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
  };

  oled_write_P(qmk_logo, false);
}

static void render_status(void) {
  oled_write_P(PSTR("LAYER:"), false);
  switch (get_highest_layer(layer_state)) {
    case _BASE:
      oled_write_ln_P(PSTR("DEFAULT"), false);
      break;
    case _LOWER:
      oled_write_ln_P(PSTR("LOWER"), false);
      break;
    case _RAISE:
      oled_write_ln_P(PSTR("RAISE"), false);
      break;
    case _ADJUST:
      oled_write_ln_P(PSTR("ADJUST"), false);
      break;
    default:
      oled_write_ln_P(PSTR("???"), false);
      break;
  }
#ifdef RGBLIGHT_ENABLE
  char buf[40];
  snprintf(buf, sizeof(buf), "H:%3d,S:%3d,V:%3d",
      rgblight_get_hue(), rgblight_get_sat(), rgblight_get_val());
  oled_write_ln(buf, false);
#endif
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
}
#endif
