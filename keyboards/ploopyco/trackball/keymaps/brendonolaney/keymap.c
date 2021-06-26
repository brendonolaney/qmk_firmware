/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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

enum brendon_keycodes {
    COPY = PLOOPY_SAFE_RANGE,
    PASTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, KC_BTN3, KC_BTN2,
          COPY, MO(1)
    ),
    [1] = LAYOUT(
        DRAG_SCROLL, _______, _______,
          PASTE, _______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("c"));
            }
            return false;
            break;
        case PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI("v"));
            }
            return false;
            break;
    }
    return true;
}
