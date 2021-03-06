/* Copyright 2021 kb-elmo<mail@elmo.space>
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

#include "quantum.h"

#define ____ KC_NO

#define LAYOUT_tkl_ansi( \
    k000,       k001, k011, k002, k012, k003, k013, k004, k014, k005, k015, k006, k016,    k007, k017, k008, \
    k020, k030, k021, k031, k022, k032, k023, k033, k024, k034, k025, k035, k026, k036,    k027, k037, k028, \
    k040, k050, k041, k051, k042, k052, k043, k053, k044, k054, k045, k055, k046, k056,    k047, k057, k048, \
    k060, k070, k061, k071, k062, k072, k063, k073, k064, k074, k065, k075,    k066,                         \
       k080,    k090, k081, k091, k082, k092, k083, k093, k084, k094, k085,    k086,             k097,       \
    k100, k110, k101,                   k112,                   k114, k105, k115, k106,    k107, k117, k108  \
) { \
    { k000, k001, k002, k003, k004, k005, k006, k007, k008 }, \
    { ____, k011, k012, k013, k014, k015, k016, k017, ____ }, \
    { k020, k021, k022, k023, k024, k025, k026, k027, k028 }, \
    { k030, k031, k032, k033, k034, k035, k036, k037, ____ }, \
    { k040, k041, k042, k043, k044, k045, k046, k047, k048 }, \
    { k050, k051, k052, k053, k054, k055, k056, k057, ____ }, \
    { k060, k061, k062, k063, k064, k065, k066, ____, ____ }, \
    { k070, k071, k072, k073, k074, k075, ____, ____, ____ }, \
    { k080, k081, k082, k083, k084, k085, k086, ____, ____ }, \
    { k090, k091, k092, k093, k094, ____, ____, k097, ____ }, \
    { k100, k101, ____, ____, ____, k105, k106, k107, k108 }, \
    { k110, ____, k112, ____, k114, k115, ____, k117, ____ }  \
}
