/*
 * uart.c
 *
 * Created: 11/9/2016 12:37:41 AM
 *  Author: elmar
 */ 

 #include "uart.h"

EVENT_REGISTER(EVENT_UART_JOB,		"Completed UART job");
EVENT_REGISTER(EVENT_UART_DELIMITER,"Got UART delimiter");

#define UART_MAX_DELIMITERS		3
#define UART_MAX_IN_BUFFER		64
#define UART_MAX_JOBS			4

struct UartJob{
	char * data;
	uint8_t len;
	void (* callback)(void);
};

struct UartDelimiter{
	char delimiter;
	uint8_t readDelimiter;
	uint8_t tempReadDelimiter;
};

struct UartJob jobs				[UART_MAX_JOBS];
uint8_t jobs_head				= 0;
uint8_t jobs_tail				= 0;

struct UartDelimiter delimiters [UART_MAX_DELIMITERS];
uint8_t delimiters_head			= 0;
uint8_t delimiters_tail			= 0;

char inBuffer					[UART_MAX_IN_BUFFER];
uint8_t inBuffer_head			= 0;
uint8_t inBuffer_tail			= 0;

static uint8_t sending			= 0;

static void _send(){
	sending = 1;
	// enable everything
}

void uart_init(UART_BAUDRATE baudrate){
	/*Set baud rate*/
	UBRR0H |= (uint8_t)(MYUBRR>>8);
	UBRR0L |= (uint8_t)(MYUBRR);
	/*Enable receiver and transmitter*/
	UCSR0B |= (1<<RXEN0) | (1<<TXEN0);
	/*Frame format: 8 data bit, 1 stop bit*/
	UCSR0C |= (1<<USBS0) | (1<<UCSZ00) | (1<<UCSZ01);
}

uint8_t uart_job(char * data, uint8_t len, void (* callback)(void)){
	uint8_t newHead = (jobs_head+1>UART_MAX_JOBS)?0:jobs_head+1;
	if(newHead == jobs_tail){
		return 0;
	}
	struct UartJob * curJob = &jobs[jobs_head];
	curJob->callback = callback;
	curJob->data = data;
	curJob->len = len;
	jobs_head = newHead;
	if(!sending)
		_send();
	return 1;
}

uint8_t uart_buffer_level(void){
	if(inBuffer_head<inBuffer_tail){
		return UART_MAX_IN_BUFFER;
	}
}

void uart_write_blocked(char * data, uint8_t len){
	uint8_t i = 0;
	while(i<len){
		/*Data buffer must be empty*/
		while(!(UCSR0A & (1<<UDRE0)));
		/*Write character by character*/
		UDR0 = data[i];
		i++;
	}
}

uint8_t uart_read_blocked(char * data, uint8_t len){
	uint8_t next_char;
	uint8_t readLen=0;
	/*Clue character to character*/
	while(readLen < len) {
		while(!(UCSR0A & (1<<RXC0)));
		data[readLen] = UDR0;
		readLen++;
	}
	return readLen;
}

uint8_t uart_add_delimiter(char delimiter, void(*callback)(char *, uint8_t)){
	uint8_t newHead = (delimiters_head+1>UART_MAX_JOBS)?0:delimiters_head+1;
	if(newHead == delimiters_tail){
		return 0;
	}
	struct UartDelimiter * curDelimiter = &delimiters[delimiters_head];
	curDelimiter->delimiter = delimiter;
	curDelimiter->readDelimiter = 0;
	delimiters_head = newHead;
	return 1;
}