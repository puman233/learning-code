//
// Created by ihyj on 2025/11/17.
//

#include <stdio.h>

int max_value (int array[][4]) {
    int i,j, max = array[0][0];
    for(i=0; i<3; i++) {
        for(j=0; j<4; j++) {
            if(array[i][j] > max) {
                max = array[i][j];
            }
        }
    }
    return max;
}
//
// int main(void)
// {
//     int a[3][4], i, j ;
//     for( i=0; i<3; i++ )
//         for( j=0; j<4; j++)
//             scanf("%d", &a[i][j]);
//     printf("max value is %d\n", max_value(a) );
//     return 0;
// }

