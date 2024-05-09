// Copyright (C) 2019, 2020  Keyboard.io, Inc
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include <stdint.h>
#include QMK_KEYBOARD_H
#define LENGTH(X) (sizeof(X) / sizeof(X[0]))

enum layer_names {
    _HOMEROW,
    _S1,
    _MOUSE,
    _FUN,
    _S2,
    LAYER_LAST,
};

enum {
    ER_COMBO,
    UI_COMBO,
    DF_COMBO,
    WR_COMBO,
    JK_ESC,
    FJ_CAPS,
};

const uint16_t PROGMEM er_combo[]       = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM ui_combo[]       = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM df_combo[]       = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM jk_combo[]       = {LSFT_T(KC_J), LCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM fj_combo[]       = {LSFT_T(KC_F), LSFT_T(KC_J), COMBO_END};

combo_t key_combos[] = {
    [ER_COMBO] = COMBO(er_combo, KC_BSPC),
    [UI_COMBO] = COMBO(ui_combo, KC_DEL),
    [DF_COMBO] = COMBO(df_combo, KC_TAB),
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [FJ_CAPS] = COMBO(fj_combo, QK_CAPS_WORD_TOGGLE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_HOMEROW] = LAYOUT_first(
  KC_Q       , KC_W            , KC_E            , KC_R             , KC_T                        , KC_Y               , KC_U             , KC_I          , KC_O          , KC_P       ,
  KC_A       , LALT_T(KC_S)    , LCTL_T(KC_D)    , LSFT_T(KC_F)     , LGUI_T(KC_G)                , LGUI_T(KC_H)       , LSFT_T(KC_J)     , LCTL_T(KC_K)  , LALT_T(KC_L)  , KC_SCLN    ,
  KC_Z       , KC_X            , KC_C            , KC_V             , KC_B         , KC_NO, KC_NO , KC_N               , KC_M             , KC_COMM       , KC_DOT        , KC_SLSH    ,
  KC_NO      , KC_NO           , KC_NO           , KC_BSPC          , MO(_S1)      , KC_NO, KC_NO , LT(_MOUSE, KC_ENT) , LT(_FUN , KC_SPC), KC_NO         , KC_NO         , KC_NO
),
[_S1] = LAYOUT_first(
  KC_LBRC    , KC_QUOT         , KC_MINS         , KC_RABK          , KC_RBRC                     , KC_GRAVE           , KC_7             , KC_8          , KC_9          , KC_EQL     ,
  KC_LPRN    , KC_GRAVE        , KC_NO           , KC_LSFT          , KC_RPRN                     , KC_LGUI            , LSFT_T(KC_4)     , LCTL_T(KC_5)  , LALT_T(KC_6)  , KC_BSLS    ,
  KC_LBRC    , KC_RBRC         , KC_NO           , KC_LCBR          , KC_RCBR      , KC_NO, KC_NO , KC_0               , KC_1             , KC_2          , KC_3          , KC_PIPE    ,
  KC_NO      , KC_NO           , KC_NO           , KC_DEL           , KC_NO        , KC_NO, KC_NO , KC_NO              , KC_NO            , KC_NO         , KC_NO         , KC_NO
),
[_S2] = LAYOUT_first(
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , KC_NO                       , KC_NO              , KC_NO            , KC_NO         , KC_NO         , KC_NO      ,
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , KC_NO                       , KC_NO              , KC_NO            , KC_NO         , KC_NO         , KC_NO      ,
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , KC_NO        , KC_NO, KC_NO , KC_NO              , KC_NO            , KC_NO         , KC_NO         , KC_NO      ,
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , KC_NO        , KC_NO, KC_NO , KC_NO              , KC_NO            , KC_NO         , KC_NO         , KC_NO
),
[_MOUSE] = LAYOUT_first(
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , KC_NO                       , KC_BTN4            , KC_BTN1          , KC_WH_U       , KC_BTN2       , KC_BTN5    ,
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , KC_NO                       , KC_MS_L            , KC_MS_D          , KC_MS_U       , KC_MS_R       , KC_BTN3    ,
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , KC_NO        , KC_NO, KC_NO , KC_NO              , KC_WH_L          , KC_WH_D       , KC_WH_R       , KC_NO      ,
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , KC_NO        , KC_NO, KC_NO , KC_NO              , KC_NO            , KC_NO         , KC_NO         , KC_NO
),
[_FUN] = LAYOUT_first(
  ALGR(KC_W) , RGB_TOG         , KC_UP           , RGB_MOD          , RGB_HUI                     , KC_DEL             , KC_F7            , KC_F8         , KC_F9         , KC_F10     ,
  ALGR(KC_L) , LALT_T(KC_LEFT) , LCTL_T(KC_DOWN) , LSFT_T(KC_RIGHT) , KC_LGUI                     , KC_LGUI            , LSFT_T(KC_F4)    , LCTL_T(KC_F5) , LALT_T(KC_F6) , KC_F11     ,
  ALGR(KC_Z) , KC_NO           , KC_NO           , KC_NO            , RGB_SAI      , KC_NO, KC_NO , KC_NO              , KC_F1            , KC_F2         , KC_F3         , KC_F12     ,
  KC_NO      , KC_NO           , KC_NO           , KC_NO            , RGB_VAI      , KC_NO, KC_NO , KC_NO              , KC_NO            , KC_NO         , KC_NO         , KC_NO
),
};

uint16_t capsword_shift(uint16_t key) {
    if (is_caps_word_on()) {
        switch (key) {
            case KC_A ... KC_Z:
            case KC_MINS:
                return LSFT(key);
                break;
            default:
                return key;
                break;
        }
    }
    return key;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // Combos on different hands are easy to fumble
    if (index == FJ_CAPS)
        return 50;
    return COMBO_TERM;
}

