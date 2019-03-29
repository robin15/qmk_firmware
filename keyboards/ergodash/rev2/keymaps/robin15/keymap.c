#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

#define EISU      (LALT(KC_GRV))
#define CT_AL_DE  (LALT(LCTL(KC_DEL)))
#define RAISE_SPC (LT(RAISE,KC_SPC))
#define SFT_SPC   (SFT_T(KC_SPC))
#define ALT_PSCR  (ALT_T(KC_PSCR))
#define CT_TB     (LCTL(KC_TAB))
#define SFT_CT_TB (LSFT(LCTL(KC_TAB)))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |  `   |                    |   +  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |  '   |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |BackSp|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |  [   |                    |   B  |   H  |   J  |   K  |   L  |   ;  | Enter|
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |ADJUST|                    | Del  |   N  |   M  |   ,  |   .  |  Up  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ins  |  GUI |  Alt | EISU ||||||||RAS+Sp|LOWER |C+A+D ||||||||ct+a+d|BackSp|SFT+Sp||||||||ALT+Ps| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,      KC_5,     KC_GRV,   KC_EQL,  KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,      KC_T,     KC_QUOT,  KC_BSLS, KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,      KC_G,     KC_LBRC,  KC_RBRC, KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,      KC_B,     ADJUST,   KC_DEL,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
    KC_INS,  KC_LGUI, KC_LALT, EISU,    RAISE_SPC, LOWER,    CT_AL_DE, KC_ENT,  KC_BSPC, SFT_SPC, ALT_PSCR,   KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | C+Tb |C+S+Tb|      |      |      |      |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO, KC_NO, KC_NO,  \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   SFT_CT_TB, CT_TB,   KC_NO, KC_NO, KC_NO,  \
    KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,   KC_NO,   KC_6,    KC_7,      KC_8,    KC_9,  KC_0,  KC_NO,  \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO, KC_NO, KC_NO,  \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO, KC_NO, KC_NO  \
  ),

  /*
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      | F12  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      | Left | Down |  Up  | Right|Alt+L |Alt+R |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    |PageUp|   6  |   7  |   8  |   9  |   0  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |PageDn|      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_F12,        \
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,   KC_NO,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,        KC_F11,        \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, RALT(KC_LEFT), RALT(KC_RGHT), \
    KC_NO,   KC_1 ,   KC_2,    KC_3 ,   KC_4 ,   KC_5,    KC_NO,   KC_PGUP, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,          KC_NO,         \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_PGUP, KC_NO,   KC_NO,   KC_NO,         KC_NO          \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       RGB_MODE_PLAIN, RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_GRADIENT, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, RGB_SPD, RGB_SPI, _______, _______, _______, _______, \
    _______, _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
