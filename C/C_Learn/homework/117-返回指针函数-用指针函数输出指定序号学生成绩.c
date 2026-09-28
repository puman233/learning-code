//
//#include <stdio.h>
//
//int main(int argc, char *argv[]) {
//    float score[][4] = {
//        {60, 70, 80, 90},
//        {56,89,67,88},
//        {34,78,90,66},
//    };
//
//    float *search(float (*pointer)[4], int n);
//
//    float *p;
//    int i,k;
//
//    printf("Enter the number of student:");
//    scanf("%d",&k);
//    printf("The scores of No.%d are:", k);
//
//    p = search(score, k);
//
//    for (i = 0; i < 4; i++) {
//        printf("%6.2f", *(p + i));
//    }
//
//
//    return 0;
//}
//
//float *search(float (*pointer)[4], int n) {
//    float *pt;
//    pt = *(pointer + n);
//    return pt;
//}
//
//
