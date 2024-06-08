#include "ander_keeb.h"


enum custom_keycodes {
    ALT_TABBER1 = SAFE_RANGE, //just the top one needs safe range, this assigns this top one a high value that is unique and the ones below will be this value plus one at each step
    ALT_TABBER2,
    ALT_RELEASE,
    MAC_CTRL_RIGHT,
    MAC_CTRL_LEFT,
    SPECIAL_ENC1,
    SPECIAL_ENC2,
    ENC_BUT1,
    ENC_BUT2,
    MY_OTHER_MACRO,
    DIP3_1,
    DIP3_2,
    DIP3_3
};

bool is_ctrl_active = false; // ADD this near the beginning of keymap.c
uint16_t ctrl_timer = 0;     // we will be using them soon.
int special_enc_type =0;






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

    case  MAC_CTRL_RIGHT:
      if (record->event.pressed) {
        if (!is_ctrl_active) {
          is_ctrl_active = true;
          register_code(KC_LEFT_CTRL);
        }
        ctrl_timer = timer_read();
        register_code(KC_RIGHT);
      } else {
        unregister_code(KC_RIGHT);
      }
      break;

    case MAC_CTRL_LEFT:
      if (record->event.pressed) {
        if (!is_ctrl_active) {
          is_ctrl_active = true;
          register_code(KC_LEFT_CTRL);
        }
        ctrl_timer = timer_read();
        register_code(KC_LEFT);
      } else {
        unregister_code(KC_LEFT);
      }
      break;


    case ALT_RELEASE:
        if (record->event.pressed) {
           unregister_code(KC_LALT);
        }
        break;

        case SPECIAL_ENC1:
        if (record->event.pressed) {
           if (special_enc_type == 0) {tap_code(KC_RIGHT);}
           if (special_enc_type == 1) {tap_code(KC_DOWN);}
           if (special_enc_type == 2) {}
        }
        break;

        case SPECIAL_ENC2:
        if (record->event.pressed) {
           if (special_enc_type == 0) {tap_code(KC_LEFT);}
           if (special_enc_type == 1) {tap_code(KC_UP);}
           if (special_enc_type == 2) {}
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

        case DIP3_1:  if (record->event.pressed) {special_enc_type =0;}break;
        case DIP3_2:  if (record->event.pressed) {special_enc_type =1;}break;
        case DIP3_3:  if (record->event.pressed) {special_enc_type =2;}break;


    }
    return true;
};



void matrix_scan_user(void) { // The very important timer.
  if (is_ctrl_active) {
    if (timer_elapsed(ctrl_timer) > 300) {
      unregister_code(KC_LEFT_CTRL);
      is_ctrl_active = false;
    }
  }
}





















const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer for windows (french accents too)
//layer for mac
//layer for



	[0] KEYMAP(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_MEDIA_PLAY_PAUSE,

		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, DM_PLY1, ALT_RELEASE, DM_PLY2,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_NO, KC_NO, KC_NO, KC_UP,
		KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_NO, KC_NO, KC_NO, KC_RGHT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_LSFT, KC_NO, KC_NO, KC_NO, KC_DOWN,
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_LALT, KC_LGUI, MO(2), KC_LCTL, KC_NO, KC_NO, KC_NO, KC_LEFT),

	[1] KEYMAP(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,

		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, C(KC_DOWN),
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_INS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    	[2] KEYMAP(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DM_RSTP, DM_REC1, DM_REC2, DM_PLY1, DM_PLY2, KC_TRNS,

		QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};


const key_override_t next_track_override =
	ko_make_with_layers_negmods_and_options(
   		MOD_MASK_CTRL,       // Trigger modifiers: ctrl
    	KC_VOLU,             // Trigger key: play/pause
    	KC_MNXT,             // Replacement key
    	~0,                  // Activate on all layers
    	MOD_MASK_SA,         // Do not activate when shift or alt are pressed
    	ko_option_no_reregister_trigger);

const key_override_t prev_track_override = ko_make_with_layers_negmods_and_options(MOD_MASK_CTRL, KC_VOLD,
											KC_MPRV, ~0, MOD_MASK_SA, ko_option_no_reregister_trigger);

const key_override_t brightness_up_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_VOLU,
											KC_F15 , ~0, MOD_MASK_CA, ko_option_no_reregister_trigger);

const key_override_t brightness_down_override = ko_make_with_layers_negmods_and_options(MOD_MASK_SHIFT, KC_VOLD,
											KC_F14 , ~0, MOD_MASK_CA, ko_option_no_reregister_trigger);


const key_override_t **key_overrides = (const key_override_t *[]){
	&next_track_override,
	&prev_track_override,
	&brightness_up_override,
	&brightness_down_override,
	NULL
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
    [0] = { ENCODER_CCW_CW(C(KC_TAB), C(S(KC_TAB))), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) , ENCODER_CCW_CW(SPECIAL_ENC1, SPECIAL_ENC2)  , ENCODER_CCW_CW(ALT_TABBER2, ALT_TABBER1)   },
    [1] = { ENCODER_CCW_CW(LGUI(LALT(KC_RIGHT)), LGUI(LALT(KC_LEFT))), ENCODER_CCW_CW(KC_VOLU, KC_VOLD) , ENCODER_CCW_CW(SPECIAL_ENC1, SPECIAL_ENC2) , ENCODER_CCW_CW(MAC_CTRL_LEFT, MAC_CTRL_RIGHT)   },
    [2] = { ENCODER_CCW_CW(C(KC_TAB), C(S(KC_TAB))), ENCODER_CCW_CW(KC_A, KC_B) , ENCODER_CCW_CW(SPECIAL_ENC1, SPECIAL_ENC2)  , ENCODER_CCW_CW(KC_TRNS, KC_TRNS)   },
};
#endif


#if defined(DIP_SWITCH_MAP_ENABLE)
const uint16_t PROGMEM dip_switch_map[NUM_DIP_SWITCHES][NUM_DIP_STATES] = {
DIP_SWITCH_OFF_ON(DF(1), DF(0)),        DIP_SWITCH_OFF_ON(KC_NO, KC_NO),        DIP_SWITCH_OFF_ON(DIP3_2, DIP3_3),
    DIP_SWITCH_OFF_ON(KC_NO, DF(1)),     DIP_SWITCH_OFF_ON(KC_LEFT, KC_RIGHT),        DIP_SWITCH_OFF_ON(DIP3_2, DIP3_1),
    DIP_SWITCH_OFF_ON(KC_LEFT, KC_RIGHT),        DIP_SWITCH_OFF_ON(KC_NO, KC_NO),        DIP_SWITCH_OFF_ON(KC_NO, KC_NO),
    DIP_SWITCH_OFF_ON(KC_UP, KC_DOWN),     DIP_SWITCH_OFF_ON(KC_NO, KC_NO),        DIP_SWITCH_OFF_ON(KC_NO, KC_NO)
};
#endif


// bool dip_switch_update_user(uint8_t index, bool active){
//   switch(index){
//     case 0:
//       if(active){ // Win
//         default_layer_set(0);
//       }
//       else{ // Mac/Win
//         default_layer_set(1);
//       }
//       break;
//     // case 1:break;
//     // case 2:break;
//     // case 3:
//     //   if(active){
//     //     tap_code(DF(0));
//     //   }
//     //   else{
//     //     tap_code(DF(1));
//     //   }
//     //   break;
//     // case 4:break;
//     // case 5:break;
//     // case 6:break;
//     // case 7:break;
//   }
//   return true;
// }






void matrix_init_user(void) {
}
