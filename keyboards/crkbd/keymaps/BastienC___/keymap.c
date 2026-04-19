#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_NO,    KC_A,    KC_Z,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
   KC_NO,KC_Q, MT(MOD_LCTL,KC_S),MT(MOD_LALT,KC_D),MT(MOD_LGUI,KC_F),KC_G,     KC_H, MT(MOD_LGUI,KC_J), MT(MOD_LALT,KC_K), MT(MOD_LCTL,KC_L), KC_M, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, MT(MOD_LSFT,KC_W), KC_X, KC_C,KC_V,    KC_B,                         KC_N, KC_SCLN, KC_SLSH,  KC_COMM, MT(MOD_LSFT,KC_DOT),  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_TAB
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_NO,  KC_ESC, KC_GRV,  KC_QUOT, KC_BSLS, KC_MINS,                     KC_NO,    S(KC_6),    S(KC_2), KC_EQL, KC_BSPC, KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, S(KC_7), KC_LCTL, KC_LALT, KC_LGUI, KC_NO,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, S(KC_8), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, S(KC_7), S(KC_3), S(KC_4), XXXXXXX, XXXXXXX,                      KC_LBRC, KC_RBRC,  S(KC_9),  S(KC_0),  S(KC_1), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_LCTL,     KC_LSFT,   KC_LALT, KC_TAB
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       XXXXXXX, KC_F9,   KC_F10, KC_F11,  KC_F12, S(KC_EQL),                      KC_PAST, KC_7, KC_8, KC_9, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F5, KC_LCTL, KC_LALT, KC_LGUI, KC_PMNS,                      KC_PSLS,  KC_4,    KC_5,    KC_6,   S(KC_5),  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_F1,   KC_F2,    KC_F3, KC_F4, KC_PEQL,                      KC_0,   KC_1,     KC_2,    KC_3,    S(KC_SCLN), KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_LCTL,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};
/*
void keyboard_post_init_user(void) {
    rgblight_enable(); // Enables RGB lighting
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT); // Sets static color mode
    rgblight_sethsv(32, 178, 170); // Set color to blue
}
*/

// Combos

enum combo_events {
    RETURN_COMBO,
    SELECT_COMBO,
    FROM_COMBO,
    RANGE_COMBO,
    TEST_COMBO,
};

const uint16_t PROGMEM return_combo[] = { KC_R, KC_T, KC_N, COMBO_END };
const uint16_t PROGMEM select_combo[] = { KC_S, KC_L, KC_T, COMBO_END };
const uint16_t PROGMEM from_combo[] = { KC_F, KC_O, KC_M, COMBO_END };
const uint16_t PROGMEM range_combo[] = { KC_R, KC_G, KC_N, COMBO_END };
const uint16_t PROGMEM test_combo[] = { KC_A, KC_P, COMBO_END };

combo_t key_combos[] = {
    [RETURN_COMBO] = COMBO_ACTION(return_combo),
    [SELECT_COMBO] = COMBO_ACTION(select_combo),
    [FROM_COMBO] = COMBO_ACTION(from_combo),
    [RANGE_COMBO] = COMBO_ACTION(range_combo),
    [TEST_COMBO] = COMBO_ACTION(test_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case RETURN_COMBO:
      if (pressed) {
        SEND_STRING("return");
      }
      break;
      
      case SELECT_COMBO:
      if (pressed) {
        SEND_STRING("select");
      }
      break;
      
      case FROM_COMBO:
      if (pressed) {
        SEND_STRING("from");
      }
      break;
      
      case RANGE_COMBO:
      if (pressed) {
        SEND_STRING("range");
      }
      break;

      case TEST_COMBO:
      if (pressed) {
        SEND_STRING("testing");
      }
      break;
  }
}



