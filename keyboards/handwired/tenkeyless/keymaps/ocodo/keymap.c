#include "tenkeyless.h"
#include "ocodo.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  KEYMAP(\
         KC_ESC,             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK,  KC_BRK, \
         __GUGR_,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, __GUBK_,        KC_INS, KC_HOME, KC_PGUP, \
         __ALTB_,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, __ALBS_,        KC_DEL,  KC_END, KC_PGDN, \
         __CTBS_,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,KC_QUOT,           __CTEN_, \
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,                   KC_RSFT,                  KC_UP, \
         KC_LCTL, KC_LALT, KC_LGUI,                   __CTSP_,                                     KC_RGUI, KC_RALT,   MO(1), KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT),

  KEYMAP(\
         _ESX,                _NM_,    _EM_,    _GH_,    _HT_,   _SSL_,     _x_, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,       M(M_PNM),M(M_PIV),    _PT_, \
         _TIX,       KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,           _INX,    _HOX,    _PUX, \
         _TAX,       KC_7,    KC_8,    KC_9,    __PL,    __MI,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,           _DEX,    _ENX,    _PDX, \
         _CAX,       KC_4,    KC_5,    KC_6,    __SL,    __AS,     _x_,     _x_,     _x_,     _x_,   _CLN_,  _QUOT_,              _x_, \
         _LSX,       KC_1,    KC_2,    KC_3,    KC_0,    __DT,     _x_,     _x_,     _x_,     _x_,     _x_,                       _x_,                    _UAX, \
          _x_,        _x_,    __EN,                     TG(2),                                         _x_,     _x_,     _x_,  KC_APP,            _x_,    _DAX,     _x_),

  KEYMAP(\
          _x_,                _NM_,    _EM_,    _GH_,    _HT_,   _SSL_,    _PN_,    _PV_,     _x_,     _x_, TG(3),     TG(4),   TG(5),        KC_BTN3, KC_BTN4, KC_BTN5, \
          _x_,       KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,        KC_WH_L, KC_WH_U, KC_WH_R, \
          _x_,       KC_7,    KC_8,    KC_9,    __PL,    __MI,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,        KC_BTN1, KC_WH_D, KC_BTN2, \
          _x_,       KC_4,    KC_5,    KC_6,    __SL,    __AS,     _x_,     _x_,     _x_,     _x_,     _x_,     _x_,              _x_, \
          _x_,       KC_1,    KC_2,    KC_3,    KC_0,    __DT,     _x_,     _x_,     _x_,     _x_,     _x_,                       _x_,                 KC_MS_U, \
          _x_,        _x_,    __EN,                       _x_,                                         _x_,     _x_,     _x_,     _x_,        KC_MS_L, KC_MS_D, KC_MS_R),

  /* COLEMAK_LAYER */
  KEYMAP(
         KC_ESC,             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS, \
         __GUGR_,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, __GUBK_,        KC_INS, KC_HOME, KC_PGUP, \
         __ALTB_,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, __ALBS_,        KC_DEL,  KC_END, KC_PGDN, \
         __CTBS_,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,          __CTEN_, \
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,                   KC_RSFT,                  KC_UP, \
         KC_LCTL, KC_LALT, KC_LGUI,                    __CTSP_,                                     KC_RGUI, KC_RALT,   MO(1),KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT),

  /* DVORAK_LAYER */
  KEYMAP(
         KC_ESC,             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS, \
         __GUGR_,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_LBRC, KC_RBRC, __GUBK_,        KC_INS, KC_HOME, KC_PGUP, \
         __ALTB_, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_SLSH,  KC_EQL, __ALBS_,        KC_DEL,  KC_END, KC_PGDN, \
         __CTBS_,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,          __CTEN_, \
         KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,                   KC_RSFT,                  KC_UP, \
         KC_LCTL, KC_LALT, KC_LGUI,                    __CTSP_,                                     KC_RGUI, KC_RALT,   MO(1), KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT),

  /* WORKMAN_LAYER */
   KEYMAP(
         KC_ESC,             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,      KC_PSCR, KC_SLCK, KC_PAUS, \
         __GUGR_,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  __GUBK_,       KC_INS, KC_HOME, KC_PGUP, \
         __ALTB_,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, KC_LBRC, KC_RBRC,  __ALBS_,       KC_DEL,  KC_END, KC_PGDN, \
         __CTBS_,    KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_QUOT,           __CTEN_, \
         KC_LSFT,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH,                    KC_RSFT,                 KC_UP, \
         KC_LCTL, KC_LALT, KC_LGUI,                    __CTSP_,                                     KC_RGUI, KC_RALT,  MO(1),   KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT),

};
