#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int x;

    scanf("%d", &x);

    if (x < 2) {
        printf("%d\n", 2 * x + 5);
    }
    else if (x >= 2 && x <= 5) {
        printf("%d\n", x * x * x);
    } else {
        printf("%d\n", -1 * x + 7);
    }




    return 0;
}
