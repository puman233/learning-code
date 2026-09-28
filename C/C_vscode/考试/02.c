#include <stdio.h>

int main(int argc, char *argv[]) {

    float temp;

    scanf("%f", &temp);

    float f = 0;

    f = 9 / 5.0 * temp + 32;

    printf("%.1f\n", f);


    return 0;
}