#include QMK_KEYBOARD_H

enum layer_names {
    _HOMEROW,
    _S1,
    _MOUSE,
    _FUNCTION,
    _S2,
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

const uint16_t PROGMEM jk_combo[]       = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM fj_combo[]       = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};

combo_t key_combos[] = {
    // [JK_ESC] = COMBO(jk_combo, TD(TD_ESC_CAPS)),
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [FJ_CAPS] = COMBO(fj_combo, QK_CAPS_WORD_TOGGLE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_HOMEROW] = LAYOUT_split_3x5_2(
  KC_Q       , KC_W              , KC_E                , KC_R                   , KC_T                     ,     KC_Y                   , KC_U             , KC_I          , KC_O          , KC_P     ,
  KC_A       , LALT_T(KC_S)      , LCTL_T(KC_D)        , LSFT_T(KC_F)           , LGUI_T(KC_G)             ,     RGUI_T(KC_H)           , RSFT_T(KC_J)     , RCTL_T(KC_K)  , RALT_T(KC_L)  , KC_SCLN  ,
  KC_Z       , KC_X              , KC_C                , KC_V                   , KC_B                     ,     KC_N                   , KC_M             , KC_COMM       , KC_DOT        , KC_SLSH  ,
                                                         KC_BSPC                , LT(MO(_S1), KC_TAB)      ,     LT(MO(_MOUSE), KC_ENT) , LT(MO(_FUNCTION) , KC_SPC)
                                                      // LT(MO(_S2), KC_BSPC)
),
[_S1] = LAYOUT_split_3x5_2(
  KC_GRAVE   , KC_TILD           , KC_MINS             , KC_LBRC                , KC_RBRC                  ,     KC_QUOT                , KC_7             , KC_8          , KC_9          , KC_EQL   ,
  KC_LPRN    , LALT_T(KC_LEFT)   , LCTL_T(KC_DOWN)     , LSFT_T(KC_RGHT)        , KC_RPRN                  ,     KC_LGUI                , RSFT_T(KC_4)     , RCTL_T(KC_5)  , RALT_T(KC_6)  , KC_BSLS  ,
  KC_LBRC    , KC_RBRC           , KC_HASH             , KC_LCBR                , KC_RCBR                  ,     KC_0                   , KC_1             , KC_2          , KC_3          , KC_PIPE  ,
                                                         KC_DEL                 , KC_TRNS                  ,     KC_TRNS                , KC_TRNS
),
[_S2] = LAYOUT_split_3x5_2(
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS          , KC_TRNS       , KC_TRNS       , KC_TRNS  ,
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS          , KC_TRNS       , KC_TRNS       , KC_TRNS  ,
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS          , KC_TRNS       , KC_TRNS       , KC_TRNS  ,
                                                         KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS
),
[_MOUSE] = LAYOUT_split_3x5_2(
  KC_LBRC    , KC_TILD           , KC_ASTR             , KC_AMPR                , KC_RBRC                  ,     KC_BTN4                , KC_BTN1          , KC_WH_U       , KC_BTN2       , KC_BTN5  ,
  KC_LPRN    , LALT_T(KC_CIRC)   , LCTL_T(KC_PERC)     , LSFT_T(KC_DLR)         , LGUI_T(KC_RPRN)          ,     KC_MS_L                , KC_MS_D          , KC_MS_U       , KC_MS_R       , KC_BTN3  ,
  KC_LCBR    , KC_HASH           , KC_AT               , KC_EXLM                , KC_RCBR                  ,     KC_TRNS                , KC_WH_L          , KC_WH_D       , KC_WH_R       , KC_TRNS  ,
                                                         KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS
),
[_FUNCTION] = LAYOUT_split_3x5_2(
  ALGR(KC_W) , RGB_TOG           , KC_UP               , RGB_MOD                , RGB_HUI                  ,     KC_DEL                 , KC_F7            , KC_F8         , KC_F9         , KC_F10   ,
  ALGR(KC_L) , LALT_T(KC_LEFT)   , LCTL_T(KC_DOWN)     , LSFT_T(KC_RIGHT)       , KC_LGUI                  ,     KC_LGUI                , RSFT_T(KC_F4)    , RCTL_T(KC_F5) , RALT_T(KC_F6) , KC_F11   ,
  ALGR(KC_Z) , KC_TRNS           , KC_TRNS             , KC_TRNS                , RGB_SAI                  ,     KC_TRNS                , KC_F1            , KC_F2         , KC_F3         , KC_F12   ,
                                                         KC_TRNS                , RGB_VAI                  ,     KC_TRNS                , KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    // mod-tap is limited to basic keycodes
    switch (keycode) {
        case LALT_T(KC_CIRC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_CIRC);
                return false;
            }
            break;
        case LCTL_T(KC_PERC):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_PERC);
                return false;
            }
            break;
        case LSFT_T(KC_DLR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_DLR);
                return false;
            }
            break;
        case LGUI_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
    }
    return true;
}

void caps_word_set_user(bool active) {
    static uint8_t prev = 0;
    uint8_t blue_ish = 100;

    HSV hsv = rgb_matrix_get_hsv();

    if (active) {
        rgb_matrix_sethsv(blue_ish, hsv.s, hsv.v);
        prev = hsv.h;
    } else {
        rgb_matrix_sethsv(prev, hsv.s, hsv.v);
    }
}

void keyboard_pre_init_user(void) {
    // Set our LED pin as output
    setPinOutput(24);
    // Turn the LED off
    // (Due to technical reasons, high is off and low is on)
    writePinHigh(24);
}
