#include <stdio.h>

int isMonth(int month) {
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 2:
            return 28;
        default:
            return 30;
    }
}

int isYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    int year, month;

    scanf("%d %d", &year, &month);

    if (month == 2) {
        printf("%d\n", isMonth(month) + isYear(year));
    }
    else {
        printf("%d\n", isMonth(month));
    }


    return 0;
}