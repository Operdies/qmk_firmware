#include QMK_KEYBOARD_H

enum layer_names {
    _HOMEROW,
    _SYMBOLS,
    _MOUSE,
    _ESCAPE_HATCH,
};

enum combos {
    JK_ESC,
    FJ_CAPS,
};

enum {
    TD_ESC_CAPS,
    TD_CAPS_WORD,
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

const uint16_t PROGMEM jk_combo[]       = {RSFT_T(KC_J), LCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM fj_combo[]       = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};

combo_t key_combos[] = {
    // [JK_ESC] = COMBO(jk_combo, TD(TD_ESC_CAPS)),
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [FJ_CAPS] = COMBO(fj_combo, QK_CAPS_WORD_TOGGLE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_HOMEROW] = LAYOUT_split_3x5_2(
  KC_Q     , KC_W         , KC_E         , KC_R         , KC_T         ,                 KC_Y                   , KC_U         , KC_I         , KC_O         , KC_P    ,
  KC_A     , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , LGUI_T(KC_G) ,                 LGUI_T(KC_H)           , RSFT_T(KC_J) , LCTL_T(KC_K) , LALT_T(KC_L) , KC_SCLN ,
  KC_Z     , KC_X         , KC_C         , KC_V         , KC_B         ,                 KC_N                   , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH ,
                                           KC_BSPC      , LT(MO(_SYMBOLS), KC_TAB) ,     LT(MO(_MOUSE), KC_ENT) , KC_SPC
),
[_SYMBOLS] = LAYOUT_split_3x5_2(
  KC_GRAVE , KC_TILD         , KC_MINS         , KC_UNDS         , KC_ASTR         ,     KC_QUOT           , KC_7         , KC_8         , KC_9         , KC_EQL ,
  KC_LPRN  , LALT_T(KC_LEFT) , LCTL_T(KC_DOWN) , LSFT_T(KC_RGHT) , KC_RPRN         ,     KC_LGUI           , RSFT_T(KC_4) , LCTL_T(KC_5) , LALT_T(KC_6) , KC_BSLS,
  KC_LBRC  , KC_RBRC         , KC_HASH         , KC_LCBR         , KC_RCBR         ,     KC_0              , KC_1         , KC_2         , KC_3         , KC_EQL ,
                                                 KC_DEL          , KC_TRNS         ,     MO(_ESCAPE_HATCH) , KC_TRNS
),
[_MOUSE] = LAYOUT_split_3x5_2(
  KC_GRAVE , KC_EQL  , KC_UP   , KC_QUOT  , KC_TAB  ,    KC_TRNS , KC_BTN1 , KC_WH_U , KC_BTN2 , KC_TRNS,
  KC_LPRN  , KC_LEFT , KC_DOWN , KC_RIGHT , KC_RPRN ,    KC_MS_L , KC_MS_D , KC_MS_U , KC_MS_R , KC_TRNS,
  KC_LBRC  , KC_RBRC , KC_HASH , KC_LCBR  , KC_RCBR ,    KC_TRNS , KC_WH_L , KC_WH_D , KC_WH_R , KC_TRNS,
                                 KC_TRNS  , KC_TRNS ,    KC_TRNS , KC_TRNS
),
[_ESCAPE_HATCH] = LAYOUT_split_3x5_2(
  KC_TRNS , KC_TRNS , KC_UP   , KC_TRNS  , KC_TRNS ,     KC_DEL  , KC_F7 , KC_F8 , KC_F9 , KC_F10,
  KC_TRNS , KC_LEFT , KC_DOWN , KC_RIGHT , KC_TRNS ,     KC_TRNS , KC_F4 , KC_F5 , KC_F6 , KC_F11,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS ,     KC_TRNS , KC_F1 , KC_F2 , KC_F3 , KC_F12,
                                KC_TRNS  , KC_TRNS ,     KC_TRNS , KC_TRNS
)};


void keyboard_pre_init_user(void) {
    // Set our LED pin as output
    setPinOutput(24);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    writePinHigh(24);
}

void keyboard_post_init_user(void) {
    rgblight_sethsv(190, 22, 73);
}

