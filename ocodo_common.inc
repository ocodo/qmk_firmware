// Used by
// - Gonnerd (tkl)                  keyboards/gonnerd/keymaps/tkl/keymap.c
// - Handwired/Tenkeyless (default) keyboards/handwired/tenkeyless/keymaps/default/keymap.c
// - Ocodo_Phantom (default)        keyboards/ocodo_phantom/keymaps/default/keymap.c
// - Satan GH60 (ocodo)             keyboards/satan/keymaps/ocodo/keymap.c

#define _x_   KC_TRNS
#define __AS  KC_KP_ASTERISK
#define __PL  KC_KP_PLUS
#define __SL  KC_KP_SLASH
#define __MI  KC_KP_MINUS
#define __DT  KC_DOT
#define __EN  KC_ENT

#define _CLN_  M(M_CLN)
#define _QUOT_ M(M_QUOT)
#define _KBD_  M(M_KBD)

#define _NM_  M(M_NOM)
#define _EM_  M(M_EML)
#define _GH_  M(M_GHB)
#define _PV_  M(M_PIV)
#define _PN_  M(M_PNM)
#define _HT_  M(M_HTP)
#define _SSL_ M(M_SSL)
#define _PT_  M(M_PTU)

#define _ESX  M(M_ESX)
#define _TIX  M(M_TIX)
#define _TAX  M(M_TAX)
#define _CAX  M(M_CAX)
#define _LSX  M(M_LSX)
#define _INX  M(M_INX)
#define _HOX  M(M_HOX)
#define _PUX  M(M_PUX)
#define _DEX  M(M_DEX)
#define _ENX  M(M_ENX)
#define _PDX  M(M_PDX)
#define _UAX  M(M_UAX)
#define _DAX  M(M_DAX)

#define __CTBS_ MT(MOD_LCTL, KC_BSPC)
#define __CTEN_ MT(MOD_LCTL, KC_ENT)
#define __ALTB_ MT(MOD_LALT, KC_TAB)
#define __ALBS_ MT(MOD_LALT, KC_BSLS)
#define __GUGR_ MT(MOD_LGUI, KC_GRV)
#define __GUBK_ MT(MOD_LGUI, KC_BSPC)
#define __CTSP_ MT(MOD_LCTL, KC_SPC)

#define UP_T    SFT_T(KC_UP)
#define DOWN_T  ALT_T(KC_DOWN)
#define LEFT_T  GUI_T(KC_LEFT)
#define RIGHT_T CTL_T(KC_RIGHT)

enum macro_id {
  M_NOM,
  M_EML,
  M_EMC,
  M_GHB,
  M_PIV,
  M_PNM,
  M_HTP,
  M_SSL,
  M_PTU,
  M_ESX,
  M_TIX,
  M_TAX,
  M_CAX,
  M_LSX,
  M_INX,
  M_HOX,
  M_PUX,
  M_DEX,
  M_ENX,
  M_PDX,
  M_UAX,
  M_DAX,
  M_CLN,
  M_QUOT,
  M_KBD
};

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
      SEND_STRING("danqiang_zhao@singaporeair.com.sg");
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

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum function_id {
  SHIFT_ESC,
};

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
