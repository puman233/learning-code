//
// Created by ihyj on 2025/11/17.
//

#include <stdio.h>

float average(float array[10]) {
    float ave = 0.0, sum = 0.0;
    int i;
    for (i = 0; i < 10; i++) {
        sum = sum + array[i];
    }
    ave = sum / 10.0;
    return ave;
}
//
// int main(void)
// {
//     float score[10], ave;
//     int  i;
//     for( i=0; i<10; i++ )
//         scanf("%f", &score[i]);
//     ave=average(score);
//     printf("Average=%.2f\n", ave);
// }