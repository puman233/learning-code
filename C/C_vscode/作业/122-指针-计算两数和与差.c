//
// Created by ihyj on 2025/12/3.
//

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void sum_diff(float op1, float op2, float *psum, float *pdiff) {

    *psum = op1 + op2;
    *pdiff = fabs((double)(op1 - op2));

}

int main(int argc, char *argv[]) {

    float n1, n2, psum = 0, pdiff = 0;

    scanf("%f %f", &n1, &n2);

    sum_diff(n1, n2, &psum, &pdiff);

    printf("sum=%.2f\n", psum);
    printf("diff=%.2f\n", pdiff);

    return 0;
}



