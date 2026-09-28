//
// Created by ihyj on 2025/11/17.
//

#include <stdio.h>

float max(float x, float y);
int main(void) {
    float a, b, c;

    scanf("%f,%f", &a, &b);
    c = max(a, b);
    printf("the result is:%6.2f\n", c);
    return 0;
}

float max(float x, float y) {
    float z;
    if (x > y)
        z = x;
    else
        z = y;
    return z;
}
