/*
 * command.c
 *
 * Created: 2/8/2017 11:26:54 PM
 *  Author: elmar
 */

#include "command.h"
#include "../drivers/host/uart.h"
#include "log.h"
#include "../drivers/uart/terminal.h"
#include "../util/event.h"
#include  "../pin_definitions.h"

LOG_INIT("Command");

// Character of the command to hook to, callback(len,data)
static void (* commands[26])(uint8_t, char *) = {0};
static char * descriptions[26] = {0};

uint8_t command_arguments(char *data, uint8_t len) {
    uint8_t index = 0;
    uint8_t arguments = 0;
    while (index < len) {
        if (data[index] == ' ') arguments++;
        index++;
    }
    return arguments;
}

char command_next_char(uint8_t * index, char * string, uint8_t size) {
    while (!(string[*index] >= 'a' && string[(*index)] <= 'Z') && (*index) < size) {
        (*index)++;
    }
    return string[*index];
}

uint32_t command_next_int(uint8_t * index, char * string, uint8_t size) {
    uint32_t num = 0;
    while (!(string[*index] >= '0' && string[(*index)] <= '9') && (*index) < size) {
        (*index)++;
    }
    while (string[*index] >= '0' && string[(*index)] <= '9' && (*index) < size) {
        num *= 10;
        num += string[*index] - '0';
        (*index)++;
    }
    return num;
}

uint8_t command_next_arg(char *data, uint8_t len) {
    uint8_t tempIndex = 0;
    while (data[tempIndex] < (uint8_t)'!' && tempIndex < len)    {
        //skipping all the spaces and other non text variables
        tempIndex++;
    }
    if (tempIndex == len) return 0;//we are at the end, no more characters!
    return tempIndex;
}

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

uint8_t command_hook(char command, void (* callback)(uint8_t, char *)) {
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

uint8_t command_hook_description(char command, void (* callback)(uint8_t, char *), char * description) {
    int8_t val = translateCommand(command);
    if (val == -1) return 0;
    if (commands[val] != 0) {
        LOG_WARNING("Command %c not added, already in use!");
        return 0;
    }
    commands[val] = callback;
    descriptions[val] = description;
    LOG_DEBUG("Added command %c", command);
    return 1;
}

uint8_t command_remove(char command, void (* callback)(uint8_t, char *)) {
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

static void callback(Event * event, uint8_t * data) {
    if (event == &EVENT_UART_DELIMITER) {
        struct UartDelimiter * delimiter = (struct UartDelimiter*)data;
        if (delimiter->port == &DEBUG_UART) {
            char command;
            if (!uart_reads_buffer(&command, &DEBUG_UART)) {
                LOG_ERROR("No bytes in buffer but we expect something");
            } else {
                if (command == '?') {
                    uint8_t i;
                    LOG_SYSTEM("Following commands are registered: ");
                    terminal_write("? | Prints out this help\r\n");
                    for (i = 0; i < 26; i++) {
                        if (commands[i] != 0) {
                            if (descriptions[i] != 0) {
                                terminal_write("%c | %s\r\n", (char)(i + 65), descriptions[i]);
                            } else {
                                terminal_write("%c |\r\n", (char)(i + 65));
                                //LOG_SYSTEM("%c", (char)(i + 65));
                            }
                        }
                    }
                    char read;
                    while (uart_reads_buffer(&read, &DEBUG_UART));  //flush the buffer
                } else {
                    int8_t val = translateCommand(command),  len = 0;
                    char readData[delimiter->length], read;
                    while (uart_reads_buffer(&read, &DEBUG_UART)) {
                        readData[len] = read;
                        len++;
                    }
                    if (val != -1) {
                        if (commands[val] == 0) {
                            LOG_WARNING("Command %c is not assigned", command);
                        } else {
                            LOG_SYSTEM("Received command: %c", command);
                            commands[val](len - 1, (char*)readData); //we remove the \n
                        }
                    } else {
                        while (uart_reads_buffer(&read, &DEBUG_UART));  //flush the buffer
                    }
                }
                //if its our uart
            }
            uart_delimiter_handled(delimiter);
        }
    } else if (event == &EVENT_TERMINAL_SPECIAL) {
        LOG_DEBUG("Special key %d", data);
    }
}
static uint8_t init(void) {
    event_addListener(&EVENT_TERMINAL_SPECIAL, callback);
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