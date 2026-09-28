#include <stdio.h>

int main(int argc, char *argv[]) {

    int n, i, sum = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum += i;
    }
    printf("sum=%d\n", sum);



    return 0;
}