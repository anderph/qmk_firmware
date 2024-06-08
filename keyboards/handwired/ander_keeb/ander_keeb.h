#ifndef ANDER_KEEB_H
#define ANDER_KEEB_H

#include "quantum.h"

#define KEYMAP( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, K012,                   K016,       \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116,       \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K215, K216, K217, \
	K300, K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311,       K313, K314, K315, K316, K317, \
	K400, K401, K402, K403, K404, K405, K406, K407, K408, K409, K410,       K412,       K414, K415, K416, K417, \
	K500, K501, K502,             K505,                   K509, K510, K511, K512,       K514, K515, K516, K517  \
) { \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011,  K012,  KC_NO, KC_NO, KC_NO, K016,  KC_NO }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111,  K112,  K113,  K114,  K115,  K116,  KC_NO }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211,  K212,  K213,  K214,  K215,  K216,  K217 }, \
	{ K300,  K301,  K302,  K303,  K304,  K305,  K306,  K307,  K308,  K309,  K310,  K311,  KC_NO, K313,  K314,  K315,  K316,  K317 }, \
	{ K400,  K401,  K402,  K403,  K404,  K405,  K406,  K407,  K408,  K409,  K410,  KC_NO, K412,  KC_NO, K414,  K415,  K416,  K417 }, \
	{ K500,  K501,  K502,  KC_NO, KC_NO, K505,  KC_NO, KC_NO, KC_NO, K509,  K510,  K511,  K512,  KC_NO, K514,  K515,  K516,  K517 }  \
}


#endif
