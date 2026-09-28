////
//// Created by ihyj on 2025/12/3.
////
//
//#include <stdio.h>
//
//int find(int *x, int a[]) {
//    // int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 99};
//
//    int i;
//    // int find_i = 0, *p = a;
//    // for (i = 0; i < 10; i++) {
//    //     if (*x < *p) {
//    //         find_i = 0;
//    //         break;
//    //     }
//    //     else if ((i + 1) < 10 && *x > *(p + i) && *x < *(p + i + 1)) {
//    //         find_i = i;
//    //         break;
//    //     }
//    //     else if (*x > *(p + 9)) {
//    //         find_i = 9;
//    //         break;
//    //     }
//    // }
//    //
//    // return find_i;
//
//    for (i = 0; i < 10; i++) {
//        if (*x < *(a + i)) {
//            return i;
//        }
//    }
//
//    return 10;
//}
//
//void insert(int *find_i, int a[], int *x, int pres[]) {
//    int i;
//    // int temp[10];
//    // for (i = 0; i < 10; i++) {
//    //     temp[i] = a[i];
//    // }
//    // int *pt = temp;
//    // for (i = 0; i < 11; i++) {
//    //     if (i < *find_i) {
//    //         *(pres + i) = *(pt + i);
//    //     }
//    //     else if (i == *find_i) {
//    //         *(pres + i) = *x;
//    //     }
//    //     else if (i > *find_i) {
//    //         *(pres + i) = *(pt + i - 1);
//    //     }
//    // }
//
//    // 1. 把插入点之前的数据拷到 res
//    for (i = 0; i < *find_i; i++) {
//        *(pres + i) = *(a + i);
//    }
//
//    // 2. 插入 x
//    *(pres + *find_i) = *x;
//
//    // 3. 把后面的数据拷进 res
//    for (i = *find_i; i < 10; i++) {
//        *(pres + i + 1) = *(a + i);
//    }
//}
//
//
//int main(int argc, char *argv[]) {
//    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 99};
//    int x;
//    int res[11];
//
//    printf("Please input new element: ");
//    scanf("%d", &x);
//
//    int find_i = find(&x, a);
//
//    insert(&find_i, a, &x, res);
//
//    printf("Result: ");
//    for (int i = 0; i < 11; i++) {
//        printf("%d ", res[i]);
//    }
//
//    return 0;
//}
//
//
