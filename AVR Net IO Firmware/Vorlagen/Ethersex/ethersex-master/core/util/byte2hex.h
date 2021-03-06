/*
* byte to HEX utils
*
* Copyright (c) 2013 by Frank Sautter <ethersix@sautter.com>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the Free
* Software Foundation; either version 3 of the License, or (at your option)
* any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along with
* this program; if not, write to the Free Software Foundation, Inc., 675 Mass
* Ave, Cambridge, MA 02139, USA.
*
* For more information on the GPL, please go to:
* http://www.gnu.org/copyleft/gpl.html
*/

#ifndef _UTIL_BTOH_H_
#define _UTIL_BTOH_H_

#define NIBBLE_TO_HEX(a) ((a) < 10 ? (a) + '0' : ((a) - 10 + 'A'))

uint8_t byte2hex (uint8_t value, char *string);

#endif
