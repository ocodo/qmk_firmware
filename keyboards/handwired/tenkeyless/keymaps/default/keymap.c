#include "tenkeyless.h"

/*
 __  __                       __                                  __      ______  __  __   __
/\ \/\ \                     /\ \              __                /\ \    /\__  _\/\ \/\ \ /\ \
\ \ \_\ \     __      ___    \_\ \  __  __  __/\_\  _ __    __   \_\ \   \/_/\ \/\ \ \/'/'\ \ \
 \ \  _  \  /'__`\  /' _ `\  /'_` \/\ \/\ \/\ \/\ \/\`'__\/'__`\ /'_` \     \ \ \ \ \ , <  \ \ \  __
  \ \ \ \ \/\ \L\.\_/\ \/\ \/\ \L\ \ \ \_/ \_/ \ \ \ \ \//\  __//\ \L\ \     \ \ \ \ \ \\`\ \ \ \L\ \
   \ \_\ \_\ \__/.\_\ \_\ \_\ \___,_\ \___x___/'\ \_\ \_\\ \____\ \___,_\     \ \_\ \ \_\ \_\\ \____/
    \/_/\/_/\/__/\/_/\/_/\/_/\/__,_ /\/__//__/   \/_/\/_/ \/____/\/__,_ /      \/_/  \/_/\/_/ \/___/

                                                                 -< customised by ocodo >-

 Features :

 - Caps       == Ctrl when held, Backspace when tapped (stolen idea from
                Dvorak layout plus dual purpose keys) (Caps is on FN1 + Caps)

 - Return     == Return when tapped / Ctrl when held as modifier

 - Tab        == Tab when tapped / Alt when held as modifier

 - Backslash  == Backslash when tapped / Alt when held as modifier

 - Backtick   == Backtick (tap) / Gui/Cmd/Super when held as a modifier

 - Backspace  == Backspace (tap) / Gui/Cmd/Super when held as a modifier

 */

enum macro_id {
  M_NOM,
  M_EML,
  M_GHB,
  M_PIV,
  M_PNM,
  M_PSG,
  M_HTP,
  M_SSL
};

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Ctrl or Backspace
#define CTLBSPC MT(MOD_LCTL, KC_BSPC)

// Ctrl or Return
#define CTLENTR MT(MOD_LCTL, KC_ENT)

// Alt or Tab
#define ALTTAB MT(MOD_LALT, KC_TAB)

// Alt or Backslash
#define ALTBSLS MT(MOD_LALT, KC_BSLS)

// GUI or Tilde
#define GUITLD MT(MOD_LGUI, KC_GRV)

// GUI or Backspace
#define GUIBSPC MT(MOD_LGUI, KC_BSPC)

// Numpad short cuts
#define N_PLUS KC_KP_PLUS
#define N_SLSH KC_KP_SLASH
#define N_MNUS KC_KP_MINUS
#define N_ASTK KC_KP_ASTERISK

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0: QWERTY+ */
  /*
   ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┬─────┬─────╮  ╭────┬────┬────╮
   │ ESC│ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │ F7 │ F8 │ F9 │ F10 │ F11 │ F12 │  │PSCR│SLCK│PAUS│
   ├────┴────┼───┬┴──┬─┴─┬──┴┬───┼───┬┴──┬─┴─┬──┴┬───┼───┬─┴─┬───┴─────┤  ├────┼────┼────┤
   │ GUI / ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ─ │ = │ GUI/BSPC│  │ INS│HOME│PGUP│
   ├─────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────────┤  ├────┼────┼────┤
   │ ALT/TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ ALT/BSLS│  │ DEL│ END│PGDN│
   ├─────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────────┤  ╰────┴────┴────╯
   │ CTL/BSPC │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  CTL/ENT   │
   ├──────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────────┤       ╭────╮
   │ LSHIFT    │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │      RSHIFT   │       │ UP │
   ├─────┬────┬┴───┴─┬─┴───┴───┴───┴───┴───┴───┼───┴──┬┴───┬────┬──────┤  ╭────┼────┼────╮
   │ LCTL│LALT│ LGUI │           SPC           │ RGUI │RALT│ FN │ RCTL │  │LEFT│DOWN│RGHT│
   ╰─────┴────┴──────┴─────────────────────────┴──────┴────┴────┴──────╯  ╰────┴────┴────╯
  */
  KEYMAP(\
          KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK,  KC_BRK, \
          GUITLD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, GUIBSPC,        KC_INS, KC_HOME, KC_PGUP, \
          ALTTAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, ALTBSLS,        KC_DEL,  KC_END, KC_PGDN, \
         CTLBSPC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,          CTLENTR, \
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,                   KC_RSFT,                  KC_UP, \
         KC_LCTL, KC_LALT, KC_LGUI,                    KC_SPC,                                     KC_RGUI, KC_RALT,   MO(1), KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT),

  /* Layer 1: FN0 - When FN is held down */
  /*
   ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┬─────┬─────╮  ╭────┬────┬────╮
   │    │ NM │ EM │ GH │ HT │ SL │    │ << │ I> │ >> │ MUT │ VUP │ VDN │  │ PN │ PV │    │
   ├────┴────┼───┬┴──┬─┴─┬──┴┬───┼───┬┴──┬─┴─┬──┴┬───┼───┬─┴─┬───┴─────┤  ├────┼────┼────┤
   │         │ A │ B │ C │ D │ E │ F │   │   │   │   │   │   │         │  │    │    │    │
   ├─────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────────┤  ├────┼────┼────┤
   │         │ 7 │ 8 │ 9 │ + │ ─ │   │   │   │   │   │   │   │         │  │    │    │    │
   ├─────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────────┤  ╰────┴────┴────╯
   │ CAPSLOCK │ 4 │ 5 │ 6 │ / │ * │   │   │   │   │   │   │            │
   ├──────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────────┤       ╭────╮
   │           │ 1 │ 2 │ 3 │ 0 │ . │   │   │   │   │   │               │       │    │
   ├─────┬────┬┴───┴─┬─┴───┴───┴───┴───┴───┴───┼───┴──┬┴───┬────┬──────┤  ╭────┼────┼────╮
   │     │    │ENTER │            L2           │      │    │    │  APP │  │    │    │    │
   ╰─────┴────┴──────┴─────────────────────────┴──────┴────┴────┴──────╯  ╰────┴────┴────╯
  */
  KEYMAP(\
         M(M_NOM),        M(M_NOM),M(M_EML),M(M_GHB),M(M_HTP),M(M_SSL), KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,      M(M_PNM),M(M_PIV), KC_TRNS, \
         KC_TRNS,    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS,    KC_7,    KC_8,    KC_9,  N_PLUS,  N_MNUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_CAPS,    KC_4,    KC_5,    KC_6,  N_SLSH,  N_ASTK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, \
         KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_0,  KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                KC_TRNS, \
         KC_TRNS, KC_TRNS,  KC_ENT,                     TG(2),                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_APP,        KC_TRNS, KC_TRNS, KC_TRNS),

  /* Layer 2: Mouse keys */
  // Ref:
  // `KC_MS_U`, `KC_MS_D`, `KC_MS_L`, `KC_MS_R`            for mouse cursor
  // `KC_WH_U`, `KC_WH_D`, `KC_WH_L`, `KC_WH_R`            for mouse wheel
  // `KC_BTN1`, `KC_BTN2`, `KC_BTN3`, `KC_BTN4`, `KC_BTN5` for mouse buttons
  /*
  ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┬─────┬─────╮  ╭────┬────┬────╮
  │    │ NM │ EM │ GH │ HT │ SL │ PN │ PV │    │    │ L3  │ L4  │ L5  │  │ BT3│ BT4│ BT5│
  ├────┴────┼───┬┴──┬─┴─┬──┴┬───┼───┬┴──┬─┴─┬──┴┬───┼───┬─┴─┬───┴─────┤  ├────┼────┼────┤
  │         │ A │ B │ C │ D │ E │ F │   │   │   │   │   │   │         │  │ WL │ WU │ WR │
  ├─────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────────┤  ├────┼────┼────┤
  │         │ 7 │ 8 │ 9 │ + │ ─ │   │   │   │   │   │   │   │         │  │ BT1│ WD │ BT2│
  ├─────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────────┤  ╰────┴────┴────╯
  │          │ 4 │ 5 │ 6 │ / │ * │   │   │   │   │   │   │            │
  ├──────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────────┤       ╭────╮
  │           │ 1 │ 2 │ 3 │ 0 │ . │   │   │   │   │   │               │       │ MU │
  ├─────┬────┬┴───┴─┬─┴───┴───┴───┴───┴───┴───┼───┴──┬┴───┬────┬──────┤  ╭────┼────┼────╮
  │     │    │ENTER │                         │      │    │    │      │  │ ML │ MD │ MR │
  ╰─────┴────┴──────┴─────────────────────────┴──────┴────┴────┴──────╯  ╰────┴────┴────╯
  */ // Suppose you need to visualise a keyboard layout or some thing
     // else which needs alignment over a lot of tables...
  KEYMAP(\
         KC_TRNS,         M(M_NOM),M(M_EML),M(M_GHB),M(M_HTP),M(M_SSL), M(M_PNM),M(M_PIV),KC_TRNS, KC_TRNS, TG(3),     TG(4),   TG(5),       KC_BTN3, KC_BTN4, KC_BTN5, \
         KC_TRNS,    KC_A,    KC_B,    KC_C,    KC_D,    KC_E,    KC_F, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_WH_L, KC_WH_U, KC_WH_R, \
         KC_TRNS,    KC_7,    KC_8,    KC_9,  N_PLUS,  N_MNUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_BTN1, KC_WH_D, KC_BTN2, \
         KC_TRNS,    KC_4,    KC_5,    KC_6,  N_SLSH,  N_ASTK, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, \
         KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_0,  KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                KC_MS_U, \
         KC_TRNS, KC_TRNS,  KC_ENT,                   KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_MS_L, KC_MS_D, KC_MS_R),

  /* unmodified layer template
  KEYMAP(\
         KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS)
  */

  /* COLEMAK_LAYER *
   ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┬─────┬─────╮  ╭────┬────┬────╮
   │ESC │ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │ F7 │ F8 │ F9 │ F10 │ F11 │ F12 │  │PSCR│SLCK│PAUS│
   ├────┴────┼───┬┴──┬─┴─┬──┴┬───┼───┬┴──┬─┴─┬──┴┬───┼───┬─┴─┬───┴─────┤  ├────┼────┼────┤
   │ GUI / ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ GUI/BSPC│  │ INS│HOME│PGUP│
   ├─────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────────┤  ├────┼────┼────┤
   │ ALT/TAB │ Q │ W │ F │ P │ G │ J │ L │ U │ Y │ ; │ [ │ ] │ ALT/BSLS│  │ DEL│ END│PGDN│
   ├─────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────────┤  ╰────┴────┴────╯
   │ CTL/BSPC │ A │ R │ S │ T │ D │ H │ N │ E │ I │ O │ ' │  CTL/ENT   │
   ├──────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────────┤       ┌────╮
   │ LSHIFT    │ Z │ X │ C │ V │ B │ K │ M │ , │ . │ / │      RSHIFT   │       │ UP │
   ├─────┬────┬┴───┴─┬─┴───┴───┴───┴───┴───┴───┼───┴──┬┴───┬────┬──────┤  ╭────┼────┼────╮
   │ LCTL│LALT│ LGUI │           SPC           │ RGUI │RALT│ FN │ RCTL │  │LEFT│DOWN│RGHT│
   ╰─────┴────┴──────┴─────────────────────────┴──────┴────┴────┴──────╯  ╰────┴────┴────╯
  */
  KEYMAP(
          KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS, \
          GUITLD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, GUIBSPC,        KC_INS, KC_HOME, KC_PGUP, \
          ALTTAB,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_LBRC, KC_RBRC, ALTBSLS,        KC_DEL,  KC_END, KC_PGDN, \
         CTLBSPC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,          CTLENTR, \
         KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,                   KC_RSFT,                  KC_UP, \
         KC_LCTL, KC_LALT, KC_LGUI,                    KC_SPC,                                     KC_RGUI, KC_RALT,   MO(1), KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT),

  /* DVORAK_LAYER *
   ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┬─────┬─────╮  ╭────┬────┬────╮
   │ESC │ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │ F7 │ F8 │ F9 │ F10 │ F11 │ F12 │  │PSCR│SLCK│PAUS│
   ├────┴────┼───┬┴──┬─┴─┬──┴┬───┼───┬┴──┬─┴─┬──┴┬───┼───┬─┴─┬───┴─────┤  ├────┼────┼────┤
   │ GUI / ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ [ │ ] │ GUI/BSPC│  │ INS│HOME│PGUP│
   ├─────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────────┤  ├────┼────┼────┤
   │ ALT/TAB │ ' │ , │ . │ P │ Y │ F │ G │ C │ R │ L │ / │ ─ │ ALT/BSLS│  │ DEL│ END│PGDN│
   ├─────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────────┤  ╰────┴────┴────╯
   │ CTL/BSPC │ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │ - │    CTL/ENT │
   ├──────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────────┤       ╭────╮
   │ LSHIFT    │ ; │ Q │ J │ K │ X │ B │ M │ W │ V │ Z │        RSHIFT │       │ UP │
   ├─────┬────┬┴───┴─┬─┴───┴───┴───┴───┴───┴───┼───┴──┬┴───┬────┬──────┤  ╭────┼────┼────╮
   │ LCTL│LALT│ LGUI │           SPC           │ RGUI │RALT│ FN │ RCTL │  │LEFT│DOWN│RGHT│
   ╰─────┴────┴──────┴─────────────────────────┴──────┴────┴────┴──────╯  ╰────┴────┴────╯
  */
  KEYMAP(
          KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,       KC_PSCR, KC_SLCK, KC_PAUS, \
          GUITLD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_LBRC, KC_RBRC, GUIBSPC,        KC_INS, KC_HOME, KC_PGUP, \
          ALTTAB, KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L, KC_SLSH,  KC_EQL, ALTBSLS,        KC_DEL,  KC_END, KC_PGDN, \
         CTLBSPC,    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S, KC_MINS,          CTLENTR, \
         KC_LSFT, KC_SCLN,    KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,                   KC_RSFT,                  KC_UP, \
         KC_LCTL, KC_LALT, KC_LGUI,                    KC_SPC,                                     KC_RGUI, KC_RALT,   MO(1), KC_RCTL,       KC_LEFT, KC_DOWN, KC_RGHT),

  /* WORKMAN_LAYER *
   ╭────┬────┬────┬────┬────┬────┬────┬────┬────┬────┬─────┬─────┬─────╮  ╭────┬────┬────╮
   │ESC │ F1 │ F2 │ F3 │ F4 │ F5 │ F6 │ F7 │ F8 │ F9 │ F10 │ F11 │ F12 │  │PSCR│SLCK│PAUS│
   ├────┴────┼───┬┴──┬─┴─┬──┴┬───┼───┬┴──┬─┴─┬──┴┬───┼───┬─┴─┬───┴─────┤  ├────┼────┼────┤
   │ GUI / ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ ─ │ = │ GUI/BSPC│  │ INS│HOME│PGUP│
   ├─────────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┼─────────┤  ├────┼────┼────┤
   │ ALT/TAB │ Q │ D │ R │ W │ B │ J │ F │ U │ P │ ; │ [ │ ] │ ALT/BSLS│  │ DEL│ END│PGDN│
   ├─────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────────┤  ╰────┴────┴────╯
   │ CTL/BSPC │ A │ S │ H │ T │ G │ Y │ N │ E │ O │ I │ ' │  CTL/ENT   │
   ├──────────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────────────┤       ╭────╮
   │ LSHIFT    │ Z │ X │ M │ C │ V │ K │ L │ , │ . │ / │      RSHIFT   │       │ UP │
   ├─────┬────┬┴───┴─┬─┴───┴───┴───┴───┴───┴───┼───┴──┬┴───┬────┬──────┤  ╭────┼────┼────╮
   │ LCTL│LALT│ LGUI │           SPC           │ RGUI │RALT│ FN │ RCTL │  │LEFT│DOWN│RGHT│
   ╰─────┴────┴──────┴─────────────────────────┴──────┴────┴────┴──────╯  ╰────┴────┴────╯
   */
   KEYMAP(
          KC_ESC,            KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,   KC_F12,      KC_PSCR, KC_SLCK, KC_PAUS, \
          GUITLD,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  GUIBSPC,       KC_INS, KC_HOME, KC_PGUP, \
          ALTTAB,    KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P, KC_SCLN, KC_LBRC, KC_RBRC,  ALTBSLS,       KC_DEL,  KC_END, KC_PGDN, \
         CTLBSPC,    KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,    KC_I, KC_QUOT,           CTLENTR, \
         KC_LSFT,    KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L, KC_COMM,  KC_DOT, KC_SLSH,                    KC_RSFT,                 KC_UP, \
         KC_LCTL, KC_LALT, KC_LGUI,                    KC_SPC,                                     KC_RGUI, KC_RALT,  MO(1),   KC_RCTL,      KC_LEFT, KC_DOWN, KC_RGHT),

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
  }

  return MACRO_NONE;
};
