/*
 * timer.h
 *
 * Created: 11/14/2016 1:11:16 AM
 *  Author: elmar
 */


#ifndef TIMER_H_
#define TIMER_H_

#include "../../util/event.h"
#include "../../util/module.h"

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////
#define TICK_1KHZ 250-1;
#define TICK_100HZ 2500-1;
//#define EXPERIMENTAL				// Background: A fast system tick (event with 1 kHz produced by overflow ISR TCC0) does not work yet  with 16 MHz, processing is too slow I guess
									// TODO: Test it with 32 MHz

/////////////////////////////////////////////////////////////////////////////////
// Event export
/////////////////////////////////////////////////////////////////////////////////
EVENT_EXP(EVENT_TIMER_1_HZ);
EVENT_EXP(EVENT_TIMER_10_HZ);
EVENT_EXP(EVENT_TIMER_100_HZ);
EVENT_EXP(EVENT_TIMER_1000_HZ);
EVENT_EXP(EVENT_ALARM);

/////////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////////
uint16_t timer_runTime(void);
int8_t   timer_timeOutEvent(uint16_t duration);

MODULE_EXP(TIMER);

#endif /* TIMER_H_ */