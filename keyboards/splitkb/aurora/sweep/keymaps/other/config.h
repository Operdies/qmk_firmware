/* Copyright 2022 splitkb.com <support@splitkb.com>
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

#pragma once

// Not yet available in `keymap.json` format
#ifdef RGB_MATRIX_ENABLE
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES
#    define ENABLE_RGB_MATRIX_HUE_BREATHING
#    define ENABLE_RGB_MATRIX_FLOWER_BLOOMING
#endif

#ifdef MOUSEKEY_ENABLE                     // Default:
#    define MOUSEKEY_WHEEL_INTERVAL 50     // 100
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 100 // 40
#    define MOUSEKEY_MOVE_DELTA 8          // 8
#    define MOUSEKEY_MAX_SPEED 10          // 10
#    define MOUSEKEY_TIME_TO_MAX 50        // 30
#endif

#define RGB_DI_PIN D3
#define RGBLIGHT_ANIMATIONS

#define ENCODER_RESOLUTION 2
