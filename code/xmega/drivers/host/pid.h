/////////////////////////////////////////////////////////////////////////////////
// 
//
// Author:				Maximilian Stiefel
// Last Modification:	16.05.2017
/////////////////////////////////////////////////////////////////////////////////

#ifndef XMEGA_MODULES_PID_H_
#define XMEGA_MODULES_PID_H_

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////
#define DT (1/100)
#define KP 10
#define KI 0
#define KD 0

/////////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////////
void start_PID(uint16_t isetpoint);
void stop_PID();

static uint8_t init(void);
static uint8_t deinit(void);
void start_PID(uint16_t isetpoint);

MODULE_EXP(PID);

#endif /* XMEGA_MODULES_PID_H_ */