#pragma once


#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    "ander"
#define PRODUCT         "ander_keeb"

#define MATRIX_ROWS 6
#define MATRIX_COLS 18



#define MATRIX_ROW_PINS { F2, F3, F4, F5, F6, F7}
#define MATRIX_COL_PINS { F1, F0, E6, E7, B0, B1, B2, D4, D5, D7, E0, E1, C0, C1, C2, C3, C4, C5}
#define UNUSED_PINS

#define ENCODERS_PAD_A { C6, A0, A1, A2 }
#define ENCODERS_PAD_B { C7, A4, A5, A6 }

#define ENCODER_RESOLUTIONS { 4, 4, 4, 4 }


#define DIP_SWITCH_MATRIX_GRID { {2,14}, {2,15}, {2,16},\
                                 {3,14}, {3,15}, {3,16},\
                                 {4,14}, {4,15}, {4,16},\
                                 {5,14}, {5,15}, {5,16} }



/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5




/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
