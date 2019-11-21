#pragma once

#include <stdint.h>
#include <algorithm>

bool LeapCheck(int64_t year);

int64_t DaysInYear(int64_t year);

int64_t DaysInMonth(int64_t month, int64_t year);

int64_t DaysAfterNewYear(int64_t day, int64_t month, int64_t year);

int64_t DaysAfterChristmas(int64_t day, int64_t month, int64_t year);

int64_t DatesDifference(int64_t day_fst, int64_t month_fst, int64_t year_fst,
                        int64_t day_snd, int64_t month_snd, int64_t year_snd);

int64_t WeekDay(int64_t day, int64_t month, int64_t year, int64_t week_day,
                int64_t day_now, int64_t month_now, int64_t year_now);
