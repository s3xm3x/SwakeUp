/////////////////////////////////////////////////////////////////////////////////
// Voltage controller based on a low-pass filter, PWM and an non-inv. opamp.
//
// Author:				Maximilian Stiefel
// Last Modification:	24.05.2017
/////////////////////////////////////////////////////////////////////////////////

#ifndef XMEGA_MODULES_VOLTAGECNTR_H_
#define XMEGA_MODULES_VOLTAGECNTR_H_

/////////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////////
// TODO: Fine tune the PID
#define KP FROMFLOAT(0.2)
#define KI FROMFLOAT(1.0)
#define KD FROMFLOAT(0.8)

#define VOLTAGEDIV_GAIN10E6 47.61904e3

/////////////////////////////////////////////////////////////////////////////////
// Prototypes
/////////////////////////////////////////////////////////////////////////////////
void initVolCnt(void);
void disableVolCnt(void);
void enableVolCnt(void);
void setVolCnt(uint16_t voltage);

#endif /*XMEGA_MODULES_VOLTAGECNTR_H_ */