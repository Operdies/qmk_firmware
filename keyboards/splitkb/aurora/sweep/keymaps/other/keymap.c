#include QMK_KEYBOARD_H

#define LENGTH(X) (sizeof(X) / sizeof(X[0]))
typedef bool (intercept_fn)(uint16_t, keyrecord_t*);

enum layer_names {
    _HOMEROW,
    _S1,
    _MOUSE,
    _FUNCTION,
    _S2,
};

enum {
    JK_ESC,
    FJ_CAPS,
};

enum {
    TD_ESC_CAPS,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
};

const uint16_t PROGMEM jk_combo[]       = {RSFT_T(KC_J), RCTL_T(KC_K), COMBO_END};
const uint16_t PROGMEM fj_combo[]       = {LSFT_T(KC_F), RSFT_T(KC_J), COMBO_END};

combo_t key_combos[] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
    [FJ_CAPS] = COMBO(fj_combo, QK_CAPS_WORD_TOGGLE),
};

// For some reason, tap/hold doesn't work for regular keys. Likely because holds aren't implemented for non-tap keys
// Start at LT(0, KC_A) because layer 0 is always active, and A is an early keycode which ensures plenty of keys to map
enum custom_keycodes {
    CK_E = LT(0, KC_A), CK_I,
    CK_W, CK_O,
    CK_R, CK_U,
    CK_T, CK_Y,
    CK_Q, CK_P,
    CK_N, CK_M,
    CK_SCLN,
};

typedef struct {
    uint16_t tapped;
    uint16_t held;
} hold_key_t;

#define CK(tap, hold) { tap, hold }
static hold_key_t hold_keys[] = {
    [CK_Q]    = CK(KC_Q, KC_ASTR),
    [CK_W]    = CK(KC_W, KC_AMPR),
    [CK_E]    = CK(KC_E, KC_LPRN),
    [CK_R]    = CK(KC_R, KC_RPRN),
    [CK_T]    = CK(KC_T, KC_MINS),
    [CK_Y]    = CK(KC_Y, KC_PLUS),
    [CK_U]    = CK(KC_U, KC_LBRC),
    [CK_I]    = CK(KC_I, KC_RBRC),
    [CK_O]    = CK(KC_O, KC_PIPE),
    [CK_P]    = CK(KC_P, KC_EQL),

    [CK_N]    = CK(KC_N, KC_0),
    [CK_M]    = CK(KC_M, KC_1),

    [CK_SCLN] = CK(KC_SCLN, KC_QUOT),
};

// NOTE: LALT_T is used on the right side because RALT_T is not registered in tmux
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_HOMEROW] = LAYOUT_split_3x5_2(
  CK_Q       , CK_W              , CK_E                , CK_R                   , CK_T                     ,     CK_Y                   , CK_U             , CK_I          , CK_O          , CK_P      ,
  KC_A       , LALT_T(KC_S)      , LCTL_T(KC_D)        , LSFT_T(KC_F)           , LGUI_T(KC_G)             ,     RGUI_T(KC_H)           , RSFT_T(KC_J)     , RCTL_T(KC_K)  , LALT_T(KC_L)  , CK_SCLN  ,
  KC_Z       , KC_X              , KC_C                , KC_V                   , KC_B                     ,     CK_N                   , CK_M             , KC_COMM       , KC_DOT        , KC_SLSH    ,
                                                         KC_BSPC                , LT(MO(_S1), KC_TAB)      ,     LT(MO(_MOUSE), KC_ENT) , LT(MO(_FUNCTION) , KC_SPC)
),
[_S1] = LAYOUT_split_3x5_2( // TODO: The lhs of this layer is kinda wacky. Never use arrow keys or hash, trying to move away from the braces
  KC_GRAVE   , KC_TILD           , KC_MINS             , KC_UNDS                , KC_TRNS                  ,     KC_TRNS                , KC_7             , KC_8          , KC_9          , KC_EQL     ,
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_LSFT                , KC_TRNS                  ,     KC_LGUI                , RSFT_T(KC_4)     , RCTL_T(KC_5)  , LALT_T(KC_6)  , KC_BSLS    ,
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_0                   , KC_1             , KC_2          , KC_3          , KC_PIPE    ,
                                                         KC_DEL                 , KC_TRNS                  ,     KC_TRNS                , KC_TRNS
),
[_S2] = LAYOUT_split_3x5_2( // TODO: Unused layer. Find a use and put on bspc
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS          , KC_TRNS       , KC_TRNS       , KC_TRNS    ,
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS          , KC_TRNS       , KC_TRNS       , KC_TRNS    ,
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS          , KC_TRNS       , KC_TRNS       , KC_TRNS    ,
                                                         KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS
),
[_MOUSE] = LAYOUT_split_3x5_2( // TODO: lhs not used
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_BTN4                , KC_BTN1          , KC_WH_U       , KC_BTN2       , KC_BTN5    ,
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_MS_L                , KC_MS_D          , KC_MS_U       , KC_MS_R       , KC_BTN3    ,
  KC_TRNS    , KC_TRNS           , KC_TRNS             , KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_WH_L          , KC_WH_D       , KC_WH_R       , KC_TRNS    ,
                                                         KC_TRNS                , KC_TRNS                  ,     KC_TRNS                , KC_TRNS
),
[_FUNCTION] = LAYOUT_split_3x5_2(
  ALGR(KC_W) , RGB_TOG           , KC_UP               , RGB_MOD                , RGB_HUI                  ,     KC_DEL                 , KC_F7            , KC_F8         , KC_F9         , KC_F10     ,
  ALGR(KC_L) , LALT_T(KC_LEFT)   , LCTL_T(KC_DOWN)     , LSFT_T(KC_RIGHT)       , KC_LGUI                  ,     KC_LGUI                , RSFT_T(KC_F4)    , RCTL_T(KC_F5) , LALT_T(KC_F6) , KC_F11     ,
  ALGR(KC_Z) , KC_TRNS           , KC_TRNS             , KC_TRNS                , RGB_SAI                  ,     KC_TRNS                , KC_F1            , KC_F2         , KC_F3         , KC_F12     ,
                                                         KC_TRNS                , RGB_VAI                  ,     KC_TRNS                , KC_TRNS
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

bool custom_hold_keys(uint16_t keycode, keyrecord_t *record) {
    if (keycode < LENGTH(hold_keys) && hold_keys[keycode].held) {
        hold_key_t *hk = &hold_keys[keycode];
        if (record->tap.count) {
            uint16_t key = capsword_shift(hk->tapped);
            if (record->event.pressed){
                register_code16(key);
            } else {
                unregister_code16(key);
            }
        } else if (record->event.pressed) {
            uint16_t key = capsword_shift(hk->held);
            tap_code16(key);
        }
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    intercept_fn *lst[] = {
        custom_hold_keys,
    };

    for (int i = 0; i < LENGTH(lst); i++)
        if (lst[i](keycode, record) == false)
            return false;
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
