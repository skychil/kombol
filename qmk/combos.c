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
    case C_dotspaceshift:
      if (pressed) {
        SEND_STRING(". ");
        set_oneshot_mods(MOD_LSFT | get_oneshot_mods());
      }
      break;

    /* case C_the: if (pressed) shift_send_string("the", "The"); break; */

    /* case C_and: if (pressed) shift_send_string("and", "And"); break; */
    /* case C_are: if (pressed) shift_send_string("are", "Are"); break; */
    /* case C_but: if (pressed) shift_send_string("but", "But"); break; */
    /* case C_can: if (pressed) shift_send_string("can", "Can"); break; */
    /* case C_could_: if (pressed) shift_send_string("could ", "Could "); break; */
    /* case C_dance: if (pressed) shift_send_string("dance", "Dance"); break; */
    /* case C_ever: if (pressed) shift_send_string("ever", "Ever"); break; */
    /* case C_from: if (pressed) shift_send_string("from", "From"); break; */
    /* case C_had: if (pressed) shift_send_string("had", "Had"); break; */
    /* case C_have: if (pressed) shift_send_string("have", "Have"); break; */
    /* case C_here: if (pressed) shift_send_string("here", "Here"); break; */
    /* case C_ing: if (pressed) shift_send_string("ing", "Ing"); break; */
    /* case C_just: if (pressed) shift_send_string("just", "Just"); break; */
    /* case C_ment: if (pressed) shift_send_string("ment", "Ment"); break; */
    /* case C_not: if (pressed) shift_send_string("not", "Not"); break; */
    /* case C_should_: if (pressed) shift_send_string("should ", "Should "); break; */
    /* case C_sky: if (pressed) shift_send_string("sky", "Sky"); break; */
    /* case C_son: if (pressed) shift_send_string("son", "Son"); break; */
    /* case C_some: if (pressed) shift_send_string("some", "Some"); break; */
    /* case C_thanks: if (pressed) shift_send_string("thanks", "Thanks"); break; */
    /* case C_thankyou: if (pressed) shift_send_string("thank you", "Thank you"); break; */
    /* case C_that_: if (pressed) shift_send_string("that ", "That "); break; */
    /* case C_they_: if (pressed) shift_send_string("they ", "They "); break; */
    /* case C_this_: if (pressed) shift_send_string("this ", "This "); break; */
    /* case C_were: if (pressed) shift_send_string("were", "Were"); break; */
    /* case C_what: if (pressed) shift_send_string("what", "What"); break; */
    /* case C_which_: if (pressed) shift_send_string("which ", "Which "); break; */
    /* case C_will: if (pressed) shift_send_string("will", "Will"); break; */
    /* case C_with: if (pressed) shift_send_string("with", "With"); break; */
    /* case C_would_: if (pressed) shift_send_string("would ", "Would "); break; */
    /* case C_you: if (pressed) shift_send_string("you", "You"); break; */
    /* case C_your: if (pressed) shift_send_string("your", "Your"); break; */

    case C_mylastname: if (pressed) shift_send_string(MY_LASTNAME_LOWERCASE, MY_LASTNAME); break;
    case C_myemail: if (pressed) shift_send_string(MY_EMAIL, MY_EMAIL_2); break;


    default:
      break;
  }
};

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

/* void shift_or_ctrl_send_string(const char *normal, const char *shifted, const char *ctrled) { */
/*   uint8_t mod_state = get_mods(); */
/*   if (mod_state & MOD_MASK_SHIFT) { */
/*     unregister_code(KC_LSHIFT); */
/*     unregister_code(KC_RSHIFT); */
/*     send_string(shifted); */
/*     set_mods(mod_state); */
/*   } */
/*   else if (mod_state & MOD_MASK_CTRL) { */
/*     unregister_code(KC_LCTL); */
/*     unregister_code(KC_RCTL); */
/*     send_string(ctrled); */
/*     set_mods(mod_state); */
/*   } */
/*   else { */
/*     send_string(normal); */
/*   } */
/* } */
