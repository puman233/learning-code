////
//// Created by ihyj on 2025/11/17.
////
//
//#include <stdio.h>
//
//void sort (int array[], int n) {
//    int i, j;
//    for( i=0; i<n; i++ ) {
//        for( j=0; j<n; j++ ) {
//            if( array[i] < array[j] ) {
//                int temp = array[i];
//                array[i] = array[j];
//                array[j] = temp;
//            }
//        }
//    }
//}
//
//// int  main(void)
//// {
////     int  a[50], i, n;
////     scanf( "%d", &n );
////     for( i=0; i<n; i++ )
////         scanf( "%d", &a[i] );
////     sort( a, n );
////     for( i=0; i<n; i++ )
////         printf( "%5d", a[i] );
////     return 0;
//// }