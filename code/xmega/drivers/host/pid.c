/////////////////////////////////////////////////////////////////////////////////
// PID controller to run with a certain frequency.
//
// Author:				Maximilian Stiefel
// Last Modification:	16.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../../modules/log.h"
#include "../../util/fixedpoint.h"
#include "adc.h"
#include "pwm.h"
#include "pid.h"

LOG_INIT("PID");

/////////////////////////////////////////////////////////////////////////////////
// Global Variables
/////////////////////////////////////////////////////////////////////////////////
uint16_t setPoint = 0;

/////////////////////////////////////////////////////////////////////////////////
// Hook  for 100 Hz event (actual PID algorithm)
/////////////////////////////////////////////////////////////////////////////////
static void pid(Event * event, uint8_t * data __attribute__ ((unused))) {
	//Variables
	static myfixedpoint32_t drive = 0;
	myfixedpoint32_t error = 0;
	uint16_t actualValue = 0;
	
	//Action
	if (event == &EVENT_TIMER_1_HZ) {
		actualValue = getVal_ADCOLED();
		error = FROMINT(setPoint) - FROMINT(actualValue);
		LOG_DEBUG("setPoint: %d", setPoint);
		LOG_DEBUG("error: %d", error);
		drive += KP*error;
		LOG_DEBUG("drive: %d", drive);
		setDutyCycle_PWMOLED(TOUINT16T(drive));
		LOG_DEBUG("actualValue: %d", actualValue);
		LOG_DEBUG("-----------------------");
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Start PID controller
/////////////////////////////////////////////////////////////////////////////////
void start_PID(uint16_t isetpoint)
{
	LOG_DEBUG("PID started.");
	setPoint = isetpoint;
	event_addListener(&EVENT_TIMER_1_HZ, pid);
}

/////////////////////////////////////////////////////////////////////////////////
// Stop PID controller
/////////////////////////////////////////////////////////////////////////////////
void stop_PID()
{
	LOG_DEBUG("PID stopped.");
	event_removeListener(&EVENT_TIMER_1_HZ, pid);
}

/////////////////////////////////////////////////////////////////////////////////
// Init and deinit of this module
/////////////////////////////////////////////////////////////////////////////////
static uint8_t init(void)
{
	LOG_DEBUG("Hej");
	start_PID(1000);
	return EXIT_SUCCESS;
}

static uint8_t deinit(void)
{
	return EXIT_SUCCESS;
}

MODULE_DEFINE(PID, "PID Controller", &init, &deinit);