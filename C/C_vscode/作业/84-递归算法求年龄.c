//
// Created by ihyj on 2025/11/17.
//

#include<stdio.h>

int age(int n) {
    // int r;

    if (n == 1) {
        return 10;
    } else {
        return age(n - 1) + 2;
    }
}

// int main(void) {
//     int n;
//     scanf("%d", &n);
//     printf("%d\n", age(n));
//     return 0;
// }
