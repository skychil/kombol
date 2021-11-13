/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "keymap.h"

enum custom_keycodes {
  VIM_C = SAFE_RANGE,
  VIM_D,
  VIM_V,
};

// Vim commands for non-vim editors
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    /* Alterative format: SEND_STRING(SS_LCTL("c")); */
    case VIM_C:
      if (!record->event.pressed) break;
      register_code(KC_LSFT);
      tap_code(KC_END);
      unregister_code(KC_LSFT);
      tap_code(KC_DEL);
      break;
    /* Duplicate */
    case VIM_D:
      if (!record->event.pressed) break;
      tap_code(KC_HOME);
      register_code(KC_LSFT);
      tap_code(KC_END);
      unregister_code(KC_LSFT);
      register_code(KC_LCTL);
      tap_code(KC_C);
      unregister_code(KC_LCTL);
      tap_code(KC_RIGHT);

      tap_code(KC_ENTER);
      register_code(KC_LCTL);
      tap_code(KC_V);
      unregister_code(KC_LCTL);
      break;
    case VIM_V:
      if (!record->event.pressed) break;
      tap_code(KC_HOME);
      register_code(KC_LSFT);
      tap_code(KC_END);
      unregister_code(KC_LSFT);
      break;
  }
  return true;
};

/* // Tap dance states */
/* typedef enum { */
/*   SINGLE_TAP, */
/*   SINGLE_HOLD, */
/*   DOUBLE_TAP, */
/*   DOUBLE_HOLD, */
/*   TWO_SINGLE_TAPS, */
/*   TOO_MANY_TAPS */
/* } td_state_t; */

/* // create a global instance of the tapdance state type */
/* static td_state_t td_state; */

/* // track the current tap dance state */
/* int cur_tapdance (qk_tap_dance_state_t *state) { */
/*   switch (state->count) { */
/*     case 1: */
/*       if (state->interrupted || !state->pressed) { */
/*         return SINGLE_TAP; */
/*       } else { */
/*         return SINGLE_HOLD; */
/*       } */
/*       break; */
/*     case 2: */
/*       if (state->interrupted) return TWO_SINGLE_TAPS; // only for alphas, like o in loop */
/*       else if (state->pressed) return DOUBLE_HOLD; */
/*       else return DOUBLE_TAP; */
/*       break; */
/*     default: */
/*       return TOO_MANY_TAPS; */
/*   } */
/* }; */

/* void dynamicMacro1(qk_tap_dance_state_t *state, void *user_data) { */
/*   td_state = cur_tapdance(state); */
/*   keyrecord_t kr; */
/*   uint16_t action; */

/*   switch (td_state) { */
/*     case SINGLE_HOLD: */
/*       action = DYN_REC_START1; */
/*       kr.event.pressed = false; */
/*       break; */
/*     case SINGLE_TAP: */
/*       action = DYN_MACRO_PLAY1; */
/*       kr.event.pressed = false; */
/*       break; */
/*     case DOUBLE_TAP: */
/*       action = DYN_REC_STOP; */
/*       kr.event.pressed = true; */
/*       break; */
/*     default: break; */
/*   } */
/*   process_dynamic_macro( action, &kr ); */
/* } */

/* void dynamicMacro2(qk_tap_dance_state_t *state, void *user_data) { */
/*   td_state = cur_tapdance(state); */
/*   keyrecord_t kr; */
/*   uint16_t action; */

/*   switch (td_state) { */
/*     case SINGLE_HOLD: */
/*       action = DYN_REC_START2; */
/*       kr.event.pressed = false; */
/*       break; */
/*     case SINGLE_TAP: */
/*       action = DYN_MACRO_PLAY2; */
/*       kr.event.pressed = false; */
/*       break; */
/*     case DOUBLE_TAP: */
/*       action = DYN_REC_STOP; */
/*       kr.event.pressed = true; */
/*       break; */
/*     default: break; */
/*   } */
/*   process_dynamic_macro( action, &kr ); */
/* } */

/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*   [DMACRO1_TD] = ACTION_TAP_DANCE_FN(dynamicMacro1), */
/*   [DMACRO2_TD] = ACTION_TAP_DANCE_FN(dynamicMacro2) */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11,
  // L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23,
  // L24, L25, L26, L27, L28, L29, L30, L31, R32, R33, R34, R35, R36, R37, R38, R39,
  //                L40, L41, L42, L43, L44, R45, R46, R47, R48, R49
  //
  // +-----+-----+-----+-----+-----+-----+                          +-----+-----+-----+-----+-----+-----+
  // | LOH |  Q  |  W  |  F  |  P  |  B  |                          |  J  |  L  |  U  |  Y  |  ;  | ROH |
  // +-----+-----+-----+-----+-----+-----+                          +-----+-----+-----+-----+-----+-----+
  // | LOM |  A  |  R  |  S  |  T  |  G  |                          |  M  |  N  |  E  |  I  |  O  | ROM |
  // +-----+-----+-----+-----+-----+-----+-----+-----+  +-----+-----+-----+-----+-----+-----+-----+-----+
  // | LOL |  Z  |  X  |  C  |  D  |  V  | LT5 | LT6 |  | RT6 | RT5 |  K  |  H  |  ,  |  .  |  /  | ROL |
  // +-----+-----+-----+-----+-----+-----+-----+-----+  +-----+-----+-----+-----+-----+-----+-----+-----+
  //                   | LE  | LT1 | LT2 | LT3 | LT4 |  | RT4 | RT3 | RT2 | RT1 |  RE |
  //                   +-----+-----+-----+-----+-----+  +-----+-----+-----+-----+-----+

  [_COLEMAK_DHM] = LAYOUT(
      MY_LOH, MY_Q, MY_W, MY_F, MY_P, MY_B,
      MY_J, MY_L, MY_U, MY_Y, MY_SCLN, MY_ROH,

      MY_LOM, MY_A, MY_R, MY_S, MY_T, MY_G,
      MY_M, MY_N, MY_E, MY_I, MY_O, MY_ROM,

      MY_LOL, MY_Z, MY_X, MY_C, MY_D, MY_V,
      MY_LT5, MY_LT6, MY_RT6, MY_RT5,
      MY_K, MY_H, MY_COMMA, MY_DOT, MY_SLASH, MY_ROL,

      MY_LE, MY_LT1, MY_LT2, MY_LT3, MY_LT4,
      MY_RT4, MY_RT3, MY_RT2, MY_RT1, MY_RE
      ),
  [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      XXXXXXX, KC_HOME, KC_UP, KC_END, XXXXXXX, _______,

      _______, _______, _______, _______, _______, _______,
      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PSCR, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______,
      XXXXXXX, XXXXXXX, KC_LT, KC_GT, XXXXXXX, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      KC_PLUS, KC_7, KC_8, KC_9, _______, _______,

      _______, _______, _______, _______, _______, _______,
      KC_DOT, KC_4, KC_5, KC_6, KC_0, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______,
      KC_MINS, KC_1, KC_2, KC_3, _______, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_WM] = LAYOUT(
      _______, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, // Xf86Launch5-9 (Frequent App Lauchers)
      _______, _______, _______, _______, _______, _______,

      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), XXXXXXX,
      _______, _______, _______, _______, _______, _______,

      XXXXXXX, XXXXXXX, XXXXXXX, VIM_C, VIM_D, VIM_V,
      _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_F] = LAYOUT(
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

      KC_CLCK, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,

      _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      _______, _______, _______, _______,
      XXXXXXX, KC_F11, KC_F12, XXXXXXX, _______, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_M] = LAYOUT(
      _______, XXXXXXX, KC_F23, KC_F22, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX, _______,

      XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX,
      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, _______,

      _______, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD, _______,
      _______, _______, _______, _______,
      XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, XXXXXXX, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
};


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { // Left
    if (IS_LAYER_ON(_NAV)) {
      // Tab Forward / Back
      if (clockwise) {
        tap_code(KC_TAB);
      } else {
        tap_code16(S(KC_TAB));
      }
    } else if (IS_LAYER_ON(_M)) {
      // Volume
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    } else if (IS_LAYER_ON(_NUM)) {
      // Undo (Ctrl Z) / Redo (Ctrl Shift Z)
      if (clockwise) {
        tap_code16(C(S(KC_Z)));
      } else {
        tap_code16(C(KC_Z));
      }
    } else {
      // Undo (Ctrl Z) / Redo (Ctrl Y)
      if (clockwise) {
        tap_code16(C(KC_Y));
      } else {
        tap_code16(C(KC_Z));
      }
    }
  }
  else if (index == 1) { // Right
    // Inverting 'clockwise' to be able to flash both sides with the same file
    if (IS_LAYER_ON(_WM)) {
      // Zoom
      if (clockwise) {
        tap_code16(C(KC_EQUAL));
      } else {
        tap_code16(C(KC_MINS));
      }
    } else if (IS_LAYER_ON(_M)) {
      // Volume
      if (clockwise) {
        tap_code(KC_VOLU);
      } else {
        tap_code(KC_VOLD);
      }
    } else {
      // Pg Down / Up
      if (clockwise) {
        tap_code(KC_PGDN);
      } else {
        tap_code(KC_PGUP);
      }
    }
  }
  return true;
}
#endif


#ifdef RGBLIGHT_LAYERS
// HSV_WHITE 0, 0, 255
// HSV_RED 0, 255, 255
// HSV_CORAL 11, 176, 255
// HSV_ORANGE 28, 255, 255
// HSV_GOLDENROD 30, 218, 218
// HSV_GOLD 36, 255, 255
// HSV_YELLOW 43, 255, 255
// HSV_CHARTREUSE 64, 255, 255
// HSV_GREEN 85, 255, 255
// HSV_SPRINGGREEN 106, 255, 255
// HSV_TURQUOISE 123, 90, 112
// HSV_TEAL 128, 255, 128
// HSV_CYAN 128, 255, 255
// HSV_AZURE 132, 102, 255
// HSV_BLUE 170, 255, 255
// HSV_PURPLE 191, 255, 255
// HSV_MAGENTA 213, 255, 255
// HSV_PINK 234, 128, 255

// {5, 2, HSV_AZURE},  // Starting with LED 6, set 2 LEDs to Azure

const rgblight_segment_t PROGMEM my_macrorec_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 10, HSV_PINK},
  {10, 10, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 10, HSV_ORANGE},
  {10, 10, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_F_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 6, HSV_CYAN},
  {9, 2, HSV_CYAN},
  {14, 6, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_M_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 6, HSV_PURPLE},
  {9, 2, HSV_PURPLE},
  {14, 6, HSV_PURPLE}
);

// Define up to 8 layers. Later layers take precedence.
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_macrorec_layer, // 0
    my_capslock_layer,
    my_F_layer,
    my_M_layer
    );

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers; // Load layer definitions from memory
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(2, layer_state_cmp(state, _F));
  rgblight_set_layer_state(3, layer_state_cmp(state, _M));
  return state;
}

// Track Capslock state
bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(1, led_state.caps_lock);
  return true;
}

// Track Macro Recording state, this didn't work due to qmk bug
/* void dynamic_macro_record_start_user(void) { */
/*   rgblight_set_layer_state(0, true); */
/* } */
/* void dynamic_macro_record_end_user(int8_t direction) { */
/*   rgblight_set_layer_state(0, false); */
/* } */
// Blink when a macro is played back
/* void dynamic_macro_play_user(int8_t direction) { */
/*   rgblight_set_layer_state(0, true); */
/*   wait_ms(1000); */
/*   rgblight_set_layer_state(0, false); */
/* } */

#endif
