//
// Created by ihyj on 2025/11/17.
//

#include <stdio.h>

long int fac(int n);
long int sum(int x, int y);

int main(void) {
    long int fac(int n);
    // long int sum(int x, int y);
    int a, b;
    long int c;

    printf("please input a and b: ");
    scanf("%d,%d", &a, &b);
    c = sum(a, b);
    printf("sum=%ld\n", c);
    return 0;
}


long int sum(int x, int y) {
    long int z1, z2;

    z1 = fac(x);
    z2 = fac(y);
    return (z1 + z2);
}

long int fac(int n)
{
    long r = 1;
    int i;
    for (i = 1; i <= n; i++)
        r *= i;
    return r;
}