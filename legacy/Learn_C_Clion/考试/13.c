#include <stdio.h>

int main(int argc, char *argv[]) {

    int m, n;

    scanf("%d %d", &m, &n);

    if (m % n == 0) {
        printf("%d\n", m / n);
    }
    else {
        printf("%d\n", m % n);
    }







    return 0;
}