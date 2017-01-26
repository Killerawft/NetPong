dnl
dnl   Copyright (c) 2013-2015 by Michael Brakemeier <michael@brakemeier.de>
dnl  
dnl   This program is free software; you can redistribute it and/or modify
dnl   it under the terms of the GNU General Public License version 3 as
dnl   published by the Free Software Foundation.
dnl
dnl   This program is distributed in the hope that it will be useful,
dnl   but WITHOUT ANY WARRANTY; without even the implied warranty of
dnl   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
dnl   GNU General Public License for more details.
dnl
dnl   You should have received a copy of the GNU General Public License
dnl   along with this program; if not, write to the Free Software
dnl   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
dnl
dnl   For more information on the GPL, please go to:
dnl   http://www.gnu.org/copyleft/gpl.html
dnl
divert(-1)dnl
define(`preamble_divert',0)dnl
define(`header_file_divert', `eval(preamble_divert` + 1')')dnl
define(`implementation_start_divert', `eval(header_file_divert` + 1')')dnl
define(`milliticks_isr_divert', `eval(implementation_start_divert` + 1')')dnl
define(`milliticks_divert', `eval(milliticks_isr_divert` + 1')')dnl
define(`postamble_divert', `eval(milliticks_divert` + 1')')dnl

dnl save current divert value
define(`pushdivert', `define(`_old_divert', divnum)')dnl
define(`popdivert', `divert(_old_divert)')dnl

define(`periodic_milliticks_header', `divert(header_file_divert)#include "$1"
divert(-1)')

define(`periodic_milliticks_isr', `ifelse($#, 0, ``$0'', $1,,,dnl
`pushdivert()divert(milliticks_isr_divert)  $1;
popdivert()')')dnl

divert(preamble_divert)dnl
/* This file has been generated by meta_periodic_milliticks.m4 automatically.
   Please do not modify it, edit the m4 script instead. */

#include <stdint.h>

#include <avr/io.h>
#include <avr/interrupt.h>

#include "config.h"

#include "core/periodic.h"

#ifdef CLOCK_PERIODIC_SUPPORT
#include "services/clock/clock.h"
#endif

/* all millitickers header files */
divert(header_file_divert)dnl
divert(implementation_start_divert)dnl

/* signal a new timer() tick to meta */
extern volatile uint8_t newtick;

#if (CONF_MTICKS_PER_SEC > HZ)
/* internal 20ms counter */
static volatile uint8_t periodic_hz_tick;
#endif

/**
 * Timer/Counter overflow ISR with milliticks support.
 *
 * This ISR is called CONF_MTICKS_PER_SEC times per second.
 */
ISR(PERIODIC_VECTOR_OVERFLOW)
{
  periodic_mticks_count++;
  
#if (CONF_MTICKS_PER_SEC > HZ)
  periodic_hz_tick++;
#endif

#ifdef DEBUG_PERIODIC
  if (pdebug_milliticks > pdebug_milliticks_max)
    pdebug_milliticks_max = pdebug_milliticks;

  pdebug_milliticks++;

#ifdef DEBUG_PERIODIC_WAVEFORMS_SUPPORT
  PIN_TOGGLE(PERIODIC_WAVETICK_OUT);
#endif
#endif

#if (CONF_MTICKS_PER_SEC > HZ)
  if (periodic_hz_tick >= (CONF_MTICKS_PER_SEC / HZ))
  {
    /* 20ms overflow */
#endif

#ifdef DEBUG_PERIODIC
    // should be CONF_MTICKS_PER_SEC / HZ periodic milliticks since last overflow
    if (pdebug_milliticks < (pdebug_milliticks_last + (CONF_MTICKS_PER_SEC / HZ) - 1))
      pdebug_milliticks_miss += (pdebug_milliticks_last + (CONF_MTICKS_PER_SEC / HZ) - pdebug_milliticks);

#ifdef DEBUG_PERIODIC_WAVEFORMS_SUPPORT
    PIN_TOGGLE(PERIODIC_WAVE25HZ_OUT);
#endif
#endif

    // signal a new timer() tick to meta
    newtick = 1;

#ifdef DEBUG_PERIODIC
    if (pdebug_milliticks >= CONF_MTICKS_PER_SEC)
      pdebug_milliticks = 0;
#endif

#ifdef CLOCK_PERIODIC_SUPPORT
    /* tick the clock module */
    clock_tick();
#endif

#ifdef DEBUG_PERIODIC
    pdebug_milliticks_last = pdebug_milliticks;
#endif

#if (CONF_MTICKS_PER_SEC > HZ)
    periodic_hz_tick = 0;
  }
#endif

  // call all the millitickers
divert(milliticks_isr_divert)dnl
divert(postamble_divert)dnl

}
divert(-1)dnl
