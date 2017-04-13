#include "satan.h"

#define _QWERTY 0
#define _LSFT   1
#define _LALT   2
#define _SPC  3
#define _CTL  4

// Fillers to make layering more clear
#define ______ KC_TRNS
#define XXXXXXX KC_NO

// Func macro definitions.
#define S_LED     FUNC(0)
#define S_LEDI    FUNC(1)
#define S_LEDD    FUNC(2)
#define FN_SPC    FUNC(3)
#define FN_LSFT     FUNC(4)
#define FN_RSFT     FUNC(5)
#define FN_LALT     FUNC(6)


// Enable these functions using FUNC(n) macro.
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_BACKLIGHT_TOGGLE(),
  [1] = ACTION_BACKLIGHT_INCREASE(),
  [2] = ACTION_BACKLIGHT_DECREASE(),
  [3] = ACTION_LAYER_TAP_KEY(_SPC, KC_SPACE),
  [4] = ACTION_LAYER_MODS(_LSFT, MOD_LSFT),
  [5] = ACTION_LAYER_MODS(_LSFT, MOD_RSFT),
  [6] = ACTION_LAYER_MODS(_LALT, MOD_LALT)
 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = KEYMAP_ANSI( /* Basic QWERTY */
      KC_ESC,     KC_1,     KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,  KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  \
      KC_TAB,     KC_Q,     KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,  KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  \
      KC_LCTL,    KC_A,     KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,  KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   \
      FN_LSFT,              KC_Z,     KC_X,    KC_C,     KC_V,     KC_B,     KC_N,    KC_M,  KC_COMM,  KC_DOT,   KC_SLSH,            FN_RSFT,  \
      KC_CAPS,    FN_LALT,  KC_LGUI,                     FN_SPC,                                       KC_RGUI,  KC_RALT,  KC_RCTL,  MO(_SPC)  \
      ),

  [_LSFT] = KEYMAP_ANSI( /* Layer LSFT */
      KC_GRV,     ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  \
      ______,     ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  \
      ______,     ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           ______,  \
      FN_LSFT,             ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,  ______,           FN_RSFT, \
      ______,     ______,  ______,                    ______,                                      ______,  ______, ______, ______   \
      ),

  [_LALT] = KEYMAP_ANSI( /* Layer SpaceFn */
      KC_GRV,     ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,  \
      ______,     ______,  ______, ______, ______, ______, ______, ______, ______, KC_GRV,   KC_E, ______, ______, ______,  \
      ______,     ______,  ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         ______,  \
      KC_LSFT,             ______, ______, ______, ______, ______, ______, ______, ______, ______, ______,         KC_RSFT, \
      ______,     FN_LALT, ______,                 ______,                                 ______, ______, ______, ______ \
      ),

  [_SPC] = KEYMAP_ANSI( /* Layer SpaceFn */
        KC_ESC,      KC_F1,   KC_F2,    KC_F3,   KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,  \
        ______,     ______,  ______,   ______,  ______,   ______,   ______,   ______,    KC_UP,     KC_O,      KC_P,   ______,   ______,   ______,  \
        ______,     ______,  ______,   KC_DEL,  ______,   ______,   ______,  KC_LEFT,  KC_DOWN, KC_RIGHT,   KC_BSPC,   ______,             ______,  \
       KC_LSFT,              S_LED,   S_LEDI,  S_LEDD,   ______,   ______,   ______,   ______,   ______,    ______,   ______,             ______,  \
        ______,     ______,  ______,                 ______,                                                 ______,   ______,   ______,   ______   \
      ),

  [_CTL] = KEYMAP_ANSI( /* Layer 2 */
      KC_ESC,         KC_1,     KC_2,    KC_3,    KC_4,     KC_5,      KC_6,     KC_7,     KC_8,    KC_9,       KC_0, KC_MINS,   KC_EQL,   KC_BSPC, \
      KC_TAB,         KC_Q,     KC_W,    KC_E,    KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,    KC_O,       KC_P, KC_LBRC,  KC_RBRC,   KC_BSLS, \
      KC_LCTL,        KC_A,     KC_S,    KC_D,    KC_F,     KC_G,      KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,              KC_ENT, \
      KC_LSFT,                  KC_Z,    KC_X,    KC_C,     KC_V,      KC_B,     KC_N,     KC_M, KC_COMM,     KC_DOT, KC_SLSH,             KC_RSFT, \
      ______,      KC_LALT,  KC_LGUI,                       KC_SPC,                                          KC_RGUI, KC_RALT,  KC_RCTL,    ______  \
      ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  return MACRO_NONE;
}
