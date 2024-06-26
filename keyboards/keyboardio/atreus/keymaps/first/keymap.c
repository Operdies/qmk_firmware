// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _RS,
    _LW,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌─────────────┬─────┬──────┬──────┬──────┐                           ┌─────┬─────────┬───┬───┬─────┐
//    │      q      │  w  │  e   │  r   │  t   │                           │  y  │    u    │ i │ o │  p  │
//    ├─────────────┼─────┼──────┼──────┼──────┤                           ├─────┼─────────┼───┼───┼─────┤
//    │      a      │  s  │  d   │  f   │  g   │                           │  h  │    j    │ k │ l │  ;  │
//    ├─────────────┼─────┼──────┼──────┼──────┼─────────┐   ┌─────────────┼─────┼─────────┼───┼───┼─────┤
//    │      z      │  x  │  c   │  v   │  b   │    `    │   │      \      │  n  │    m    │ , │ . │  /  │
//    ├─────────────┼─────┼──────┼──────┼──────┼─────────┤   ├─────────────┼─────┼─────────┼───┼───┼─────┤
//    │ LCTL_T(esc) │ tab │ lgui │ lsft │ bspc │ MO(_LW) │   │ LALT_T(del) │ spc │ MO(_RS) │ - │ ' │ ent │
//    └─────────────┴─────┴──────┴──────┴──────┴─────────┘   └─────────────┴─────┴─────────┴───┴───┴─────┘
[_QW] = LAYOUT_first(
  KC_Q           , KC_W   , KC_E    , KC_R    , KC_T    ,                                KC_Y   , KC_U    , KC_I    , KC_O    , KC_P   ,
  KC_A           , KC_S   , KC_D    , KC_F    , KC_G    ,                                KC_H   , KC_J    , KC_K    , KC_L    , KC_SCLN,
  KC_Z           , KC_X   , KC_C    , KC_V    , KC_B    , KC_GRV  ,     KC_BSLS        , KC_N   , KC_M    , KC_COMM , KC_DOT  , KC_SLSH,
  LCTL_T(KC_ESC) , KC_TAB , KC_LGUI , KC_LSFT , KC_BSPC , MO(_LW) ,     LALT_T(KC_DEL) , KC_SPC , MO(_RS) , KC_MINS , KC_QUOT , KC_ENT
),

//    ┌─────┬──────┬──────┬──────┬──────┐                 ┌──────┬─────┬───┬───┬───┐
//    │  !  │  @   │  up  │  $   │  %   │                 │ home │  7  │ 8 │ 9 │ | │
//    ├─────┼──────┼──────┼──────┼──────┤                 ├──────┼─────┼───┼───┼───┤
//    │  (  │ left │ down │ rght │  )   │                 │ end  │  4  │ 5 │ 6 │ \ │
//    ├─────┼──────┼──────┼──────┼──────┼──────┐   ┌──────┼──────┼─────┼───┼───┼───┤
//    │  [  │  ]   │  #   │  {   │  }   │  ^   │   │  &   │  *   │  1  │ 2 │ 3 │ + │
//    ├─────┼──────┼──────┼──────┼──────┼──────┤   ├──────┼──────┼─────┼───┼───┼───┤
//    │ esc │ ins  │ lgui │ lsft │ bspc │ lctl │   │ lalt │ spc  │     │ . │ 0 │ = │
//    └─────┴──────┴──────┴──────┴──────┴──────┘   └──────┴──────┴─────┴───┴───┴───┘
[_RS] = LAYOUT_first(
  KC_EXLM , KC_AT   , KC_UP   , KC_DLR  , KC_PERC ,                         KC_HOME , KC_7    , KC_8   , KC_9 , KC_PIPE,
  KC_LPRN , KC_LEFT , KC_DOWN , KC_RGHT , KC_RPRN ,                         KC_END  , KC_4    , KC_5   , KC_6 , KC_BSLS,
  KC_LBRC , KC_RBRC , KC_HASH , KC_LCBR , KC_RCBR , KC_CIRC ,     KC_AMPR , KC_ASTR , KC_1    , KC_2   , KC_3 , KC_PLUS,
  KC_ESC  , KC_INS  , KC_LGUI , KC_LSFT , KC_BSPC , KC_LCTL ,     KC_LALT , KC_SPC  , KC_TRNS , KC_DOT , KC_0 , KC_EQL
),

//    ┌───────────────┬───────────────┬───────────────┬─────────┬─────────┐                 ┌──────┬─────────┬──────┬──────┬──────┐
//    │    LGUI(1)    │    LGUI(2)    │    LGUI(3)    │ LGUI(4) │ LGUI(5) │                 │  up  │   f7    │  f8  │  f9  │ f10  │
//    ├───────────────┼───────────────┼───────────────┼─────────┼─────────┤                 ├──────┼─────────┼──────┼──────┼──────┤
//    │ LSFT(ALGR(z)) │ LSFT(ALGR(l)) │ LSFT(ALGR(w)) │  rght   │  pgdn   │                 │ down │   f4    │  f5  │  f6  │ f11  │
//    ├───────────────┼───────────────┼───────────────┼─────────┼─────────┼──────┐   ┌──────┼──────┼─────────┼──────┼──────┼──────┤
//    │    ALGR(z)    │    ALGR(l)    │    ALGR(w)    │   no    │ QK_BOOT │      │   │      │  no  │   f1    │  f2  │  f3  │ f12  │
//    ├───────────────┼───────────────┼───────────────┼─────────┼─────────┼──────┤   ├──────┼──────┼─────────┼──────┼──────┼──────┤
//    │      no       │     vold      │     lgui      │  lsft   │  bspc   │ lctl │   │ lalt │ spc  │ TO(_QW) │ pscr │ sCRL │ paus │
//    └───────────────┴───────────────┴───────────────┴─────────┴─────────┴──────┘   └──────┴──────┴─────────┴──────┴──────┴──────┘
[_LW] = LAYOUT_first(
  LGUI(KC_1)       , LGUI(KC_2)       , LGUI(KC_3)       , LGUI(KC_4) , LGUI(KC_5) ,                         KC_UP   , KC_F7   , KC_F8   , KC_F9   , KC_F10 ,
  LSFT(ALGR(KC_Z)) , LSFT(ALGR(KC_L)) , LSFT(ALGR(KC_W)) , KC_RGHT    , KC_PGDN    ,                         KC_DOWN , KC_F4   , KC_F5   , KC_F6   , KC_F11 ,
  ALGR(KC_Z)       , ALGR(KC_L)       , ALGR(KC_W)       , KC_NO      , QK_BOOT    , _______ ,     _______ , KC_NO   , KC_F1   , KC_F2   , KC_F3   , KC_F12 ,
  KC_NO            , KC_VOLD          , KC_LGUI          , KC_LSFT    , KC_BSPC    , KC_LCTL ,     KC_LALT , KC_SPC  , TO(_QW) , KC_PSCR , KC_SCRL , KC_PAUS
)
};

