#include <stdio.h>

int main(int argc, char *argv[]) {

    int num[10];

    int i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &num[i]);
    }

    int max = num[0], min = num[0];

    for (i = 0; i < 10; i++) {
        if (num[i] > max) max = num[i];
        if (num[i] < min) min = num[i];
    }

    printf("Max=%d\n", max);
    printf("Min=%d\n", min);


    return 0;
}