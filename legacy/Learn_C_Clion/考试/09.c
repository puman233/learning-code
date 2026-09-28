#include <stdio.h>

int main(int argc, char *argv[]) {

    int i, j, a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if (a < b) {
        int t = a;
        a = b;
        b = t;
    }
    if (a < c) {
        int t = c;
        c = a;
        a = t;
    }
    if (b < c) {
        int t = c;
        c = b;
        b = t;
    }

    printf("%d %d %d\n", a, b, c);



    return 0;
}