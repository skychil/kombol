/*
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

#include "keymap.h"


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
/* /1* static bool tap_dance_active = false; *1/ */

/* // track the current tap dance state */
/* int cur_dance (qk_tap_dance_state_t *state) { */
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

/* void CACCCV_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   td_state = cur_dance(state); */
/*   switch (td_state) { */
/*     case SINGLE_HOLD: tap_code16(C(KC_A)); break; */
/*     case SINGLE_TAP: tap_code16(C(KC_C)); break; */
/*     case DOUBLE_TAP: tap_code16(C(KC_V)); break; */
/*     default: break; */
/*   } */
/* }; */

// The following behavior is implemented much simpler as a combo:
/* // Double tap dot for ". <osm shift>" */
/* // This quickly ends a sentence and begins another. */
/* void dot_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   if (state->count == 2) { */
/*     if (get_mods() & MOD_MASK_SHIFT) { // If Shift is active */
/*       SEND_STRING(">"); */
/*     } else { */
/*       SEND_STRING(". "); */
/*       set_oneshot_mods(MOD_LSFT | get_oneshot_mods()); */
/*     } */
/*   } else { */
/*     for (uint8_t i = state->count; i > 0; i--) { */
/*       tap_code16(KC_DOT); */
/*     } */
/*   } */
/* }; */

// Working code for having one key control two layers:
// One shot layer 1 on tap, layer 2 on hold
// Too mentally taxing to actually use
/* void SYM_finished(qk_tap_dance_state_t *state, void *user_data) { */
/*   td_state = cur_dance(state); */
/*   switch (td_state) { */
/*     case SINGLE_TAP: */
/*       if (tap_dance_active) { */
/*         reset_oneshot_layer(); */
/*         tap_dance_active = false; */
/*       } else { */
/*         set_oneshot_layer(_SYM, ONESHOT_START); */
/*         tap_dance_active = true; */
/*       } */
/*       break; */
/*     case SINGLE_HOLD: */
/*       layer_on(_NUM); */
/*       break; */
/*     case DOUBLE_HOLD: */
/*       layer_on(_SYM); */
/*       break; */
/*     default: break; */
/*   } */
/* }; */
/* void SYM_reset(qk_tap_dance_state_t *state, void *user_data) { */
/*   switch(td_state) { */
/*     case SINGLE_TAP: */
/*       clear_oneshot_layer_state(ONESHOT_PRESSED); */
/*       tap_dance_active = false; */
/*       break; */
/*     case SINGLE_HOLD: */
/*       layer_off(_NUM); */
/*       break; */
/*     case DOUBLE_HOLD: */
/*       layer_off(_SYM); */
/*       break; */
/*     default: break; */
/*   } */
/* } */
/* void tap_dance_process_keycode(uint16_t keycode) { */
/*   if (td_state == SINGLE_TAP && keycode != TD_SYM) { */
/*     tap_dance_active = false; */
/*   } */
/* } */

/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*   [CACCCV_TD] = ACTION_TAP_DANCE_FN(CACCCV_finished) */
/*   /1* [DOT_TD] = ACTION_TAP_DANCE_FN(dot_finished), *1/ */
/*   /1* [SYM_TD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, SYM_finished, SYM_reset), *1/ */
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
      XXXXXXX, KC_PGDN, KC_UP, KC_PGUP, XXXXXXX, _______,

      _______, _______, _______, _______, _______, _______,
      XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______,
      XXXXXXX, XXXXXXX, KC_LT, KC_GT, XXXXXXX, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_NUM] = LAYOUT(
      _______, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, // Xf86Launch 5-9
      XXXXXXX, KC_7, KC_8, KC_9, XXXXXXX, _______,

      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), XXXXXXX,
      KC_PLUS, KC_4, KC_5, KC_6, KC_0, _______,

      _______, G(KC_8), G(KC_7), G(KC_6), G(KC_5), XXXXXXX,
      _______, _______, _______, _______,
      KC_MINS, KC_1, KC_2, KC_3, KC_DOT, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_F] = LAYOUT(
      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_PSCR,

      KC_CLCK, XXXXXXX, DM_REC1, DM_RSTP, DM_PLY1, XXXXXXX,
      XXXXXXX, KC_F4, KC_F5, KC_F6, KC_F11, KC_SLCK,

      _______, XXXXXXX, DM_REC2, DM_RSTP, DM_PLY2, XXXXXXX,
      _______, _______, _______, _______,
      XXXXXXX, KC_F1, KC_F2, KC_F3, KC_F12, KC_PAUSE,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_M] = LAYOUT(
      _______, XXXXXXX, KC_F23, KC_F22, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_WH_D, KC_MS_U, KC_WH_U, XXXXXXX, _______,

      XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX,
      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, _______,

      RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG, RGB_MOD, _______,
      _______, _______, _______, _______,
      XXXXXXX, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______,

      _______, _______, _______, _______, _______,
      _______, KC_BTN1, KC_BTN2, KC_BTN3, _______
      ),
  [_VIM] = LAYOUT(
      _______, KC_Q, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      )
};

/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*   switch (keycode) { */
/*     case TD_CACCCV: return 150; */
/*     default: return TAPPING_TERM; */
/*   } */
/* } */

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
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
      // Undo / Redo (Ctrl Shift Z)
      if (clockwise) {
        tap_code16(C(S(KC_Z)));
      } else {
        tap_code16(C(KC_Z));
      }
    } else if (IS_LAYER_ON(_F)) {
      // Undo / Redo (Keycodes)
      if (clockwise) {
        tap_code(KC_UNDO);
      } else {
        tap_code(KC_AGAIN);
      }
    } else {
      // Undo / Redo (Ctrl Y)
      if (clockwise) {
        tap_code16(C(KC_Y));
      } else {
        tap_code16(C(KC_Z));
      }
    }
  }
  else if (index == 1) { // Right
    // Inverting 'clockwise' to be able to flash both sides with the same file
    if (IS_LAYER_ON(_NUM)) {
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
}
#endif


#ifdef RGBLIGHT_ENABLE
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
  {0, 6, HSV_RED},
  {9, 2, HSV_RED},
  {14, 6, HSV_RED}
);
const rgblight_segment_t PROGMEM my_VIM_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 6, HSV_GREEN},
  {9, 2, HSV_GREEN},
  {14, 6, HSV_GREEN}
);
/* const rgblight_segment_t PROGMEM my_NAV_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*   {10, 1, HSV_BLUE}, */
/*   {14, 6, HSV_BLUE} */
/* ); */
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
    my_M_layer,
    my_VIM_layer
    /* my_NAV_layer, */
    /* my_NUM_layer, */
    );

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers; // Load layer definitions from memory
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(2, layer_state_cmp(state, _F));
  rgblight_set_layer_state(3, layer_state_cmp(state, _M));
  rgblight_set_layer_state(4, layer_state_cmp(state, _VIM));
  return state;
}

// Track Capslock state
bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(1, led_state.caps_lock);
  return true;
}

// Track Macro Recording state
void dynamic_macro_record_start_user(void) {
  rgblight_set_layer_state(0, true);
}
void dynamic_macro_record_end_user(int8_t direction) {
  rgblight_set_layer_state(0, false);
}
// Blink when a macro is played back
void dynamic_macro_play_user(int8_t direction) {
  rgblight_set_layer_state(0, true);
  wait_ms(1000);
  rgblight_set_layer_state(0, false);
}

#endif


// Define map for swap hands (mirror sides)
/* const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = { */
/*   {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}, {7, 4}}, */
/*   {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}, {7, 5}}, */
/*   {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}, {7, 6}}, */
/*   {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}, {7, 7}}, */
/*   {{0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}}, */
/*   {{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}}, */
/*   {{0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}}, */
/*   {{0, 3}, {1, 3}, {2, 3}, {3, 3}, {4, 3}, {5, 3}, {6, 3}, {7, 3}} */
/* }; */
