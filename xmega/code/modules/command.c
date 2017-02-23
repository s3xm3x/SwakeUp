/*
 * command.c
 *
 * Created: 2/8/2017 11:26:54 PM
 *  Author: elmar
 */

#include "command.h"
#include "../drivers/host/uart.h"
#include "log.h"
#include "../util/event.h"
#include  "../pin_definitions.h"

LOG_INIT("Command");

// Character of the command to hook to, callback(len,data)
static void (* commands[26])(uint8_t, uint8_t *) = {0};

static int8_t translateCommand(char command) {
    int8_t val = (uint8_t) command;
    if (val > 90) {
        //  LOG_WARNING("Command(%c) is not capitalized", command); //Todo, do we really want this? we correct it either way
        val -= 32;
    }
    val -= 65;
    if (val < 0 || val > 26) {
        return -1;
    }
    return (int8_t) val;
}

uint8_t command_hook(char command, void (* callback)(uint8_t, uint8_t *)) {
    int8_t val = translateCommand(command);
    if (val == -1) return 0;
    if (commands[val] != 0) {
        LOG_WARNING("Command %c not added, already in use!");
        return 0;
    }
    commands[val] = callback;
    LOG_DEBUG("Added command %c", command);
    return 1;
}

uint8_t command_remove(char command, void (* callback)(uint8_t, uint8_t *)) {
    int8_t val = translateCommand(command);
    if (val == -1) return 0;
    if (commands[val] == callback) {
        LOG_DEBUG("Removed command %c", command);
        commands[val] = 0;
        return 1;
    } else {
        if (commands[val] == 0) {
            LOG_WARNING("Command %c not removed: not assigned", command);
        } else {
            LOG_WARNING("Command %c has different callback", command);
        }
        return 0;
    }
}

void command_remove_force(char command) {
    int8_t val = translateCommand(command);
    if (val != -1) {
        commands[val] = 0;
    }
}

void callback(Event * event, uint8_t * data) {
    struct UartDelimiter * delimiter = (struct UartDelimiter*)data;
    if (delimiter->port == &DEBUG_UART) {
        char command;
        if (!uart_reads_buffer(&command, &DEBUG_UART)) {
            LOG_ERROR("No bytes in buffer but we expect something");
        } else {
            int8_t val = translateCommand(command),  len = 0;
            char data[delimiter->length], read;
            while (uart_reads_buffer(&read, &DEBUG_UART)) {
                data[len] = read;
                len++;
            }
            if (val != -1) {
                if (commands[val] == 0) {
                    LOG_WARNING("Command %c is not assigned", command);
                } else {
                    LOG_SYSTEM("Received command: %c", command);
                    commands[val](len, data);
                }
            } else {
                while (uart_reads_buffer(&read, &DEBUG_UART));  //flush the buffer
            }
            //if its our uart
        }
        uart_delimiter_handled(delimiter);
    }
}
static uint8_t init(void) {
    event_addListener(&EVENT_UART_DELIMITER, callback);
    uart_add_delimiter('\n', &DEBUG_UART);
    uart_add_delimiter('\r', &DEBUG_UART);
    LOG_SYSTEM("Command initialized");
    return 1;
}
static uint8_t deinit(void) {
    event_removeListener(&EVENT_UART_DELIMITER, callback);
    //TODO remove delimiter
    return 1;
}
MODULE_DEFINE(COMMAND, "Command", init, deinit, &LOGGER);