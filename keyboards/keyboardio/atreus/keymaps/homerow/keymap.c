// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include <stdint.h>
#include QMK_KEYBOARD_H

enum layer_names {
    HOMEROW,
    SYMBOLS,
    _LW,
};

enum custom_keycodes {
    _ASSIGN = SAFE_RANGE,
    _COMPARE,
    _LEQ,
    _GEQ,
    _LE,
    _GE,
    _SUB,
    _ADD,
};

enum combos {
  YU_BRC,
  JK_ESC,
  OP_BRC,
  QW_QUOT,
  DA_DASH,
  AS_APO,
  QWE_ASSIGN,
  EQ_EQ,
  LT_LT,
  GT_GT,
};

const uint16_t PROGMEM yu_combo[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {LSFT_T(KC_J) , LCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM op_combo[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM as_combo[] = {KC_A, LALT_T(KC_S), COMBO_END};
const uint16_t PROGMEM da_combo[] = {LCTL_T(KC_D), KC_A, COMBO_END};
const uint16_t PROGMEM eqassign_combo[] = {KC_Q, KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM eq_combo[] = {KC_Q, KC_E, COMBO_END};
const uint16_t PROGMEM lt_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM gt_combo[] = {KC_W, KC_E, COMBO_END};

combo_t key_combos[] = {
  [YU_BRC] = COMBO(yu_combo, KC_LBRC),
  [JK_ESC] = COMBO(jk_combo, KC_ESC),
  [OP_BRC] = COMBO(op_combo, KC_RBRC),
  [QW_QUOT] = COMBO(qw_combo, KC_DQUO),
  [AS_APO] = COMBO(as_combo, KC_QUOT),
  [DA_DASH] = COMBO(da_combo, KC_MINS),
  [QWE_ASSIGN] = COMBO(eqassign_combo, _ASSIGN),
  [EQ_EQ] = COMBO(eq_combo, KC_EQL),
  [LT_LT] = COMBO(lt_combo, KC_LT),
  [GT_GT] = COMBO(gt_combo, KC_GT),
  [QWE_ASSIGN] = COMBO(eqassign_combo, _ASSIGN),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────┬───────────┬─────────────┬───────────┬───────────┐                ┌───────────┬─────────────┬───────────┬───────────┬─────┐
//    │  q  │     w     │      e      │     r     │     t     │                │     y     │      u      │     i     │     o     │  p  │
//    ├─────┼───────────┼─────────────┼───────────┼───────────┤                ├───────────┼─────────────┼───────────┼───────────┼─────┤
//    │  a  │ LALT_T(s) │  LCTL_T(d)  │ LSFT_T(f) │ LGUI_T(g) │                │ LGUI_T(h) │  LSFT_T(j)  │ LCTL_T(k) │ LALT_T(l) │  ;  │
//    ├─────┼───────────┼─────────────┼───────────┼───────────┼──────┐   ┌─────┼───────────┼─────────────┼───────────┼───────────┼─────┤
//    │  z  │     x     │      c      │     v     │     b     │  `   │   │  \  │     n     │      m      │     ,     │     .     │  /  │
//    ├─────┼───────────┼─────────────┼───────────┼───────────┼──────┤   ├─────┼───────────┼─────────────┼───────────┼───────────┼─────┤
//    │ esc │    tab    │ MO(SYMBOLS) │    no     │   bspc    │ lgui │   │ ent │    spc    │ MO(SYMBOLS) │     -     │     '     │ ent │
//    └─────┴───────────┴─────────────┴───────────┴───────────┴──────┘   └─────┴───────────┴─────────────┴───────────┴───────────┴─────┘
[HOMEROW] = LAYOUT_first(
  KC_Q   , KC_W         , KC_E         , KC_R         , KC_T         ,                         KC_Y         , KC_U         , KC_I         , KC_O         , KC_P   ,
  KC_A   , LALT_T(KC_S) , LCTL_T(KC_D) , LSFT_T(KC_F) , LGUI_T(KC_G) ,                         LGUI_T(KC_H) , LSFT_T(KC_J) , LCTL_T(KC_K) , LALT_T(KC_L) , KC_SCLN,
  KC_Z   , KC_X         , KC_C         , KC_V         , KC_B         , KC_GRV  ,     KC_BSLS , KC_N         , KC_M         , KC_COMM      , KC_DOT       , KC_SLSH,
  KC_ESC , KC_TAB       , MO(SYMBOLS)  , KC_NO        , KC_BSPC      , KC_LGUI ,     KC_ENT  , KC_SPC       , MO(SYMBOLS)  , KC_MINS      , KC_QUOT      , KC_ENT
),

//    ┌─────┬──────────────┬──────────────┬──────────────┬──────┐                 ┌─────────────┬───────────┬───────────┬───┬───┐
//    │  !  │      @       │      up      │      $       │  %   │                 │    home     │     7     │     8     │ 9 │ | │
//    ├─────┼──────────────┼──────────────┼──────────────┼──────┤                 ├─────────────┼───────────┼───────────┼───┼───┤
//    │  (  │ LALT_T(left) │ LCTL_T(down) │ LSFT_T(rght) │  )   │                 │ LGUI_T(end) │ LSFT_T(4) │ LCTL_T(5) │ 6 │ \ │
//    ├─────┼──────────────┼──────────────┼──────────────┼──────┼──────┐   ┌──────┼─────────────┼───────────┼───────────┼───┼───┤
//    │  [  │      ]       │      #       │      {       │  }   │  ^   │   │  &   │      *      │     1     │     2     │ 3 │ + │
//    ├─────┼──────────────┼──────────────┼──────────────┼──────┼──────┤   ├──────┼─────────────┼───────────┼───────────┼───┼───┤
//    │ esc │     ins      │     lgui     │     lsft     │ bspc │ lctl │   │ lalt │     spc     │           │     .     │ 0 │ = │
//    └─────┴──────────────┴──────────────┴──────────────┴──────┴──────┘   └──────┴─────────────┴───────────┴───────────┴───┴───┘
[SYMBOLS] = LAYOUT_first(
  KC_EXLM , KC_AT           , KC_UP           , KC_DLR          , KC_PERC ,                         KC_HOME        , KC_7         , KC_8         , KC_9 , KC_PIPE,
  KC_LPRN , LALT_T(KC_LEFT) , LCTL_T(KC_DOWN) , LSFT_T(KC_RGHT) , KC_RPRN ,                         LGUI_T(KC_END) , LSFT_T(KC_4) , LCTL_T(KC_5) , KC_6 , KC_BSLS,
  KC_LBRC , KC_RBRC         , KC_HASH         , KC_LCBR         , KC_RCBR , KC_CIRC ,     KC_AMPR , KC_ASTR        , KC_1         , KC_2         , KC_3 , KC_PLUS,
  KC_ESC  , KC_INS          , KC_LGUI         , KC_LSFT         , KC_BSPC , KC_LCTL ,     KC_LALT , KC_SPC         , KC_TRNS      , KC_DOT       , KC_0 , KC_EQL
),

//    ┌─────┬─────┬─────┬─────┬─────┐               ┌──────┬──────┬─────┬──────┬─────┐
//    │     │     │     │     │     │               │      │      │     │      │     │
//    ├─────┼─────┼─────┼─────┼─────┤               ├──────┼──────┼─────┼──────┼─────┤
//    │     │     │     │     │     │               │ left │ down │ up  │ rght │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┐   ┌─────┼──────┼──────┼─────┼──────┼─────┤
//    │     │     │     │     │     │     │   │     │      │      │     │      │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼──────┼──────┼─────┼──────┼─────┤
//    │     │     │     │     │     │     │   │     │      │      │     │      │     │
//    └─────┴─────┴─────┴─────┴─────┴─────┘   └─────┴──────┴──────┴─────┴──────┴─────┘
[_LW] = LAYOUT_first(
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,                         KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS,
  KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ,     KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS  , KC_TRNS
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _ASSIGN:
            if (record->event.pressed) {
                SEND_STRING(" = ");
            }
            break;
    }
    return true;
}
