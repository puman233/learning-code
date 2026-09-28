////
//// Created by ihyj on 2025/12/3.
////
//
//#include<stdio.h>
//
//void swap(int a[]) {
//    int i, max = a[0], maxi = 0, min = a[0], mini = 0;
//
//    for (i = 0; i < 10; i++) {
//        if (a[i] > max) {
//            max = a[i];
//            maxi = i;
//        };
//        if (a[i] < min) {
//            min = a[i];
//            mini = i;
//        };
//    }
//
//    int temp = a[maxi];
//    a[maxi] = a[9];
//    a[9] = temp;
//
//    int temp2 = a[mini];
//    a[mini] = a[0];
//    a[0] = temp2;
//}
//
//int main(int argc, char *argv[]) {
//
//    int a[10];
//    for (int i = 0; i < 10; i++) {
//        scanf("%d", &a[i]);
//    }
//
//    swap(a);
//
//    for (int i = 0; i < 10; i++) {
//        printf("%d ", a[i]);
//    }
//
//    return 0;
//}
//
//
//
