////
//// Created by ihyj on 2025/11/19.
////
//
//#include <stdio.h>
//
//int f(int n) {
//
//    if (n < 1) {
//        return 0;
//    }
//    else if (n == 1 || n == 2) {
//        return 1;
//    }
//    else if (n == 3) {
//        return 2;
//    }
//    else if (n > 3) {
//        return f(n-1) + f(n-2);
//    }
//    return 0;
//}
//
//int main(int argc, char *argv[]) {
//    int n;
//    scanf("%d", &n);
//
//    int i;
//    for (i = 1; i <= n; i++) {
//        printf("%12d", f(i));
//        if (i % 5 == 0) {
//            printf("\n");
//        }
//    }
//
//
//    return 0;
//}
//
