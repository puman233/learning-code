//#include <stdio.h>
//
//int main(int argc, char *argv[]) {
//
//    int n, i, j;
//
//    scanf("%d",&n);
//
//    int triangle[n][n];
//
//    triangle[0][0] = 1;
//    triangle[1][0] = 1;
//    triangle[1][1] = 1;
//    for (i = 2; i < n; i++) {
//        triangle[i][0] = 1;
//        triangle[i][i] = 1;
//        for (j = 1; j < i; j++) {
//            triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
//        }
//    }
//
//    for (i = 0; i < n; i++) {
//        for (j = 0; j <= i; j++) {
//            printf("%5d", triangle[i][j]);
//        }
//        printf("\n");
//    }
//
//
//
//
//    return 0;
//}