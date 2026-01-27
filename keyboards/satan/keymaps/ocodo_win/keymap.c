#include "satan.h"

#undef LEFT_T
#undef UP_T
#undef DOWN_T
#undef RIGHT_T

#define LEFT_T  GUI_T(KC_DOWN)
#define UP_T    SFT_T(KC_UP)
#define DOWN_T  ALT_T(KC_LEFT)
#define RIGHT_T CTL_T(KC_RIGHT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer */
  [0] = KEYMAP_ANSI(
		    F(20),   KC_1,    KC_2,    KC_3,   KC_4,     KC_5,      KC_6,    KC_7,       KC_8,    KC_9,       KC_0,  KC_MINS,  KC_EQL,  KC_BSPC, \
                    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,     KC_T,      KC_Y,    KC_U,       KC_I,    KC_O,       KC_P,  KC_LBRC, KC_RBRC,  KC_BSLS, \
                    KC_CAPS, KC_A,    KC_S,    KC_D,   KC_F,     KC_G,      KC_H,    KC_J,       KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT, \
                    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,     KC_B,      KC_N,    KC_M,    KC_COMM,  KC_DOT,    KC_SLSH,              UP_T,           \
                    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                        MO(1),               LEFT_T,  DOWN_T,  RIGHT_T),

  /* Keymap: function layer*/
  [1] = KEYMAP_ANSI(
		    KC_GRV,  KC_F1,   KC_F2,   KC_F3,  KC_F4,    KC_F5,     KC_F6,   KC_F7,     KC_F8,   KC_F9,     KC_F10,  KC_F11,   KC_F12,   KC_DEL, \
                    _x_,     _x_,     _x_,     _x_,    _x_,      _x_,       _x_,     KC_INS,      _x_,     _x_,     KC_PSCR, KC_SLCK,  KC_PAUS,     _x_, \
                    _x_,     _x_,     _x_,     _x_,    _x_,      _x_,       _x_,     _x_,         _x_,     _x_,     KC_HOME, KC_PGUP,               _x_, \
                    _x_,     _x_,     _x_,     _x_,    _x_,      _x_,       KC_VOLD, KC_VOLU, KC_MUTE,  KC_END,     KC_PGDN,           _x_,              \
                    _x_,     _x_,     _x_,                                 _x_,                                     _x_,     _x_,      _x_,         _x_),
};

