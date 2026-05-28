/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#define DUAL_FUNC_0 LT(13, KC_X)
#define DUAL_FUNC_1 LT(3, KC_Y)
#define DUAL_FUNC_2 LT(3, KC_J)
#define DUAL_FUNC_3 LT(7, KC_F4)
#define DUAL_FUNC_4 LT(4, KC_V)
#define DUAL_FUNC_5 LT(1, KC_N)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_NO,
        XXXXXXX, MT(MOD_LCTL, KC_A), MT(MOD_LSFT, KC_S), KC_D,   KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    MT(MOD_RSFT,KC_L), MT(MOD_RCTL,KC_SCLN), KC_QUOT,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    MT(MOD_LGUI,KC_V), MT(MOD_LALT,KC_B),       KC_N,    KC_M, KC_COMM, KC_DOT, KC_SLASH,  KC_ESC,
                                              KC_LGUI, LT(3, KC_SPACE),  MO(2),                                     LT(1,KC_BSPC),   KC_SPACE, KC_TAB
    ),

    [1] = LAYOUT_split_3x6_3(
        XXXXXXX, KC_1,     KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
        XXXXXXX, KC_EXCLAIM, KC_AT, KC_HASH, KC_DLR, KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
        XXXXXXX, S(KC_7),  S(KC_3), S(KC_4), XXXXXXX, XXXXXXX,       MT(MOD_RALT,KC_LBRC), KC_RBRC, S(KC_9), S(KC_0), S(KC_1), XXXXXXX,
                                                          KC_LGUI, KC_TRANSPARENT, KC_LCTL,       _______, KC_TRANSPARENT, KC_TAB
    ),

    [2] = LAYOUT_split_3x6_3(
        KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE, KC_TRANSPARENT,       KC_PAGE_UP, KC_UP, KC_DELETE, KC_MINUS, KC_EQUAL, KC_TRANSPARENT,
        KC_TRANSPARENT, KC_LEFT_CTRL,   KC_LEFT_SHIFT,    KC_MEDIA_STOP, KC_MEDIA_PLAY_PAUSE, KC_TRANSPARENT,       KC_LEFT,    KC_DOWN, KC_RIGHT,    KC_LBRC,  KC_RBRC,  KC_TRANSPARENT,
        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,   KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,       MT(MOD_RALT, KC_PGDN), LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_DQUO, KC_BSLS, KC_TRANSPARENT,
                                                                                       KC_LGUI, KC_TRANSPARENT, _______,       KC_ENT, KC_LALT, KC_RALT
    ),

    [3] = LAYOUT_split_3x6_3(
        KC_TRANSPARENT, RALT(KC_1), RALT(KC_2), RALT(KC_3), RALT(KC_4), RALT(KC_5),       KC_TRANSPARENT, KC_5, KC_MINUS, RALT(KC_4), RALT(KC_EQUAL), KC_TRANSPARENT,
        KC_TRANSPARENT, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRANSPARENT, KC_TRANSPARENT,       KC_TRANSPARENT, RALT(KC_5), RALT(KC_MINUS), KC_6, RSFT(KC_EQUAL), KC_TRANSPARENT,
        KC_TRANSPARENT, RGB_HUD, RGB_SAD, RGB_VAD, RGBLIGHT_MODE_CHRISTMAS, RGBLIGHT_MODE_RGB_TEST,       KC_TRANSPARENT, KC_LABK, KC_RABK, KC_TRANSPARENT, KC_EQUAL, KC_TRANSPARENT,
                                                                                       KC_LGUI, _______, KC_SPC,       KC_ENT, KC_TRANSPARENT, KC_RALT
    )
};

const uint16_t PROGMEM echap[] = {KC_F, KC_D, COMBO_END};
combo_t key_combos[] = {
    COMBO(echap, KC_CAPS),
};
