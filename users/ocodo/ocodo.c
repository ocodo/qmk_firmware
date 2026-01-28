#include "ocodo.h"

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
  case M_NOM:
    if (record->event.pressed) {
      SEND_STRING("jasonm23");
    }
    break;
  case M_EML:
    if (record->event.pressed) {
      SEND_STRING("@gmail.com");
    }
    break;
  case M_GHB:
    if (record->event.pressed) {
      SEND_STRING("github.com");
    }
    break;
  case M_HTP:
    if (record->event.pressed) {
      SEND_STRING("http://");
    }
    break;
  case M_SSL:
    if (record->event.pressed) {
      SEND_STRING("https://");
    }
    break;
  case M_PIV:
    if (record->event.pressed) {
      SEND_STRING("pivotal.io");
    }
    break;
  case M_PNM:
    if (record->event.pressed) {
      SEND_STRING("jmilkins");
    }
    break;
  case M_PTU:
    if (record->event.pressed) {
      SEND_STRING("https://pivotaltracker.com/story/show/");
    }
    break;
  case M_ESX:
    if (record->event.pressed) {
      SEND_STRING("git checkout -b");
    }
    break;
  case M_TIX:
    if (record->event.pressed) {
      SEND_STRING("git duet");
    }
    break;
  case M_TAX:
    if (record->event.pressed) {
      SEND_STRING("git diff");
    }
    break;
  case M_CAX:
    if (record->event.pressed) {
      SEND_STRING("git log");
    }
    break;
  case M_LSX:
    if (record->event.pressed) {
      SEND_STRING("git add --patch");
    }
    break;
  case M_INX:
    if (record->event.pressed) {
      SEND_STRING("git duet-commit -v");
    }
    break;
  case M_HOX:
    if (record->event.pressed) {
      SEND_STRING("cd ~/.emacs.d");
    }
    break;
  case M_PUX:
    if (record->event.pressed) {
      SEND_STRING("git push origin head");
    }
    break;
  case M_DEX:
    if (record->event.pressed) {
      SEND_STRING("git reset --hard");
    }
    break;
  case M_ENX:
    if (record->event.pressed) {
      SEND_STRING("git checkout master");
    }
    break;
  case M_PDX:
    if (record->event.pressed) {
      SEND_STRING("git pull --rebase --recurse-submodules");
    }
    break;
  case M_UAX:
    if (record->event.pressed) {
      SEND_STRING("git submodule update --init --recursive");
    }
    break;
  case M_DAX:
    if (record->event.pressed) {
      SEND_STRING("git fetch --all");
    }
    break;
  case M_CLN:
    if (record->event.pressed) {
      register_code(KC_LCTL);
      register_code(KC_E);
      unregister_code(KC_E);
      unregister_code(KC_LCTL);
      register_code(KC_SCLN);
      unregister_code(KC_SCLN);
    }
    break;
  case M_QUOT:
    if (record->event.pressed) {
      SEND_STRING("\"\\()\"");
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
    }
    break;
  case M_KBD:
    if (record->event.pressed) {
      SEND_STRING("<kbd></kbd>");
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
    }
    break;
  }

  return MACRO_NONE;
};

// Function action implementations
const uint16_t PROGMEM fn_actions[] = {
  [20] = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
  case SHIFT_ESC:
    shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
    if (record->event.pressed) {
      if (shift_esc_shift_mask) {
        add_key(KC_GRV);
        send_keyboard_report();
      } else {
        add_key(KC_ESC);
        send_keyboard_report();
      }
    } else {
      if (shift_esc_shift_mask) {
        del_key(KC_GRV);
        send_keyboard_report();
      } else {
        del_key(KC_ESC);
        send_keyboard_report();
      }
    }
    break;
  }
}

