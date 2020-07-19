/* Copyright 2015-2017 Jack Humbert
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
 *
 */

#include QMK_KEYBOARD_H
#include "muse.h"

enum planck_layers
{
    _BASE,
    _NAV,
    _NUM,
    _SYM,
    _BRC,
    _FNC,
    _MED,
    _ADJ,
};

#define NAV MO(_NAV)
#define NUM MO(_NUM)
#define SYM MO(_SYM)
#define BRC MO(_BRC)
#define FNC MO(_FNC)
#define MED MO(_MED)
#define ADJ MO(_ADJ)

enum nav_keycodes
{
    NBOL = SAFE_RANGE,
    NEOL,
    NBWRD,
    NFWRD,
    NBDWRD,
    NDWRD,
    NUNDO,
    NCUT,
    NCOPY,
    NPASTE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Enter|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Meh  | Alt  | GUI  | Nav  | Num  |    Space    | Sym  | Brac |  Fn  | Media| Hyper|
    * `-----------------------------------------------------------------------------------'
    */
    [_BASE] = LAYOUT_planck_grid(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_MEH,  KC_LALT, KC_LGUI, NAV,     NUM,     KC_SPC,  KC_SPC,  SYM,     BRC,     FNC,     MED,     KC_HYPR
    ),

    /* NAV
    * ,-----------------------------------------------------------------------------------.
    * | Esc  | Ins  | BdWrd|      | DWrd |      |  BOL | Bwrd |  Up  | Fwrd |  EOL | Del  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |      | Bdel |      | Del  |      | Home | Left | Down | Right|  END | Enter|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift| Undo | Cut  | Copy | Paste|      |      |      |      |      |      | Shift|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Meh  | Alt  | GUI  | Nav  | Num  |    Space    | Sym  | Brac |  Fn  | Media| Hyper|
    * `-----------------------------------------------------------------------------------'
    */
    [_NAV] = LAYOUT_planck_grid(
        KC_ESC,  KC_INS,  NBDWRD,  XXXXXXX, NDWRD,   XXXXXXX, NBOL,    NBWRD,   KC_UP,   NFWRD,   NEOL,    KC_DEL,
        _______, XXXXXXX, KC_BSPC, XXXXXXX, KC_DEL,  XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
        _______, NUNDO,   NCUT,    NCOPY,   NPASTE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* NUM
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |      |      |      |      |      |      |   4  |   5  |   6  |      |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|      |      |      |      |      |   0  |   1  |   2  |   3  |      |Shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Hyper| Meh  | Alt  | GUI  | Num  |    Space    | Sym  | Brac | Fn   |Media | Adj  |
    * `-----------------------------------------------------------------------------------'
    */
    [_NUM] = LAYOUT_planck_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_0   , KC_1,    KC_2,    KC_3,    XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* SYM
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |      |      |      |      |      |      |   -  |   =  |   '  |   \  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|      |      |      |      |      |      |   _  |   +  |   "  |   |  |Shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Hyper| Meh  | Alt  | GUI  | Num  |    Space    | Sym  | Brac | Fn   |Media | Adj  |
    * `-----------------------------------------------------------------------------------'
    */
    [_SYM] = LAYOUT_planck_grid(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL,  KC_QUOT, KC_BSLS, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_DQUO, KC_PIPE, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Brackets
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   '  |   "  |   (  |   )  |      |      |      |      |      |      | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |   <  |   >  |   [  |   ]  |      |      |      |      |      |      |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|      |      |   {  |   }  |      |      |      |      |      |      |Shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Hyper| Meh  | Alt  | GUI  | Num  |    Space    | Sym  | Brac | Fn   |Media | Adj  |
    * `-----------------------------------------------------------------------------------'
    */
    [_BRC] = LAYOUT_planck_grid(
        KC_TAB,  KC_QUOT, KC_DQUO, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        _______, KC_LT,   KC_GT,   KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Function
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |  F5  |  F6  |  F7  |  F8  |      |      |PrScr |ScrLk |Pause |      |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|  F9  |  F10 |  F11 |  F12 |      |      |      |NumLk |CapLk |      |Shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Hyper| Meh  | Alt  | GUI  | Num  |    Space    | Sym  | Brac | Fn   |Media | Adj  |
    * `-----------------------------------------------------------------------------------'
    */
    [_FNC] = LAYOUT_planck_grid(
        KC_TAB,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX, XXXXXXX, KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX, _______,
        _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, KC_NLCK, KC_CLCK, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Media
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |      | Mute | Vol- | Vol+ |      |      |      |      |      |      | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl |      | Prev | Play | Next |      |      |      |      |      |      |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Shift|      |      |      |      |      |      |      |      |      |      |Shift |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Hyper| Meh  | Alt  | GUI  | Num  |    Space    | Sym  | Brac | Fn   |Media | Adj  |
    * `-----------------------------------------------------------------------------------'
    */
    [_MED] = LAYOUT_planck_grid(
        KC_TAB,  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Adjust
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      | Reset|      |      |EEPRes|      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |Aud on|Audoff|Audtog|      |      | RGB  |Brght+|Brght-|      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |Mus on|Musoff|Mustog|      |      |RGBMod| Hue+ | Hue- |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJ] = LAYOUT_planck_grid(
        KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
        _______, XXXXXXX, AU_ON,   AU_OFF,  AU_TOG,  XXXXXXX, XXXXXXX, RGB_TOG, RGB_VAI, RGB_VAD, XXXXXXX, _______,
        _______, XXXXXXX, MU_ON,   MU_OFF,  MU_TOG,  XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUI, RGB_HUD, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

layer_state_t layer_state_set_user(layer_state_t state)
{
  return update_tri_layer_state(state, _NUM, _SYM, _ADJ);
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch(keycode) {
    case NBOL:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)));
        }
        break;
    case NEOL:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_TAP(X_RGHT)));
        }
        break;
    case NBWRD:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
        }
        break;
    case NFWRD:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_RGHT)));
        }
        break;
    case NBDWRD:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_BSPC)));
        }
        break;
    case NDWRD:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LALT(SS_TAP(X_RGHT))) SS_TAP(X_DEL));
        }
        break;
    case NUNDO:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("z"));
        }
        break;
    case NCUT:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("x"));
        }
        break;
    case NCOPY:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("c"));
        }
        break;
    case NPASTE:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("z"));
        }
        break;
    }
    return true;
}
