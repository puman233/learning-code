//
// Created by ihyj on 2025/11/19.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int fun(int n) {
    int sign = -1;
    if (n <= 0) {
        n = n * (-1);
        sign = 1;
    }
    int sum = 0, temp = n, mask = 1;
    while (temp > 9) {
        temp /= 10;
        mask++;
    }
    temp = n;
    while (mask > 0) {
        temp = (n % 10);
        n /= 10;
        sum = sum * 10 + temp;
        mask--;
    }
    if (sign == 1) {
        return sum * (-1);
    }
    else {
        return sum;
    }

}

int main(int argc, char *argv[]) {

    int m1, m2;
    printf("Input m1: ");
    scanf("%d", &m1);
    printf("Input m2: ");
    scanf("%d", &m2);


    printf("%d's reverse is: %d\n", m1, fun(m1));
    printf("%d's reverse is: %d\n", m2, fun(m2));

    return 0;
}



