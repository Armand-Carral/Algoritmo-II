#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include <stdio.h>

int lower_minimum_temperature (WeatherTable a);

void max_temp_year (WeatherTable a, int output[YEARS]);

void max_rainfall_month_year (WeatherTable a, t_month output[YEARS]);

void string_month_dump (t_month output2[YEARS]);

#endif