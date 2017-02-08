/*
 * lab2.c
 *
 * Created: 10/31/2016 3:44:36 PM
 * Author : elmar
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "pin_definitions.h"
#include "drivers/host/timer.h"
#include "drivers/host/uart.h"
#include "drivers/uart/terminal.h"
#include "modules/log.h"

static void callback(Event * event, uint8_t * data);

LOG_INIT("Main");

static void sleep(void) {
    //sleep_enable();
    sleep_cpu();
}

static void wakeUp(void) {
    sleep_disable();
    //ADCSRA = adcsra;
}

void switchExternalCrystal_16mHz(void) {
    //16MHz external crystal
    OSC_XOSCCTRL = OSC_FRQRANGE_12TO16_gc | OSC_XOSCSEL_XTAL_16KCLK_gc;
    //Enable external oscillator
    OSC_CTRL |= OSC_XOSCEN_bm;
    //Wait for clock stabilization
    while (!(OSC_STATUS & OSC_XOSCRDY_bm));
    // Selects clock system as external clock
    // through change protection mechanism
    CCP = CCP_IOREG_gc;
    CLK_CTRL = CLK_SCLKSEL_XOSC_gc;
}

int main(void) {
    switchExternalCrystal_16mHz();
    LED_PORT.DIR = LED_PIN;
    LED_PORT.OUTTGL = LED_PIN;
#ifdef EVENT_SUPPORTS_SLEEP
    event_init(sleep, wakeUp);
    sleep_enable();
    set_sleep_mode(SLEEP_MODE_IDLE);
#endif
    //module_init(&Screen);
    PMIC.CTRL |= PMIC_LOLVLEN_bm | PMIC_MEDLVLEN_bm;    //Peripheral enable - interrupt levels (ALL)
    module_init(&LOGGER);                               //Initializing the logger for use
    _delay_ms(200);
    module_init(&TIMER);                                //Timer
    _delay_ms(200);
    event_addListener(&EVENT_TIMER_1_HZ, callback);     //TODO this can be removed
    sei();                                              //Enabling interrupts
    _delay_ms(200);
    LOG_SYSTEM("System initialized");
    //event_addListener(&EVENT_UART_JOB, callback);
    while (1) {
        //This is all that should happen in the main loop
        //The system will go to sleep if no more events are to be processed
        event_process();
    }
}

static const char _job[] = "\n\r job \n\r";
static void callback(Event * event, uint8_t * data) {
    static uint8_t i = 0;
    if (event == &EVENT_TIMER_1_HZ) {
        //LED_PORT.OUTTGL = LED_PIN;
        LOG_DEBUG("Timer event %d ja", i++);
    }
}