#ifndef OCODO_H
#define OCODO_H

// Includes
#include <stdint.h>
#include <stdbool.h>

// Keymap macros
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

// Macro IDs
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

// Function prototypes
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt);
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt);

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// Function IDs
enum function_id {
  SHIFT_ESC,
};

// Function prototype for function actions
extern const uint16_t PROGMEM fn_actions[];

#endif // OCODO_H
