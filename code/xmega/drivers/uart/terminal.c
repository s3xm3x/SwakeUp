/*
 * terminal.c
 *
 * Created: 11/14/2016 2:46:45 PM
 *  Author: elmar
 */
#include "terminal.h"
#include "../host/uart.h"
#include "../../util/job.h"
#include "../../modules/log.h"
#include "../../tinyprint/printf.h"
#include "../../pin_definitions.h"
#include <stdarg.h>

LOG_INIT("Terminal");
EVENT_REGISTER(EVENT_TERMINAL_SPECIAL, "Special character");

void (*sink) (void*, char);

uint8_t isArr = 0;

static void echo_uart(char received) {
    if ((uint8_t)received == 13) {
        uart_writes('\r', &DEBUG_UART);
        uart_writes('\n', &DEBUG_UART);
    }
    if (received == '[') {
        isArr = 1;
    } else  if (isArr == 1 || (uint8_t) received == 9) {
        enum TERMINAL_SPECIAL_KEY key = KEY_TAB;
        switch (received) {
        case 'A':
            key = ARR_UP;
            break;
        case 'B':
            key = ARR_DOWN;
            break;
        case 'C':
            key = ARR_LEFT;
            break;
        case 'D':
            key = ARR_RIGHT;
            break;
        case 9:
            key = KEY_TAB;
            break;
        }
        isArr = 2;
        event_fire(&EVENT_TERMINAL_SPECIAL, (uint8_t* )key);
    } else {
        if (isArr == 0) {
            uart_writes(received, &DEBUG_UART);
            if ((uint8_t)received == 8 || (uint8_t)received == 127) {
                struct UartBuffer * inBuf = getInBuffer(&CP_PORT);
                if (inBuf->size > 1) {
                    inBuf->size -= 2;
                    if (inBuf->head == 1) {
                        inBuf->head = UART_MAX_IN_BUFFER - 1;
                    } else {
                        inBuf->head -= 2;
                    }
                }
            }
        } else {
            isArr = 0;
        }
    }
}
static void write_block(void * p __attribute__ ((unused)), char c) {
    uart_write_blocked(c, &DEBUG_UART);
}
static void write(void * p __attribute__ ((unused)), char c) {
    uart_writes(c, &DEBUG_UART);
}
void (*terminal_current_sink(void))(void *, char ) {
    return sink;
}
void terminal_set_sink(void (*putcf) (void*, char)) {
    sink = putcf;
}
void terminal_default_sink(void) {
    sink = &write;                          //default
    LOG_SYSTEM("Reverted back to default sink");
}
uint8_t terminal_write(char * format, ...) {
    init_printf((void*)0, sink);
    va_list arg;
    va_start(arg, format);
    tfp_format(0, sink, format, arg);
    va_end(arg);
    return 1;
}
void terminal_write_force(char * format, ...) {
    init_printf((void*)0, sink);
    va_list arg;
    va_start(arg, format);
    tfp_format(0, sink, format, arg);
    va_end(arg);
}
uint8_t terminal_format_p(const char *fmt, va_list va) {
    init_printf((void*)0, sink);
    tfp_format_p(0, sink, (char *) fmt, va); //stupid printf library, casting here is bad practice!
    return 1;
}
uint8_t terminal_format(const char *fmt, va_list va) {
    init_printf((void*)0, sink);
    tfp_format(0, sink, (char *) fmt, va); //stupid printf library, casting here is bad practice!
    return 1;
}
void terminal_format_blocking(const char *fmt, va_list va) {
    init_printf((void*)0, write_block);
    tfp_format(0, write_block, (char *) fmt, va); //stupid printf library, casting here is bad practice!
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
// static void callback(Event * event, uint8_t * data) {
//     if (event == &EVENT_UART_JOB) {
//         // don't have to do anything i guess
//     }
// }
void terminal_putc(char c __attribute__ ((unused))) {
    sink(0, c);
}
char terminal_getc(void) {
    LOG_WARNING("Not implemented");
    return '0';
}
static uint8_t init(void) {
    sink = &write;                          //default
    uart_set_callback(&echo_uart, &CP_PORT);
    terminal_write("Terminal initialized\n\r");
    return 1;
}
static uint8_t deinit(void) {
    //event_removeListener(&EVENT_UART_JOB, callback);
    return 1;
}
MODULE_DEFINE(TERMINAL, "Uart terminal", init, deinit, &UART);