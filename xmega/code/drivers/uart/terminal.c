/*
 * terminal.c
 *
 * Created: 11/14/2016 2:46:45 PM
 *  Author: elmar
 */
#include "terminal.h"
#include "../host/uart.h"
#include "../../util/event.h"
#include "../../util/job.h"
#include "../../modules/log.h"
#include "../../tinyprint/printf.h"
#include "../../pin_definitions.h"
#include <stdarg.h>

LOG_INIT("Terminal");

static void write_block(void * p, char c) {
    uart_write_blocked(c, &CP_PORT);
}

static void write(void * p, char c) {
    uart_writes(c, &CP_PORT, &CP_PORT);
    //terminal_putc(c);
}

uint8_t terminal_write(char * format, ...) {
    init_printf((void*)0, write);
    va_list arg;
    va_start(arg, format);
    tfp_format(0, write, format, arg);
    va_end(arg);
    return 1;
}

void terminal_write_force(char * format, ...) {
    init_printf((void*)0, write);
    va_list arg;
    va_start(arg, format);
    tfp_format(0, write, format, arg);
    va_end(arg);
}

uint8_t terminal_format(char *fmt, va_list va) {
    init_printf((void*)0, write);
    tfp_format(0, write, fmt, va);
    return 1;
}

void terminal_format_force(char *fmt, va_list va) {
    init_printf((void*)0, write);
    tfp_format(0, write, fmt, va);
}

void terminal_format_blocking(char *fmt, va_list va) {
    init_printf((void*)0, write_block);
    tfp_format(0, write_block, fmt, va);
}

void terminal_write_block(char * format, ...) {
    init_printf((void*)0, write_block);
    va_list arg;
    va_start(arg, format);
    tfp_format(0, write_block, format, arg);
    va_end(arg);
}

void terminal_flush(void) {
    //lets keep it easy, it always flushes for now
}


static void callback(Event * event, uint8_t * data) {
    if (event == &EVENT_UART_JOB) {
        // don't have to do anything i guess
    }
}

void terminal_putc(char c) {
}

char terminal_getc(void) {
    return '0';
}

uint8_t terminal_level_in(void) {
    return 0;
}

static void initalizeCallback(Event * event, uint8_t * data) {
    LOG_SYSTEM("Uart set up");
    event_removeListener(&EVENT_UART_JOB, initalizeCallback);
}

static uint8_t init(void) {
    terminal_write("Terminal initialized\n\r");
    // event_addListener(&EVENT_UART_JOB, callback);
    //event_addListener(&EVENT_UART_JOB, initalizeCallback);
    return 1;
}
static uint8_t deinit(void) {
    event_removeListener(&EVENT_UART_JOB, callback);
    event_removeListener(&EVENT_UART_JOB, initalizeCallback);
    return 1;
}
MODULE_DEFINE(TERMINAL, "Uart terminal", init, deinit, &UART);