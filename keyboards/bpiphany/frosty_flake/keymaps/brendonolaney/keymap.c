#include QMK_KEYBOARD_H

enum frosty_flake_layers {
    _BASE,
    _NAV,
    _FNC,
};

#define NAV MO(_NAV)
#define FNC MO(_FNC)

enum nav_keycodes {
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
  [_BASE] = LAYOUT_tkl(\
    KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,     KC_PSCR, KC_SLCK, KC_PAUS, \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,    KC_INS,  KC_HOME, KC_PGUP, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,    KC_DEL,  KC_END,  KC_PGDN, \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,                                \
    KC_LSFT, XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,             KC_UP,            \
    KC_MEH,  KC_LALT, KC_LGUI,                            KC_SPC,                             NAV,     KC_RALT, FNC,     KC_RCTL,    KC_LEFT, KC_DOWN, KC_RGHT  \
  ),
  [_NAV] = LAYOUT_tkl(\
    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, NBDWRD,  XXXXXXX, NDWRD,   XXXXXXX, NBOL,    NBWRD,   KC_UP,   NFWRD,   NEOL,    XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, KC_BSPC, XXXXXXX, KC_DEL,  XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  XXXXXXX,          _______,                               \
    _______, XXXXXXX, NUNDO,   NCUT,    NCOPY,   NPASTE,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,             XXXXXXX,          \
    _______, _______, _______,                            _______,                            _______, _______, _______, _______,    XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
  [_FNC] = LAYOUT_tkl(\
    XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU,    XXXXXXX, EEP_RST, RESET,   \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   XXXXXXX, XXXXXXX, XXXXXXX, _______,    XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   XXXXXXX, XXXXXXX,          _______,                               \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          _______,             XXXXXXX,          \
    _______, _______, _______,                            _______,                            _______, _______, _______, _______,    XXXXXXX, XXXXXXX, XXXXXXX  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
