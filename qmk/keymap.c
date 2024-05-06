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

// Lower Thumb keys
#define MY_LE RGB_TOG
#define MY_LT1 KC_LCTL
#define MY_LT2 LSFT_T(KC_SPACE)
#define MY_LT3 MO(_W)
#define MY_LT4 MO(_F)
#define MY_RT4 MO(_M)
#define MY_RT3 MO(_NUM)
#define MY_RT2 RSFT_T(KC_ENTER)
#define MY_RT1 MO(_NAV)
#define MY_RE KC_MUTE

// Upper Thumb keys
#define MY_LT5 DM_REC1
#define MY_LT6 DM_RSTP
#define MY_RT6 DM_PLY1
#define MY_RT5 DM_PLY1

// Outer Edge Keys
#define MY_LOH KC_TAB
#define MY_LOM KC_ESC
#define MY_LOL C(KC_LALT)

#define MY_ROH KC_DEL
#define MY_ROM KC_BSPC
#define MY_ROL LCTL_T(KC_INS)

// Alpha keys
#define MY_A LGUI_T(KC_A)
#define MY_R KC_R
#define MY_S KC_S
#define MY_T KC_T
#define MY_G KC_G
#define MY_M KC_M
#define MY_N KC_N
#define MY_E KC_E
#define MY_I KC_I
#define MY_O KC_O

#define MY_Z LALT_T(KC_Z)
#define MY_X KC_X
#define MY_C KC_C
#define MY_D KC_D
#define MY_V KC_V
#define MY_K KC_K
#define MY_H KC_H
#define MY_COMMA KC_COMMA
#define MY_DOT KC_DOT
#define MY_SLASH LALT_T(KC_SLASH)

#define MY_Q KC_Q
#define MY_W KC_W
#define MY_F KC_F
#define MY_P KC_P
#define MY_B KC_B
#define MY_J KC_J
#define MY_L KC_L
#define MY_U KC_U
#define MY_Y KC_Y
#define MY_SCLN KC_SCLN

enum layer_names {
  _COLEMAK_DHM = 0,
  _NAV, // Up Down Left Right Home End PrintScr
  _NUM, // Number Pad 0-9 . + -
  _W, // Window management, app launchers, capslock
  _F, // F1-F12
  _M, // Media Control, Dynamic Macros, Mouse Keys
};

enum custom_keycodes {
  CKC_BOTHBRC = SAFE_RANGE,
  CKC_BOTHGRAVE,
  CKC_BOTHCBR,
  CKC_BOTHPAREN,
  CKC_BOTHDQUO,
  CKC_BOTHQUOTE,
  CKC_BOTHANGLE,
  CKC_MYLASTNAME,
  CKC_MYUSERNAME,
  CKC_MYWORKEMAIL,
  CKC_MYPLOVER
  /* CKC_VIM_C, */
  /* CKC_VIM_D, */
  /* CKC_VIM_V, */
};

// Pull in basic combos (depends on CKC's and MY_'s)
#include "combos.h" // define combos from combos.def
#include "personalplover.h"

// Helper function for complex combos
// Send second arg if shift is held, else send the first
void shift_send_string(const char *normal, const char *shifted) {
  uint8_t mod_state = get_mods();
  if (mod_state & MOD_MASK_SHIFT) {
    // Temporarily cancel shifts so they aren't applied to the whole string
    unregister_code(KC_LSFT);
    unregister_code(KC_RSFT);
    send_string(shifted);
    set_mods(mod_state);
  }
  else {
    send_string(normal);
  }
}

// Process custom key codes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool p = record->event.pressed;
  switch (keycode) {
    // When printing both parens, etc., the X_LEFT moves the cursor in between them
    case CKC_BOTHBRC: if (p) send_string("[]" SS_TAP(X_LEFT)); break;
    case CKC_BOTHCBR: if (p) send_string("{}" SS_TAP(X_LEFT)); break;
    case CKC_BOTHPAREN: if (p) send_string("()" SS_TAP(X_LEFT)); break;
    case CKC_BOTHANGLE: if (p) send_string("<>" SS_TAP(X_LEFT)); break;
    case CKC_BOTHDQUO: if (p) send_string("\"\"" SS_TAP(X_LEFT)); break;
    case CKC_BOTHQUOTE: if (p) send_string("''" SS_TAP(X_LEFT)); break;
    case CKC_BOTHGRAVE: if (p) send_string("``" SS_TAP(X_LEFT)); break;

    case CKC_MYLASTNAME: if (p) shift_send_string(MY_LASTNAME, MY_LASTNAME_SHIFT); break;
    case CKC_MYUSERNAME: if (p) shift_send_string(MY_USERNAME, MY_GMAIL); break;
    case CKC_MYWORKEMAIL: if (p) shift_send_string(MY_WORK_EMAIL, MY_GMAIL); break;
    case CKC_MYPLOVER: if (p) shift_send_string(MY_PLOVER, MY_PLOVER_SHIFT); break;

    /* // Vim commands for non-vim editors */

    /* /1* Change to end of line *1/ */
    /* case CKC_VIM_C: */
    /*   if (p) { */
    /*     register_code(KC_LSFT); */
    /*     tap_code(KC_END); */
    /*     unregister_code(KC_LSFT); */
    /*     tap_code(KC_DEL); */
    /*   } */
    /*   break; */
    /* /1* Duplicate  Line *1/ */
    /* case CKC_VIM_D: */
    /*   if (p) { */
    /*     tap_code(KC_HOME); */
    /*     register_code(KC_LSFT); */
    /*     tap_code(KC_END); */
    /*     unregister_code(KC_LSFT); */
    /*     register_code(KC_LCTL); */
    /*     tap_code(KC_C); */
    /*     unregister_code(KC_LCTL); */
    /*     tap_code(KC_RIGHT); */

    /*     tap_code(KC_ENTER); */
    /*     register_code(KC_LCTL); */
    /*     tap_code(KC_V); */
    /*     unregister_code(KC_LCTL); */
    /*   } */
    /*   break; */
    /*   /1* Select whole line *1/ */
    /* case CKC_VIM_V: */
    /*   if (p) { */
    /*     tap_code(KC_HOME); */
    /*     register_code(KC_LSFT); */
    /*     tap_code(KC_END); */
    /*     unregister_code(KC_LSFT); */
    /*   } */
    /*   break; */
  }
  return true;
};


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
      KC_TAB, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PSCR, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_NUM] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      KC_PLUS, KC_7, KC_8, KC_9, KC_EQUAL, _______,

      _______, _______, _______, _______, _______, _______,
      KC_DOT, KC_4, KC_5, KC_6, KC_0, _______,

      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______,
      KC_MINS, KC_1, KC_2, KC_3, _______, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_W] = LAYOUT(
      _______, G(S(KC_1)), G(S(KC_2)), G(S(KC_3)), G(S(KC_4)), G(S(KC_5)), // Move window to workspace
      _______, _______, _______, _______, _______, _______,

      KC_CAPS, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5), // Switch to workspace
      _______, _______, _______, _______, _______, _______,

      _______, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, // Xf86Launch5-9 (Frequent App Launchers)
      _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_F] = LAYOUT(
      _______, KC_F11, KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

      _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

      _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
      _______, _______, _______, _______,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,

      _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______
      ),
  [_M] = LAYOUT(
      _______, _______, _______, _______, _______, _______,
      XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX, _______,

      _______, XXXXXXX, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX,
      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2, _______,

      _______, _______, _______, _______, _______, _______,
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
    if (IS_LAYER_ON(_W)) {
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

const rgblight_segment_t PROGMEM my_NUM_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {11, 2, HSV_RED},  // a few red on the right hand
  {15, 4, HSV_RED}
);
const rgblight_segment_t PROGMEM my_W_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 4, HSV_ORANGE},  // a few orange on the left hand
  {7, 2, HSV_ORANGE}
);
const rgblight_segment_t PROGMEM my_F_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 4, HSV_GREEN}, // a few green on the left hand
  {7, 2, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_M_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 4, HSV_PURPLE}, // Purple on both hands
  {7, 2, HSV_PURPLE},
  {11, 2, HSV_PURPLE},
  {15, 4, HSV_PURPLE}
);
/* const rgblight_segment_t PROGMEM my_macrorec_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*   {0, 20, HSV_PINK}  // All pink */
/* ); */
/* const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS( */
/*   {0, 20, HSV_GOLD}  // All yellow */
/* ); */

// Define up to 8 layers. Later layers take precedence.
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_NUM_layer,  // 0
    my_W_layer,
    my_F_layer,
    my_M_layer
    /* my_capslock_layer, */
    /* my_macrorec_layer */
    );

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers; // Load layer definitions from memory
}

layer_state_t layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _NUM));
  rgblight_set_layer_state(1, layer_state_cmp(state, _W));
  rgblight_set_layer_state(2, layer_state_cmp(state, _F));
  rgblight_set_layer_state(3, layer_state_cmp(state, _M));
  return state;
}

// On update to any keyboard LED (like Capslock)
// Set the layer light to 
/* bool led_update_user(led_t led_state) { */
/*   rgblight_set_layer_state(4, led_state.caps_lock); */
/*   return true; */
/* } */

/* void dynamic_macro_record_start_user(int8_t direction) { */
/*   rgblight_set_layer_state(5, true); */
/* } */
/* void dynamic_macro_record_end_user(int8_t direction) { */
/*   rgblight_set_layer_state(5, false); */
/* } */
// Blink when a macro is played back
/* void dynamic_macro_play_user(int8_t direction) { */
/*   rgblight_set_layer_state(5, true); */
/*   wait_ms(1000); */
/*   rgblight_set_layer_state(5, false); */
/* } */

#endif
