#include "gonnerd.h"

#define _x_   KC_TRNS
#define __AS  KC_KP_ASTERISK
#define __PL  KC_KP_PLUS
#define __SL  KC_KP_SLASH
#define __MI  KC_KP_MINUS
#define __DT  KC_DOT
#define __EN  KC_ENT

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
  M_DAX
  };

// Keymap layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = KEYMAP_TKL( \
                   KC_ESC,           KC_F1,   KC_F2,  KC_F3, KC_F4,   KC_F5,  KC_F6, KC_F7,  KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,    KC_PSCR,KC_SLCK,KC_PAUS, \
                   KC_GRV,  KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,   KC_INS, KC_HOME,KC_PGUP, \
                   KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,   KC_DEL, KC_END, KC_PGDN, \
                   KC_LCTL, KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,    KC_SCLN, KC_QUOT, _x_,     KC_ENT,                             \
                   KC_LSFT, _x_,     KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _x_,               KC_UP,           \
                   KC_LCTL, KC_LALT, KC_LGUI,                         KC_SPC,                          KC_RGUI, KC_RALT, MO(1),   KC_RCTL,   KC_LEFT,KC_DOWN,KC_RGHT \
                    ),
  [1] = KEYMAP_TKL(\
                   _ESX,             _NM_,    _EM_,  _GH_,  _HT_,    _SSL_,   _x_,    KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,  _PN_,      _PV_,   _PT_, \
                   _TIX,    KC_A,    KC_B,    KC_C,  KC_D,  KC_E,    KC_F,    _x_,    _x_,     _x_,     _x_,     _x_,     _x_,     _x_,      _INX,      _HOX,   _PUX, \
                   _TAX,    KC_7,    KC_8,    KC_9,  __PL,  __MI,     _x_,    _x_,    _x_,     _x_,     _x_,     _x_,     _x_,     _x_,      _DEX,      _ENX,   _PDX, \
                   _CAX,    KC_4,    KC_5,    KC_6,  __SL,  __AS,     _x_,    _x_,    _x_,     _x_,     _x_,     _x_,     _x_,     _x_, \
                   _LSX,    _x_,     KC_1,    KC_2,  KC_3,  KC_0,    __DT,    _x_,    _x_,     _x_,     _x_,     _x_,     _x_,     _x_,                 _UAX, \
                   _x_,     _x_,     __EN,                           _x_,                               _x_,     _x_,     _x_,     KC_APP,   _x_,       _DAX,    _x_)
};

const uint16_t PROGMEM fn_actions[] = {
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
  }

  return MACRO_NONE;
};
