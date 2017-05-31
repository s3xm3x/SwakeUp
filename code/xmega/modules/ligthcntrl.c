/////////////////////////////////////////////////////////////////////////////////
//
//
// Author:				Maximilian Stiefel
// Last Modification:	24.05.2017
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////////
#include <avr/io.h>
#include <stdio.h>
#include "../util/fixedpoint.h"
#include "ligthcntrl.h"
#include "../drivers/host/pwm.h"
#include "../util/event.h"
#include "../drivers/host/timer.h"
#include "../modules/log.h"
#include "../pin_rev_1.h"

LOG_INIT("LIGHT");

/////////////////////////////////////////////////////////////////////////////////
// Typedefs
/////////////////////////////////////////////////////////////////////////////////
typedef enum mycolorstate_t {IDLE, PLAY_COLOR} mycolorstate_t;

/////////////////////////////////////////////////////////////////////////////////
// Globale Vars
/////////////////////////////////////////////////////////////////////////////////
static volatile myrgbcolor_t *patternQue[QUEUE_LENGTH] = {NULL};
static volatile uint16_t readInd;
static volatile uint16_t writeInd;

/////////////////////////////////////////////////////////////////////////////////
// Increase Ring Buffer Style
/////////////////////////////////////////////////////////////////////////////////
static inline incRingBuffer(uint16_t *i)
{
	if( (*i) < QUEUE_LENGTH)
		(*i)++;
	else
		(*i) = 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Set Colors
/////////////////////////////////////////////////////////////////////////////////
static inline setRGB(myrgbcolor_t *color)
{
	// TODO: In a later HW revision the PID controller has to be included here.
	if(color == NULL)
	{
		setDutyCycle_PWMRed(0);
		setDutyCycle_PWMBlue(0);
		setDutyCycle_PWMGreen(0);
	}
	else
	{
		setDutyCycle_PWMRed(color->red);
		setDutyCycle_PWMBlue(color->blue);
		setDutyCycle_PWMGreen(color->green);	
	}
}

/////////////////////////////////////////////////////////////////////////////////
// Add another Color to the Light Queue
/////////////////////////////////////////////////////////////////////////////////
uint8_t addToLigthPattern(myrgbcolor_t *color)
{
	if( patternQue[writeInd] == NULL)				// Check if queue is already full
	{
		patternQue[writeInd] = color;
		incRingBuffer(&writeInd);
		return 1;									// Successfully added element 
	}
	else
		return 0;
}

/////////////////////////////////////////////////////////////////////////////////
// Executet every 100 ms
/////////////////////////////////////////////////////////////////////////////////
static void light(Event * event, uint8_t * data __attribute__ ((unused))) 
{
	static volatile mycolorstate_t currentState = IDLE;
	if (event == &EVENT_TIMER_10_HZ) 
	{
		switch (currentState)
		{
		case IDLE:
			if(patternQue[readInd] != NULL)
			{
				setRGB(patternQue[readInd]);
				(patternQue[readInd]->duration)--;
				currentState = PLAY_COLOR;
			}
			else
			{
				setRGB(NULL);
			}
			break;
		case PLAY_COLOR:
				if( (patternQue[readInd]->duration) > 0)
				{
					LOG_DEBUG("Hejsan, %d", patternQue[readInd]->duration);
					(patternQue[readInd]->duration)--;
				}
				else
				{
					incRingBuffer(&readInd);
					currentState = IDLE;
				}
			break;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////
// Enable Light Controller
/////////////////////////////////////////////////////////////////////////////////
void enableLightCnt(void)
{
	LOG_DEBUG("Ligth controller enabled.");
	event_addListener(&EVENT_TIMER_10_HZ, light);
}

/////////////////////////////////////////////////////////////////////////////////
// Disable Light Controller
/////////////////////////////////////////////////////////////////////////////////
void stopLightCnt(void)
{
	LOG_DEBUG("Ligth controller disabled.");
	event_removeListener(&EVENT_TIMER_10_HZ, light);
}
