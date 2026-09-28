//#include <stdio.h>
//
//int sum(int a[10][10], int m, int n) {
//
//    int i, j, sum = 0;
//    for (i = 0; i < m; i++) {
//        for (j = 0; j < n; j++) {
//            sum += a[i][j];
//        }
//    }
//    return sum;
//}
//
//
//int main(int argc, char *argv[]) {
//
//    int a[10][10];
//    int i, j, m, n, s;
//    scanf( "%d,%d", &m, &n );
//    for( i = 0; i < m; i++ )
//    {
//        for( j = 0; j < n; j++ )
//        {
//            scanf( "%d", &a[i][j] );
//        }
//    }
//    s = sum( a, m, n );
//    printf( "sum=%d\n", s );
//
//
//    return 0;
//}