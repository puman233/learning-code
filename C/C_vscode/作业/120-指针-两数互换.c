//
// Created by ihyj on 2025/12/3.
//

#include <stdio.h>

int main(int argc, char *argv[]) {

    int n1, n2;
    int *p1 = &n1, *p2 = &n2;

    printf("Please enter a,b: ");
    scanf("%d,%d", &n1, &n2);

    printf("Before swap: ");
    printf("%d,%d\n", *p1, *p2);

    int t = *p1;
    *p1 = *p2;
    *p2 = t;

    printf("After swap: ");
    printf("%d,%d\n", *p1, *p2);

    return 0;
}


