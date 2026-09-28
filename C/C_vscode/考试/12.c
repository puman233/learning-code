#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    float x;

    scanf("%f", &x);

    if (x >= -10 && x <= 4) {
        printf("y=%.2f\n", fabs((double)x - 2));
    }
    else if (x >= 5 && x <= 7) {
        printf("y=%.2f\n", 2.0 * x + 10);
    }
    else if (x >= 8 && x <= 12) {
        printf("y=%.2f\n", powf(x, 4.0));
    }
    else {
        printf("No answer.\n");
    }


    return 0;
}