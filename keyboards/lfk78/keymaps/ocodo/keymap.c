#include "lfk78.h"
#include "issi.h"
#include "lighting.h"
#include "action_layer.h"

//Define a shorter 'transparent' key code to make the keymaps more compact
#define KC_TR KC_TRNS

// Return/Ctl
#define RET_CTL CTL_T(KC_ENT)

// Backspace/Ctl (for Capslock location)
#define BSP_CTL CTL_T(KC_BSPC)

enum macro_id {
  M_NOM,
  M_EML,
  M_GHB,
  M_PIV,
  M_PNM,
  M_HTP,
  M_SSL
};

#define JM23  M(M_NOM)
#define GMAIL M(M_EML)
#define GHUB  M(M_GHB)
#define HTTP  M(M_HTP)
#define HTTPS M(M_SSL)
#define JMPIV M(M_PNM)
#define PIVIO M(M_PIV)

enum keymap_layout {
  OCODO = 0,
  FUNC,
  NUMPAD,
};

// Colors of the layer indicator LED
// This list needs to define layer 0xFFFFFFFF, it is the end of the list, and the unknown layer
const Layer_Info layer_info[] = {
  // Layer     Mask         Red     Green   Blue
  {0x00000000, 0xFFFFFFF8, {0x0000, 0x00FF, 0x00FF}},
  {0x00000002, 0xFFFFFFF8, {0x0FFF, 0x0000, 0x0000}},
  {0xFFFFFFFF, 0xFFFFFFFF, {0x0FFF, 0x0FFF, 0x0FFF}},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap OCODO: (Ocodo base layer) Default Layer
   * ,---------.  ,------------------------------------------------------------.  ,---------.
   * |    |    |  |Esc~| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |  0| - | = |Backspa|  |Home|PgUp|
   * |---------|  |------------------------------------------------------------|  |---------|
   * |    |    |  |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|     \|  |End |PgDn|
   * |---------|  |------------------------------------------------------------|  `---------'
   * |    |    |  |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return   |
   * |---------|  |------------------------------------------------------------|  ,----.
   * |    |    |  |Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift       |  | Up |
   * |---------|  |-------------------------------------------------------------------------.
   * |    |    |  |Ctrl|Alt |Gui |         Space         |    |Ctrl|Func |    |Lft| Dn |Rig |
   * `---------'  `------------------------------------------------------'    `-------------'
   */

  [OCODO] = KEYMAP(
                   KC_NO,   KC_NO,    KC_FN1,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,   KC_0,      KC_MINS,   KC_EQL,     KC_BSPC,    KC_HOME,  KC_PGUP,
                   KC_NO,   KC_NO,    KC_TAB,    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,      KC_LBRC,   KC_RBRC,    KC_BSLS,    KC_END,   KC_PGDN,
                   KC_NO,   KC_NO,    BSP_CTL,   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN,   KC_QUOT,               RET_CTL,
                   KC_NO,   KC_NO,    KC_LSFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,   KC_RSFT,                           KC_UP,
                   KC_NO,   KC_NO,    KC_LCTL,   KC_LALT, KC_LGUI,               KC_SPC,                          KC_NO,  KC_LCTL,   MO(FUNC),               KC_LEFT,   KC_DOWN,   KC_RGHT),

  /* Keymap FUNCTION: Function Layer
   * ,---------.  ,-------------------------------------------------------------.  ,---------.
   * |    |    |  | ` |F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|   Del   |  |jm23|gml |
   * |---------|  |-------------------------------------------------------------|  |---------|
   * |    |    |  |     |   |   |   |   |   |   |   |   |   |   |HTP|SSL| GHB   |  |jmil|piv |
   * |---------|  |-------------------------------------------------------------|  `---------'
   * |    |    |  |      |   |   |   |   |   |   |   |   |   |   |   |          |
   * |---------|  |-------------------------------------------------------------|  ,----.
   * |    |    |  |       |   |   |   |   |   |   |   |   |   |   | Tgl Numpad  |  |    |
   * |---------|  |--------------------------------------------------------------------------.
   * |    |    |  |    |    |    |                         |   |Alt |Func |   |    |    |    |
   * `---------'  `-------------------------------------------------------'   `--------------'
   */
  [FUNC] = KEYMAP(
                  KC_NO,    KC_NO,    KC_GRV,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_DEL,   JM23,    GMAIL,
                  KC_NO,    KC_NO,    KC_TR,    KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,    HTTP,     HTTPS,    GHUB,     JMPIV,   PIVIO,
                  KC_NO,    KC_NO,    KC_TR,    KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,    KC_TR,              KC_TR,
                  KC_NO,    KC_NO,    KC_TR,    KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,    TG(NUMPAD),                   KC_TR,
                  KC_NO,    KC_NO,    KC_TR,    KC_TR,   KC_TR,                     KC_TR,                              KC_TR,   KC_RALT,  KC_TR,               KC_TR,   KC_TR,   KC_TR),

  /* Keymap NUMPAD: Numpad Layer
   * ,---------.  ,-------------------------------------------------------------.  ,---------.
   * |    |    |  |NLK| A | B | C | D | E | F |   |   |   |   |   |   |         |  |    |    |
   * |---------|  |-------------------------------------------------------------|  |---------|
   * |    |    |  |     | 7 | 8 | 9 |   |   |   |   |   |   |   |   |   |       |  |    |    |
   * |---------|  |-------------------------------------------------------------|  `---------'
   * |    |    |  |      | 4 | 5 | 6 |   |   |   |   |   |   |   |   |          |
   * |---------|  |-------------------------------------------------------------|  ,----.
   * |    |    |  |       | 1 | 2 | 3 |   |   |   |   |   |   |   |             |  |    |
   * |---------|  |--------------------------------------------------------------------------.
   * |    |    |  |  . |  0 | ENT|                         |    |   |Func |   |    |    |    |
   * `---------'  `-------------------------------------------------------'   `--------------'
   */
  [NUMPAD] = KEYMAP(
                    KC_NO,    KC_NO,    KC_NUMLOCK, KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F,    KC_TR,   KC_TR,   KC_TR,   KC_TR,    KC_TR,    KC_TR,    KC_TR,     KC_TR,   KC_TR,
                    KC_NO,    KC_NO,    KC_TR,      KC_KP_7, KC_KP_8, KC_KP_9, KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,    KC_TR,    KC_TR,    KC_TR,     KC_TR,   KC_TR,
                    KC_NO,    KC_NO,    KC_TR,      KC_KP_4, KC_KP_5, KC_KP_6, KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,    KC_TR,              KC_TR,
                    KC_NO,    KC_NO,    KC_TR,      KC_KP_1, KC_KP_2, KC_KP_3, KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,   KC_TR,    KC_TR,                        KC_TR,
                    KC_NO,    KC_NO,    KC_DOT,     KC_KP_0, KC_ENT,                    KC_TR,                              KC_TR,   KC_TR,    KC_TR,               KC_TR,   KC_TR,   KC_TR),
};

const uint16_t PROGMEM fn_actions[] = {
  ACTION_FUNCTION(LFK_CLEAR),               // FN0 - reset layers
  ACTION_FUNCTION(LFK_ESC_TILDE),           // FN1 - esc+shift = ~, else escape
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
      SEND_STRING("@pivotal.io");
    }
    break;
  case M_PNM:
    if (record->event.pressed) {
      SEND_STRING("jmilkins");
    }
    break;
  }

  return MACRO_NONE;
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
