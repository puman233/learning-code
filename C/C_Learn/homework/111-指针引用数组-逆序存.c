////
//// Created by ihyj on 2025/12/2.
////
//
//#include <stdio.h>
//
//void inv(int *x, int n) {
//    int t, *p, *i, *j, m = (n - 1)/ 2;
//    p = x+m;
//    i = x;
//    j = x +n-1;
//    for (;i <= p;i ++, j--) {
//        t = *i;
//        *i = *j;
//        *j = t;
//    }
//
//}
//
//int main(int argc, char *argv[]) {
//    int i, a[10], *p;
//    for (i = 0; i < 10; i++) {
//        scanf("%d", &a[i]);
//    }
//    p = &a[0];
//    inv(p, 10);
//    for (i = 0; i < 10; i++) {
//        printf("%d ", a[i]);
//    }
//    printf("\n");
//
//    return 0;
//}
//
//
