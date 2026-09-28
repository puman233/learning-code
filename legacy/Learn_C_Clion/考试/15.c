#include <stdio.h>

int main(int argc, char *argv[]) {

    int n, i, j, isNum = 0;

    scanf("%d",&n);

    for (i = 2; i <= n; i++) {
        isNum = 1;
        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isNum = 0;
                break;
            }
        }
        if (isNum) {
            printf("%5d", i);
        }
    }
    printf("\n");



    return 0;
}