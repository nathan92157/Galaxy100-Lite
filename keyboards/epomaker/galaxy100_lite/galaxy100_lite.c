/* Copyright 2025 Epomaker
 * Copyright 2025 Epomaker <https://github.com/Epomaker>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../lib/rdr_lib/rdr_common.h"

void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

led_config_t g_led_config = { {
    { 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 13       , 32       , 51         },
	{ 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , 29       , 30       , 31       , NO_LED   , NO_LED     },
	{ 37       , 38       , 39       , 40       , 41       , 42       , 43       , 44       , 45       , 46       , 47       , 48       , 49       , 50       , NO_LED   , NO_LED     },
	{ 56       , 57       , 58       , 59       , 60       , 61       , 62       , 63       , 64       , 65       , 66       , 67       , NO_LED   , 68       , NO_LED   , 69         },
	{ 73       , NO_LED   , 74       , 75       , 76       , 77       , 78       , 79       , 80       , 81       , 82       , 83       , NO_LED   , 84       , 85       , 86         },
	{ 89       , 90       , 91       , NO_LED   , 14       , 92       , 15       , 16       , 17       , 93       , 94       , NO_LED   , NO_LED   , 95       , 96       , 97         },
    { 33       , 34       , 35       , 36       , 52       , 53       , 54       , 70       , 71       , 72       , 55       , 87       , 88       , 98       , 99       , 100        }
},{
    { 0,  10}, { 22, 10}, { 33, 10}, { 44, 10}, { 55, 10}, { 72, 10}, { 83, 10}, { 94, 10}, { 105,10}, { 121, 10}, { 132, 10}, { 143, 10}, { 154, 10},             { 170, 10}, { 186, 10}, { 197, 10},{ 208, 10},{ 219, 10},
    { 0,  20}, { 11, 20}, { 22, 20}, { 33, 20}, { 44, 20}, { 55, 20}, { 66, 20}, { 67, 20}, { 88, 20}, { 99,  20}, { 110, 20}, { 121, 20}, { 132, 20}, { 148, 20}, { 170, 10}, { 186, 20}, { 197, 20},{ 208, 20},{ 219, 20},
    { 3,  30}, { 17, 30}, { 28, 30}, { 39, 30}, { 50, 30}, { 61, 30}, { 72, 30}, { 83, 30}, { 94, 30}, { 105, 30}, { 116, 30}, { 127, 30}, { 138, 30}, { 152, 30}, { 170, 10}, { 186, 30}, { 197, 30},{ 208, 30},{ 219, 30},
    { 4,  40},            { 19, 40}, { 30, 40}, { 41, 40}, { 52, 40}, { 63, 40}, { 74, 40}, { 85, 40}, { 96,  40}, { 107, 40}, { 118, 40} ,{ 129, 40}, { 148, 40}, { 170, 40}, { 186, 40}, { 197, 40},{ 208, 40},
    { 6,  50},            { 24, 50}, { 35, 50}, { 46, 50}, { 57, 50}, { 68, 50}, { 79, 50}, { 90, 50}, { 111, 50}, { 122, 50}, { 133, 50},             { 142, 50}, { 154, 50}, { 186, 50}, { 197, 50},{ 208, 50},
    { 0,  60}, { 15, 60}, { 30, 60},                                  { 70, 60},                                   { 120, 60}, { 135, 60},             { 143, 60}, { 154, 60}, { 165, 60}, { 196, 60},{ 208, 60},{ 219, 60}
}, {
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,  1,
    1,  1,  1,  1,      1,  1,  1,  1,  1,      1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();
    return false;
}

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state)  {
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if(usb_device_state == USB_DEVICE_STATE_CONFIGURED) {
            Usb_If_Ok = true;//usb枚举完成
            Usb_If_Ok_Led = true;
            Usb_If_Ok_Delay = 0;
        } else {
            Usb_If_Ok = false;
		    Usb_If_Ok_Led = false;
        }
    } else {
        Usb_If_Ok = false;
	    Usb_If_Ok_Led = false;
    }
}

void housekeeping_task_user(void) {
    User_Keyboard_Reset();
    es_chibios_user_idle_loop_hook();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
    Usb_Change_Mode_Delay = 0;                                      /*只要有按键就不会进入休眠*/
    Usb_Change_Mode_Wakeup = false;

    return Key_Value_Dispose(keycode, record);
}
