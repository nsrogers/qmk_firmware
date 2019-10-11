/* Copyright 2019 robotcanadia
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { QMKBEST = SAFE_RANGE, QMKURL };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base layer */
    KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE,\
	KC_GRAVE, KC_1, KC_2,  KC_3,  KC_4,  KC_5,  KC_6, KC_7,  KC_8,  KC_9,  KC_0, KC_MINUS, KC_EQUAL, KC_BSPACE,        KC_INSERT, KC_HOME,KC_PGUP,KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS,\
	KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U, KC_I, KC_O, KC_P,KC_LBRACKET,KC_RBRACKET,KC_BSLASH,KC_DELETE,KC_END,KC_PGDOWN,KC_KP_7,   KC_KP_8,   KC_KP_9,   KC_KP_PLUS,\
	KC_CAPSLOCK, KC_A, KC_S,   KC_D,   KC_F,   KC_G, KC_H,   KC_J, KC_K,   KC_L, KC_SCOLON,   KC_QUOTE, KC_ENTER,KC_KP_4,   KC_KP_5,   KC_KP_6,\
    KC_LSHIFT, KC_Z, KC_X,   KC_C,   KC_V,   KC_B, KC_N,   KC_M, KC_COMMA,   KC_DOT, KC_SLASH,   KC_RSHIFT,   KC_UP, KC_KP_1,   KC_KP_2,   KC_KP_3,   KC_KP_ENTER,\
    KC_LCTRL, KC_LGUI, KC_LALT,  KC_SPACE, KC_RALT, KC_APPLICATION,  KC_RGUI, KC_RCTRL, KC_LEFT,   KC_DOWN,   KC_RIGHT,KC_KP_0,     KC_KP_DOT\
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/" SS_TAP(X_ENTER));
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

void led_set_user(uint8_t usb_led) {}
