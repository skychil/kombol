#include QMK_KEYBOARD_H

#include "keymap.h"
#include "combos.h"
#include "action_tapping.h" // for action_tapping_process

void shifted_send_string(const char *normal, const char *shifted);
void shifted_or_ctrled_send_string(const char *normal, const char *shifted, const char *ctrled);


void process_combo_event(uint16_t combo_index, bool pressed) {
  // Process mod-taps before the combo is fired,
  // this helps making modifier-aware combos,
  // more fluid with home row mods.
  action_tapping_process((keyrecord_t){});

  switch(combo_index) {
    /* case C_macrorec: */
    /*   if (pressed) tap_code16(DM_REC1); */
    /*   break; */
    /* case C_macrostop: */
    /*   if (pressed) tap_code16(DM_RSTP); */
    /*   break; */
    /* case C_macroplay: */
    /*   if (pressed) tap_code16(DM_PLY1); */
    /*   break; */

    case C_lbrc:
      if (pressed) shifted_send_string("[", "{");
      break;
    case C_rbrc:
      if (pressed) shifted_send_string("]", "}");
      break;
    case C_bothbrc:
      if (pressed) {
        shifted_send_string("[]", "{}");
        tap_code(KC_LEFT); // Cursor in between
      }
      break;
    case C_bothcbr:
      if (pressed) {
        send_string("{}");
        tap_code(KC_LEFT); // Cursor in between
      }
      break;
    case C_bothparen:
      if (pressed) {
        send_string("()");
        tap_code(KC_LEFT); // Cursor in between
      }
      break;
    case C_dotspaceshift:
      if (pressed) {
        SEND_STRING(". ");
        set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
      }
      break;
    case C_exclspaceshift:
      if (pressed) {
        SEND_STRING("! ");
        set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
      }
      break;
    case C_quesspaceshift:
      if (pressed) {
        SEND_STRING("? ");
        set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
      }
      break;
    /* case C_and: */
    /*   if (pressed) shifted_send_string("and", "And"); */
    /*   break; */
    /* case C_are: */
    /*   if (pressed) shifted_send_string("are", "Are"); */
    /*   break; */
    /* case C_the: */
    /*   if (pressed) shifted_send_string("the", "The"); */
    /*   break; */
    /* case C_that: */
    /*   if (pressed) shifted_send_string("that", "That"); */
    /*   break; */
    /* case C_this: */
    /*   if (pressed) shifted_send_string("this", "This"); */
    /*   break; */
    /* case C_ing: */
    /*   if (pressed) send_string("ing"); */
    /*   break; */
    /* case C_ment: */
    /*   if (pressed) shifted_send_string("ment", "Ment"); */
    /*   break; */

    /* case C_not: */
    /*   if (pressed) shifted_or_ctrled_send_string("not", "Not", "n't"); */
    /*   break; */
    /* case C_ever: */
    /*   if (pressed) shifted_send_string("ever", "Ever"); */
    /*   break; */
    /* case C_ion: */
    /*   if (pressed) send_string("ion"); */
    /*   break; */
    /* case C_ould: */
    /*   if (pressed) send_string("ould"); */
    /*   break; */

    /* case C_with: */
    /*   if (pressed) shifted_send_string("with", "With"); */
    /*   break; */
    /* case C_which: */
    /*   if (pressed) shifted_send_string("which", "Which"); */
    /*   break; */
    /* case C_for: */
    /*   if (pressed) shifted_send_string("for", "For"); */
    /*   break; */
    /* case C_the: */
    /*   if (pressed) shifted_send_string("the", "The"); */
    /*   break; */
    /* case C_part: */
    /*   if (pressed) shifted_send_string("part", "Part"); */
    /*   break; */
    /* case C_all: */
    /*   if (pressed) shifted_send_string("all", "All"); */
    /*   break; */
    /* case C_use: */
    /*   if (pressed) shifted_send_string("use", "Use"); */
    /*   break; */
    /* case C_you: */
    /*   if (pressed) shifted_send_string("you", "You"); */
    /*   break; */

    /* case C_dance: */
    /*   if (pressed) shifted_send_string("dance", "Dance"); */
    /*   break; */
    /* case C_sky: */
    /*   if (pressed) shifted_send_string("sky", "Sky"); */
    /*   break; */
    /* case C_here: */
    /*   if (pressed) shifted_send_string("here", "Here"); */
    /*   break; */
    /* case C_have: */
    /*   if (pressed) shifted_send_string("have", "Have"); */
    /*   break; */
    /* case C_vim_v: */
    /*   if (!pressed) break; */
    /*   tap_code(KC_HOME); */
    /*   register_code(KC_LSFT); */
    /*   tap_code(KC_END); */
    /*   unregister_code(KC_LSFT); */
    /*   break; */
    /* case C_vim_s: */
    /*   if (!pressed) break; */
    /*   tap_code(KC_HOME); */
    /*   register_code(KC_LSFT); */
    /*   tap_code(KC_END); */
    /*   unregister_code(KC_LSFT); */
    /*   tap_code(KC_BSPC); */
    /*   break; */
    /* case C_vim_c: */
    /*   if (!pressed) break; */
    /*   register_code(KC_LSFT); */
    /*   tap_code(KC_END); */
    /*   unregister_code(KC_LSFT); */
    /*   tap_code(KC_BSPC); */
    /*   break; */
    default:
      break;
  }
};

void shifted_send_string(const char *normal, const char *shifted) {
  uint8_t mod_state = get_mods();
  if (mod_state & MOD_MASK_SHIFT) {
    // Temporarily cancel shifts so they aren't applied to the whole string
    unregister_code(KC_LSHIFT);
    unregister_code(KC_RSHIFT);
    send_string(shifted);
    set_mods(mod_state);
  }
  else {
    send_string(normal);
  }
}

void shifted_or_ctrled_send_string(const char *normal, const char *shifted, const char *ctrled) {
  uint8_t mod_state = get_mods();
  if (mod_state & MOD_MASK_SHIFT) {
    unregister_code(KC_LSHIFT);
    unregister_code(KC_RSHIFT);
    send_string(shifted);
    set_mods(mod_state);
  }
  else if (mod_state & MOD_MASK_CTRL) {
    unregister_code(KC_LCTL);
    unregister_code(KC_RCTL);
    send_string(ctrled);
    set_mods(mod_state);
  }
  else {
    send_string(normal);
  }
}
