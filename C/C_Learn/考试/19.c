//#include <stdio.h>
//
//void seq(int num[], int nSize) {
//    int i,j;
//
//    for (i = 0; i < nSize - 1; i++) {
//        for (j = i + 1; j < nSize; j++) {
//            if (num[i] > num[j]) {
//                int t = num[i];
//                num[i] = num[j];
//                num[j] = t;
//            }
//        }
//    }
//
//}
//
//int main(int argc, char *argv[]) {
//
//    int n;
//
//    scanf("%d",&n);
//
//    int num[n];
//
//    for (int i = 0; i < n; i++) {
//        scanf("%d",&num[i]);
//    }
//
//    seq(num, n);
//
//    for (int i = 0; i < n; i++) {
//        printf("%4d", num[i]);
//    }
//
//
//
//
//    return 0;
//}