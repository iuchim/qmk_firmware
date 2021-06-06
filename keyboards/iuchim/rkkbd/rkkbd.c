/* Copyright 2021 iuchim
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

#include "rkkbd.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = { {
  { NO_LED, NO_LED, NO_LED,      0,      1,      2 },
  {      8,      7,      6,      5,      4,      3 },
  {      9,     10,     11,     12,     13,     14 },
  {     20,     19,     18,     17,     16,     15 },
  {     21,     22,     23,     24, NO_LED, NO_LED },
  { NO_LED, NO_LED, NO_LED,     25,     26,     27 },
  {     33,     32,     31,     30,     29,     28 },
  {     34,     35,     36,     37,     38,     39 },
  {     45,     44,     43,     42,     41,     40 },
  {     46,     47,     48,     49, NO_LED, NO_LED },
}, {
  {  32,   0 }, {  16,   2 }, {  0,  3 },
  {   0,  11 }, {  16,  10 }, { 32,  8 }, { 48,  8 }, { 64,  9 }, { 80, 11 },
  {  80,  19 }, {  64,  17 }, { 48, 16 }, { 32, 16 }, { 16, 18 }, {  0, 19 },
  {   0,  27 }, {  16,  26 }, { 32, 24 }, { 48, 24 }, { 64, 25 }, { 80, 27 },
  {  88,  36 }, {  72,  33 }, { 56, 32 }, { 40, 32 },
  {  224-32,   0 }, {  224-16,   2 }, { 224- 0,  3 },
  {  224- 0,  11 }, {  224-16,  10 }, { 224-32,  8 }, { 224-48,  8 }, { 224-64,  9 }, { 224-80, 11 },
  {  224-80,  19 }, {  224-64,  17 }, { 224-48, 16 }, { 224-32, 16 }, { 224-16, 18 }, { 224- 0, 19 },
  {  224- 0,  27 }, {  224-16,  26 }, { 224-32, 24 }, { 224-48, 24 }, { 224-64, 25 }, { 224-80, 27 },
  {  224-88,  36 }, {  224-72,  33 }, { 224-56, 32 }, { 224-40, 32 }
}, {
  4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4,
  4, 4, 4, 4
} };

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

#endif
