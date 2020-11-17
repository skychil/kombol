#pragma once

#include QMK_KEYBOARD_H

enum layer_names {
  _COLEMAK_DHM = 0,
  _NAV,
  _NUM,
  _F,
  _M,
  _VIM
};

// Lower Thumb keys
#define MY_LE RGB_TOG
#define MY_LT1 KC_LCTL
#define MY_LT2 LSFT_T(KC_SPACE)
#define MY_LT3 MO(_NUM)
#define MY_LT4 MO(_VIM)
#define MY_RT4 MO(_M)
#define MY_RT3 MO(_NUM)
#define MY_RT2 RSFT_T(KC_ENTER)
#define MY_RT1 MO(_NAV)
#define MY_RE KC_MUTE

// Upper Thumb keys
#define MY_LT5 MO(_F)
#define MY_LT6 MO(_M)
#define MY_RT6 MO(_VIM)
#define MY_RT5 MO(_F)

// Outer Edge Keys
#define MY_LOH KC_TAB
#define MY_LOM LALT_T(KC_ESC)
#define MY_LOL C(KC_LALT)

#define MY_ROH KC_INS
#define MY_ROM KC_BSPACE
/* #define MY_ROM LCTL_T(KC_QUOTE) */
#define MY_ROL C(KC_LALT)

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
#define MY_O LGUI_T(KC_O)

// Ideal Home Row Mods
// Activating breaks combos (which are more useful)
// Leaving in case qmk adds support in the future
/* #define MY_R LALT_T(KC_R) */
/* #define MY_S LCTL_T(KC_S) */
/* #define MY_E LCTL_T(KC_E) */
/* #define MY_I LALT_T(KC_I) */

#define MY_Z KC_Z
#define MY_X KC_X
#define MY_C KC_C
#define MY_D KC_D
#define MY_V KC_V
#define MY_K KC_K
#define MY_H KC_H
#define MY_COMMA KC_COMMA
#define MY_DOT KC_DOT
#define MY_SLASH LCTL_T(KC_SLASH)

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


/* // Tap Dance */
/* enum { */
/*   CACCCV_TD = 0, */
/* }; */

/* #define TD_CACCCV TD(CACCCV_TD) */

