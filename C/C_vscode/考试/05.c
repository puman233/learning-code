#include <stdio.h>

int main(int argc, char *argv[]) {

    int num, i, mask = 10000;

    scanf("%d", &num);

    for (i = 1; i <= 5; i++) {
        int t = num / mask;
        printf("%d   ", t);

        num %= mask;
        mask /= 10;

    }




    return 0;
}