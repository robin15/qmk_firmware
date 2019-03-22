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

#define EISU LALT(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  `   |   1  |   2  |   3  |   4  |   5  |Pscree|                    |   +  |   6  |   7  |   8  |   9  |   0  |  -   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |    [ |                    |   ]  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |      |                    |   B  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | TG(2)|                    | Bksp |   N  |   M  |   ,  |   .  |  Up  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Esc  |  GUI |  Alt | EISU | MO(1)| Del  | MO(3)|      ||||||||      |ct+a+d| Space| Enter|Pscree| Left | Down | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,     KC_PSCR,  KC_EQL,   KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, \
	  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,     KC_LBRC,  KC_RBRC,  KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS, \
		KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,     KC_GRV,   KC_B,     KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,     KC_DEL,   KC_BSPC,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, \
		KC_ESC,  KC_LGUI, KC_LALT, EISU,    RAISE,  LOWER,    ADJUST,   KC_BSPC,  KC_ENT,  KC_SPC, RAISE,   KC_LEFT, KC_DOWN, KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |NumLck|   /  |   *  |   -  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |   7  |   8  |   9  |   +  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |  Up  |      |   4  |   5  |   6  |   ,  |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    | Left | Down | Right|   1  |   2  |   3  |   =  |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |      |      |      |      ||||||||      |      |      |      |   0  |      |   .  |Enter |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
	[_LOWER] = LAYOUT( \
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
	  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_P4,   KC_P5,   KC_P6,   KC_PCMM, \
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, \
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_P0,   KC_NO,   KC_PDOT, KC_PENT  \
  ),

  /*
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |      |                    |      |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |PageUp| Bak  |  Up  | Fwd  |      |      | F12  |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |PageDn| Left | Down | Right|      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |   1  |   2  |   3  |   4  |   5  |      |                    | Bksp |   6  |   7  |   8  |   9  |   0  |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      |      |      |      |      ||||||||      |      |      |      |      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
	[_RAISE] = LAYOUT( \
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_NO,   KC_NO,   KC_F6,   KC_F7,         KC_F8,   KC_F9,         KC_F10,  KC_F11, \
	  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGUP, LALT(KC_LEFT), KC_UP,   LALT(KC_RGHT), KC_NO,   KC_F12, \
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_PGDN, KC_LEFT,       KC_DOWN, KC_RGHT,       KC_NO,   KC_NO,  \
		KC_NO,   KC_1 ,   KC_2,    KC_3 ,   KC_4 ,   KC_5,    KC_NO,   KC_NO,   KC_6,    KC_7 ,         KC_8,    KC_9,          KC_0,    KC_NO,  \
		KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,   KC_NO,         KC_NO,   KC_NO   \
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
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
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
