#include <stdio.h>

struct calculateDay {
    int year;
    int month;
    int day;
    int res;
};

int isLeap(int year) {
    int res = 0;    // 默认非闰年

    if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) res = 1;

    return res;
}

int monthDay(int month) {
    int res;

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            res = 31;
            break;
        case 2:
            res = 28;
            break;
        default:
            res = 30;
            break;
    }
    return res;
}


int main(int argc, char *argv[]) {

    struct calculateDay calculate_day;

    calculate_day.res = 0;

    printf("Input year,month,day: ");
    scanf("%d,%d,%d", &calculate_day.year, &calculate_day.month, &calculate_day.day);

    for (int i = 1; i < calculate_day.month; i++) {
        calculate_day.res += monthDay(i);
        if (isLeap(calculate_day.year) && i == 2) {
            calculate_day.res += 1;
        }
    }
    calculate_day.res += calculate_day.day;

    printf("%d/%d is the %dth day in %d.\n", calculate_day.month, calculate_day.day, calculate_day.res, calculate_day.year);

    return 0;
}