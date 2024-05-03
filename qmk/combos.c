#include QMK_KEYBOARD_H

#include "keymap.h"
#include "combos.h"
#include "action_tapping.h" // for action_tapping_process
#include "personalplover.h"

void shift_send_string(const char *normal, const char *shifted);

void process_combo_event(uint16_t combo_index, bool pressed) {
  // Process mod-taps before the combo is fired,
  // this helps making modifier-aware combos
  // more fluid with home row mods.
  action_tapping_process((keyrecord_t){});

  switch(combo_index) {
    case C_bothbrc:
      if (pressed) {
        send_string("[]");
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
    case C_bothangle:
      if (pressed) {
        send_string("<>");
        tap_code(KC_LEFT); // Cursor in between
      }
      break;
    case C_bothdquo:
      if (pressed) {
        send_string("\"\"");
        tap_code(KC_LEFT); // Cursor in between
      }
      break;
    case C_bothquote:
      if (pressed) {
        send_string("''");
        tap_code(KC_LEFT); // Cursor in between
      }
      break;
    case C_bothgrave:
      if (pressed) {
        send_string("``");
        tap_code(KC_LEFT); // Cursor in between
      }
      break;

    case C_mylastname: if (pressed) shift_send_string(MY_LASTNAME, MY_LASTNAME_SHIFT); break;
    case C_myusername: if (pressed) shift_send_string(MY_USERNAME, MY_GMAIL); break;
    case C_myworkemail: if (pressed) shift_send_string(MY_WORK_EMAIL, MY_GMAIL); break;
    case C_myplover: if (pressed) shift_send_string(MY_PLOVER, MY_PLOVER_SHIFT); break;

    default:
      break;
  }
};

// Send second arg if shift is held, else send the first
void shift_send_string(const char *normal, const char *shifted) {
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

