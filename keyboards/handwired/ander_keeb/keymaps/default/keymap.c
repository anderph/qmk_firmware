#include "ander_keeb.h"




enum custom_keycodes {
    ALT_TABBER1 = SAFE_RANGE, //just the top one needs safe range, this assigns this top one a high value that is unique and the ones below will be this value plus one at each step
    ALT_TABBER2,
    ALT_RELEASE,
    ENC_BUT1,
    ENC_BUT2,
    MY_OTHER_MACRO,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ALT_TABBER1:
        if (record->event.pressed) {
            // when keycode ALT_TABBER1 is pressed
            register_code(KC_LALT);
            register_code(KC_TAB);
        } else {
            // when keycode ALT_TABBER1 is released
            unregister_code(KC_TAB);
        }
        break;

    case ALT_TABBER2:
        if (record->event.pressed) {
            // when keycode ALT_TABBER2 is pressed
            register_code(KC_LALT);
            register_code(KC_LEFT_SHIFT);
            register_code(KC_TAB);
        } else {
            // when keycode ALT_TABBER2 is released
            unregister_code(KC_TAB);
            unregister_code(KC_LEFT_SHIFT);
        }
        break;

    case ALT_RELEASE:
        if (record->event.pressed) {
           unregister_code(KC_LALT);
        }
        break;

    case ENC_BUT1:
        if (record->event.pressed) {
        //    if((get_mods() & MOD_BIT(KC_LEFT_CTRL)) == MOD_BIT(KC_LEFT_CTRL)) {
        }else {
            // when keycode ENC_BUT1 is released
        }
        break;

    case ENC_BUT2:
        if (record->event.pressed) {
        }else {
            // when keycode ENC_BUT2 is released
        }
        break;

        case MY_OTHER_MACRO:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("ac")); // selects all and copies
        }
        break;

    }
    return true;
};










const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer for windows (french accents too)
//layer for mac
//layer for



	[0] KEYMAP(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MEDIA_PLAY_PAUSE,

		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, DM_PLY1, ALT_RELEASE, DM_PLY2,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_Q, KC_W, KC_E, KC_UP,
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_A, KC_S, KC_D, KC_RGHT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_Z, KC_X, KC_C, KC_DOWN,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_LALT, KC_LGUI, MO(2), KC_LCTL, KC_T, KC_Y, KC_U, KC_LEFT),

	[1] KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    	[2] KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_RSTP, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};


	// [1] KEYMAP(
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	// 	KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),




#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(C(KC_TAB), C(S(KC_TAB))), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) , ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)  , ENCODER_CCW_CW(ALT_TABBER2, ALT_TABBER1)   },
    [1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  ,           ENCODER_CCW_CW(KC_VOLD, KC_VOLU) , ENCODER_CCW_CW(KC_VOLD, KC_VOLU) , ENCODER_CCW_CW(KC_VOLD, KC_VOLU)    },
    [2] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  ,           ENCODER_CCW_CW(KC_VOLD, KC_VOLU) , ENCODER_CCW_CW(KC_VOLD, KC_VOLU) , ENCODER_CCW_CW(KC_VOLD, KC_VOLU)    },
};
#endif













void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}
