//#include <stdio.h>
//#include <stdlib.h>
//
//int fun(int n) {
//
//    int tn = 0, res = 0, i, count = 0;
//
//    tn = abs(n);
//
//    while (tn > 0) {
//        tn /= 10;
//        count++;
//    }
//
//    tn = abs(n);
//
//    for (i = 0; i < count; i++) {
//        res *= 10;
//        res += tn % 10;
//        tn /= 10;
//    }
//
//    if (n < 0) {
//        return -res;
//    }
//    return res;
//
//}
//
//
//int main(int argc, char *argv[]) {
//
//    int n;
//    printf("Input n: ");
//    scanf("%d", &n);
//    printf("%d's reverse is: %d\n", n, fun(n));
//
//
//    return 0;
//}