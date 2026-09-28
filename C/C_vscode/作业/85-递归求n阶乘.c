//
// Created by ihyj on 2025/11/17.
//

#include <stdio.h>

long int fac(int number) {
    if (number == 1) {
        return 1;
    } else {
        return number * fac(number - 1);
    }
}
//
// int main(void) {
//     int n;
//     long int y;
//     printf("Input a integer number:");
//     scanf("%d", &n);
//     if (n >= 0) {
//         y = fac(n);
//         printf("%d!=%ld", n, y);
//     } else
//         printf("data error!");
//     return 0;
// }
