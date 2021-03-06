/*
 * clock_2.c
 *
 * Created: 5/13/2017 10:47:28 AM
 *  Author: elmar
 */

#include "../modules/timekeeper.h"
#include "../modules/screen.h"
#include "../sprites.h"
#include "clock.h"
#include "app.h"

static uint16_t bckgrColor = COLOR_TO656(0, 0, 0);

static void move(uint16_t x, uint16_t y) {
}

APP_CREATE("Clock", move);

#define CLOCK_DISPLAY_LARGE         (1<<0)
#define CLOCK_DISPLAY_SMALL         (1<<1)
#define CLOCK_DISPLAY_ALARM         (1<<2)
#define CLOCK_DISPLAY_DATE          (1<<3)
#define CLOCK_DISPLAY_NOTHING       (0x00)
#define CLOCK_DISPLAY_ALL           (CLOCK_DISPLAY_LARGE | CLOCK_DISPLAY_SMALL | CLOCK_DISPLAY_ALARM | CLOCK_DISPLAY_DATE)

static uint8_t displayWhat =    CLOCK_DISPLAY_NOTHING;

void clock_draw(uint8_t update, uint8_t display) {
    if(!APP_ISENABLED) return;
    //hour : min : sec + \0
    //day/month/year + \0
    char clockbuf[11];
    if (update & TIMEKEEPER_UPDATE_TIME) {
        struct timekeepertime_s displayTime = timekeeper_time_get();
        if (display & CLOCK_DISPLAY_SMALL && (update & TIMEKEEPER_UPDATE_HOUR_BP || update & TIMEKEEPER_UPDATE_MIN_BP || update & TIMEKEEPER_UPDATE_SEC_BP)) {
            clockbuf[0] = displayTime.hour / 10 + '0';
            clockbuf[1] = displayTime.hour % 10 + '0';
            clockbuf[2] = ':';
            clockbuf[3] = displayTime.minute / 10 + '0';
            clockbuf[4] = displayTime.minute % 10 + '0';
            clockbuf[5] = ':';
            clockbuf[6] = displayTime.second / 10 + '0';
            clockbuf[7] = displayTime.second % 10 + '0';
            screen_color(COLOR_TO656(255, 255, 255));
            screen_text(clockbuf, 8, 158 - 8 * CLOCK_SMALL_FONT_SIZE, yy + CLOCK_DIGITAL_HEIGHT + 2);
        }
        if (display & CLOCK_DISPLAY_LARGE && (update & TIMEKEEPER_UPDATE_HOUR_BP || update & TIMEKEEPER_UPDATE_MIN_BP)) {
            screen_draw_begin(FILLED);
            screen_color(bckgrColor);
            if (update & TIMEKEEPER_UPDATE_HOUR_BP) {
                screen_rect(xx, yy + 1, 24, 60);
                screen_sub_image(&sprite_numbers, xx, yy + 1, (displayTime.hour / 10) * 24, 0, 24, 60);
                screen_rect(xx + 24 * 1, yy + 1, 24, 60);
                screen_sub_image(&sprite_numbers, xx + 24, yy + 1, (displayTime.hour % 10) * 24, 0, 24, 60);
            }
            if (update & TIMEKEEPER_UPDATE_MIN_BP) {
                screen_rect(xx + 24 * 2, yy + 1, 24, 60);
                screen_sub_image(&sprite_numbers, xx + 48, yy + 1, (displayTime.minute / 10) * 24, 0, 24, 60);
                screen_rect(xx + 24 * 3, yy + 1, 24, 60);
                screen_sub_image(&sprite_numbers, xx + 72, yy + 1, (displayTime.minute % 10) * 24, 0, 24, 60);
            }
            screen_draw_end();
        }
    }
    if (display & CLOCK_DISPLAY_ALARM && update & TIMEKEEPER_UPDATE_ALARM_BP) {
        struct timekeeperalarm_s alarm = timekeeper_alarm_get();
        clockbuf[0] = alarm.time.hour / 10 + '0';
        clockbuf[1] = alarm.time.hour % 10 + '0';
        clockbuf[2] = ':';
        clockbuf[3] = alarm.time.minute / 10 + '0';
        clockbuf[4] = alarm.time.minute % 10 + '0';
        clockbuf[5] = ':';
        clockbuf[6] = alarm.time.second / 10 + '0';
        clockbuf[7] = alarm.time.second % 10 + '0';
        screen_color(COLOR_TO656(200, 80, 120));
        screen_text(clockbuf, 8, 158 - 8 * CLOCK_SMALL_FONT_SIZE, yy + CLOCK_DIGITAL_HEIGHT + CLOCK_SMALL_LINE_SPACING + 1 + CLOCK_SMALL_FONT_SIZE);
        screen_color(COLOR_TO656(255, 255, 255));
    }
    if (update & TIMEKEEPER_UPDATE_DATE) {
        struct timekeeperdate_s data = timekeeper_date_get();
        //2000/01/01
        snprintf(clockbuf, 11, "20%02d/%02d/%02d", data.year, data.month, data.day);
        screen_color(COLOR_TO656(70, 30, 150));
        screen_text(clockbuf, 10, 158 - 10 * CLOCK_SMALL_FONT_SIZE, yy + CLOCK_DIGITAL_HEIGHT + (CLOCK_SMALL_LINE_SPACING * 2) + CLOCK_SMALL_FONT_SIZE * 2);
        screen_color(COLOR_TO656(255, 255, 255));
    }
#ifdef BOUNDARY_BOX
    screen_draw_begin(LINE);
    screen_color(COLOR_TO656(30, 240, 30));
    screen_rect(xx, yy, CLOCK_DIGITAL_WIDTH - 2, CLOCK_DIGITAL_HEIGHT );
    screen_rect(xx, yy + CLOCK_DIGITAL_HEIGHT, CLOCK_DIGITAL_WIDTH - 2, CLOCK_SMALL_HEIGHT - 1);
    screen_draw_end();
#endif
}
static void callback(Event * event, uint8_t * data) {
    if (event == &TIME_CHANGE && APP_ISENABLED) {
        clock_draw((uint8_t)data, displayWhat);
    }
}

void clock_init(uint16_t drawX, uint16_t drawY) {
    APP_SET_POS(drawX, drawY);
    APP_SET_BOUNDS(CLOCK_DIGITAL_WIDTH, CLOCK_DIGITAL_HEIGHT + CLOCK_SMALL_HEIGHT);
    APP_ENABLE(true);
    displayWhat = CLOCK_DISPLAY_ALL;
    event_addListener(&TIME_CHANGE, callback);
    clock_draw(TIMEKEEPER_UPDATE_TIME, displayWhat);
}
void clock_deinit(void) {
    APP_ENABLE(false);
    event_removeListener(&TIME_CHANGE, callback);
    displayWhat = CLOCK_DISPLAY_NOTHING;
}