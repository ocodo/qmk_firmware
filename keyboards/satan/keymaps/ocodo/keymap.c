#include "satan.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Return/Ctl
#define RET_CTL CTL_T(KC_ENT)

// Backspace/Ctl (for Capslock location)
#define BSP_CTL CTL_T(KC_BSPC)

#define JSM23 M(M_NOM)
#define GMAIL M(M_EML)
#define GHUB  M(M_GHB)
#define HTTP  M(M_HTP)
#define HTTPS M(M_SSL)
#define JMPIV M(M_PNM)
#define PIVIO M(M_PIV)

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ┌───────────────────────────────────────────────────────────┐
   * │Esc~│ 1│  2│  3│  4│  5│  6│  7│  8│  9│  0│  ─│  =│Backsp │
   * │───────────────────────────────────────────────────────────│
   * │Tab  │  Q│  W│  E│  R│  T│  Y│  U│  I│  O│  P│  [│  ]│  \  │
   * │───────────────────────────────────────────────────────────│
   * │Bsp/Ctl│  A│  S│  D│  F│  G│  H│  J│  K│  L│  ;│  '│Ret/Ctl│
   * │───────────────────────────────────────────────────────────│
   * │Shift   │  Z│  X│  C│  V│  B│  N│  M│  ,│  .│  /│Shift     │
   * │───────────────────────────────────────────────────────────│
   * │Ctrl│Alt │Gui │         Space         │Gui │FN  │Alt │Ctrl │
   * └───────────────────────────────────────────────────────────┘
   */
[_BL] = KEYMAP_ANSI(
  F(0),    KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,     KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, \
  BSP_CTL, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,     KC_K,    KC_L,   KC_SCLN, KC_QUOT,          RET_CTL,  \
  KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT, KC_SLSH,                   KC_RSFT, \
  KC_LCTL, KC_LALT, KC_LGUI,                           KC_SPC,                             KC_RGUI, MO(_FL), KC_RALT, KC_RCTL),

/* Keymap _FL: Function Layer
   * ┌───────────────────────────────────────────────────────────┐
   * │ ~ │ F1│F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│  DEL  │
   * │───────────────────────────────────────────────────────────│
   * │     │  │ Up│JM│GM│GH│HTP│HTPS│Ins│   │PrSc│Sclk│Paus│     │
   * │───────────────────────────────────────────────────────────│
   * │      │Left│Down│Rig│JMP│PIV│  │  │   │   │Home│PgUp│      │
   * │───────────────────────────────────────────────────────────│
   * │        │   │App│  │  │   │Vdn│Vup│Mute│End│PgDn│          │
   * │───────────────────────────────────────────────────────────│
   * │    │    │    │                        │    │    │    │    │
   * └───────────────────────────────────────────────────────────┘
   */
[_FL] = KEYMAP_ANSI(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  \
  KC_TRNS, KC_TRNS, KC_UP,   JSM2,    GMAIL,   GHUB,    HTTP,    HTTPS,    KC_INS,  KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_TRNS, \
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, JMPIV,   PIVIO,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP,          KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_APP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU,  KC_MUTE, KC_END,  KC_PGDN,                   KC_TRNS, \
  KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

enum function_id {
    SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_FUNCTION(SHIFT_ESC),
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
  case M_PSG:
    if (record->event.pressed) {
      SEND_STRING("pivotal-sg");
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
  case M_VER:
    if (record->event.pressed) {
      SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION "@" QMK_BUILDDATE);
    }
    break;
  }

  return MACRO_NONE;
};
