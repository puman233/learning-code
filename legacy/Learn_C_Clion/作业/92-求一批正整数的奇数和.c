//
// Created by ihyj on 2025/11/19.
//

#include <stdio.h>

int even(int n) {

    if (n % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }

    // return 0;
}

int main(int argc, char *argv[]) {
    int n[30], i, odd_sum = 0, count = 0;

    printf("Input integers: ");

    for (i =0; i < 30; i++) {
        int t;
        scanf("%d", &t);
        if (t <= 0) {
            break;
        }
        else {
            n[i] = t;
            count++;
        }
    }
    for (i = 0; i < count; i++) {
        int is = even(n[i]);
        if (is == 0) {
            odd_sum += n[i];
        }
    }

    printf("The sum of the odd numbers is %d", odd_sum);

    return 0;
}


