/*
 * weather.c
 *
 * Created: 3/1/2017 1:02:21 AM
 *  Author: elmar
 */
#include "../modules/screen.h"
#include "core.h"
#include "weather.h"
#include "../sprites.h"
#include "app.h"
#include <avr/pgmspace.h>

EVENT_REGISTER(WEATHER_CHANGE, "Change of weather");

static void move(uint16_t x, uint16_t y) {
}

APP_CREATE("Weather", move);

#define ICON_WIDTH          32
#define ICON_HEIGHT         32

#define ICON_AMOUNT         6
#define ICON_SUN_INDEX      0
#define ICON_CLOUD_INDEX    1
#define ICON_OVERCAST_INDEX 2
#define ICON_SNOW_INDEX     3
#define ICON_RAIN_INDEX     4
#define ICON_THUNDER_INDEX  5

static Weather curWeather;

static uint8_t getIndex(WeatherType type) {
    if (type == WeatherType_WEATHER_THUNDER) return ICON_THUNDER_INDEX;
    if (type == WeatherType_WEATHER_SNOW) return ICON_SNOW_INDEX;
    if (type == WeatherType_WEATHER_RAIN) return ICON_RAIN_INDEX;
    if (type == WeatherType_WEATHER_CLOUDY) return ICON_CLOUD_INDEX;
    if (type == WeatherType_WEATHER_OVERCAST) return ICON_OVERCAST_INDEX;
    if (type == WeatherType_WEATHER_SUN) return ICON_SUN_INDEX;
    return 0;
}

static char text[4][4];

void weather_set(Weather weather) {
    curWeather = weather;
    sprintf(text[0], "%d%c", weather.temperature, weather.unit[0]);
    if(weather.city.size > 4) {
        memcpy(&text[1], &weather.city.bytes[0], 4);
        memcpy(&text[2], &weather.city.bytes[4], weather.city.size - 4);
    } else {
        memcpy(&text[1], &weather.city.bytes[0], weather.city.size);
    }
    //TODO event
    weather_draw();
}

Weather weather_get(void) {
    return curWeather;
}


void weather_draw(void) {
    if (!APP_ISENABLED) return;
    screen_sub_image(&sprite_weather, xx, yy, ICON_WIDTH * getIndex(curWeather.weatherType), 0, ICON_WIDTH, ICON_HEIGHT);
    screen_text(text[0], 4, xx + 32 + 1, yy + 1);
    screen_text(text[1], 4, xx + 32 + 1, yy + 8 + 2 + 1);
    screen_text(text[2], 4, xx + 32 + 1, yy + 8 + 8 + 4 + 1);
#ifdef BOUNDARY_BOX
    screen_draw_begin(LINE);
    screen_color(COLOR_TO656(30, 240, 30));
    screen_rect(APP_BOUNDS - 1);
    screen_rect(APP_BOUNDS - 1);
    screen_draw_end();
#endif
}

const char * city = "Amsterdam";

void weather_init(uint16_t drawX, uint16_t drawY) {
    APP_SET_POS(drawX, drawY);
    APP_SET_BOUNDS(WEATHER_APP_WIDTH, WEATHER_APP_HEIGHT);
    APP_ENABLE(true);
    curWeather.temperature = 12;
    curWeather.city.size = 8;//sizeof(&city);
    memcpy(curWeather.city.bytes, city, 8);
    curWeather.unit[0] = 'K';
    curWeather.weatherType = WeatherType_WEATHER_SUN;
    weather_set(curWeather);
}

void weather_deinit(void) {
    APP_ENABLE(false);
}