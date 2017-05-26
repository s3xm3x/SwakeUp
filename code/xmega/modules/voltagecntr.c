/////////////////////////////////////////////////////////////////////////////////
// Voltage controller based on a low-pass filter, PWM and an non-inv. opamp.
//
// Author:				Maximilian Stiefel
// Last Modification:	24.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include "pid.h"
#include "voltagecntr.h"
#include "../../util/fixedpoint.h"
#include "../drivers/host/adc.h"
#include "../drivers/host/pwm.h"
#include "../../modules/log.h"
#include "../defines.h"

LOG_INIT("OLED");

/////////////////////////////////////////////////////////////////////////////////
// Global variables
/////////////////////////////////////////////////////////////////////////////////
mycontroller_t oledController;

/////////////////////////////////////////////////////////////////////////////////
// Init controller
/////////////////////////////////////////////////////////////////////////////////
void initVolCnt(void)
{
	oledController.kd = KD;
	oledController.ki = KI;
	oledController.kp = KP;
	oledController.getSensorVal = &getVal_ADCOLED;
	oledController.setActuatorVal = &setDutyCycle_PWMOLED;
	oledController.enabled = 0;												// Keep disabled
	add_Controller(&oledController);
}

/////////////////////////////////////////////////////////////////////////////////
// Enable controller
/////////////////////////////////////////////////////////////////////////////////
void enableVolCnt(void)
{
	oledController.enabled = 1;	
}

/////////////////////////////////////////////////////////////////////////////////
// Disable controller
/////////////////////////////////////////////////////////////////////////////////
void disableVolCnt(void)
{
	oledController.enabled = 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Set voltage
/////////////////////////////////////////////////////////////////////////////////
void setVolCnt(uint16_t voltage)
{
	myfixedpoint32_t uoledCounts = 0;
	myfixedpoint32_t voltageAtADC = 0;
	
	voltageAtADC = fixedPt_mul( FROMINT(voltage), FROMFLOAT(VOLTAGEDIV_GAIN10E6) );								// Voltage divider: VADC = VOLED R2/(R1+R2)			
	uoledCounts = fixedPt_div( voltageAtADC, FROMFLOAT(VPERCOUNT_GAIN10E6) );									// Convert to counts: VADC / VPERCOUNT
	oledController.setPoint = TOUINT16T(uoledCounts);
}