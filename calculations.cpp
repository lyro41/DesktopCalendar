#include "calculations.h"


bool LeapCheck(int64_t year) {
    return (year % 4 == 0 && year % 100) || (year % 400 == 0);
}

int64_t DaysInYear(int64_t year) {
    return 365 + LeapCheck(year);
}

int64_t DaysInMonth(int64_t month, int64_t year) {
    switch(month) {
        case 2:
            return 28 + LeapCheck(year);
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        default:
            return 30;
    }
}

int64_t DaysAfterNewYear(int64_t day, int64_t month, int64_t year) {
    int64_t res = day - 1;
    for (int i = 1; i < month; ++i) {
        res += DaysInMonth(i, year);
    }
    return res;
}

int64_t DaysAfterChristmas(int64_t day, int64_t month, int64_t year) {
    int64_t res = DaysAfterNewYear(day, month, year);
    --year;
    res += 365 * year - year / 100 + year / 4 + year / 400;
    return res;
}

int64_t DatesDifference(int64_t day_fst, int64_t month_fst, int64_t year_fst,
                        int64_t day_snd, int64_t month_snd, int64_t year_snd) {
    return std::abs(DaysAfterChristmas(day_fst, month_fst, year_fst) -
                    DaysAfterChristmas(day_snd, month_snd, year_snd));
}

int64_t WeekDay(int64_t day, int64_t month, int64_t year, int64_t week_day,
                int64_t day_now, int64_t month_now, int64_t year_now) {
    int64_t res;
    int64_t q = DaysAfterChristmas(day, month, year);
    int64_t q_now = DaysAfterChristmas(day_now, month_now, year_now);
    if (q_now <= q) {
        res = week_day - DatesDifference(day, month, year,
                                         day_now, month_now, year_now) % 7;
        if (res <= 0) res += 7;
    } else {
        res = (week_day + DatesDifference(day, month, year,
                                         day_now, month_now, year_now)) % 7;
        if (res == 0) res = 7;
    }
    return res;
}
