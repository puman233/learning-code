////
//// Created by ihyj on 2025/12/2.
////
//
//#include <stdio.h>
//
//int main(int argc, char *argv[]) {
//
//    int a[3][4] = {
//        {1,3,5,7},
//        {9,11,13,15},
//        {17,19,21,23}
//    };
//    int (*p)[4], i, j;
//
//    p =  a;
//
//    for (i = 0; i < 3; i++, p++) {
//        for (j = 0; j < 4; j++) {
//            // printf("%d ", p[i][j]);
//            printf("%4d", *(*p + j));
//        }
//        printf("\n");
//    }
//
//    return 0;
//}
//
//
//
