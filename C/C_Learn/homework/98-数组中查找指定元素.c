////
//// Created by ihyj on 2025/11/20.
////
//
//#include <stdio.h>
//
//int search(int arr[], int n, int x) {
//    int i;
//    for (i = 0; i < n; i++) {
//        if (arr[i] == x) {
//            return i;
//        }
//    }
//
//    return -1;
//}
//
//
//
//int main(int argc, char *argv[]) {
//
//    int n, arr[10], i, x;
//    printf("Input n:");
//    scanf("%d", &n);
//
//    printf("Input %d integers:", n);
//    for (i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    printf("Input x:");
//    scanf("%d", &x);
//
//    int is = search(arr, n, x);
//    if (is == -1) {
//        printf("Not found");
//    }
//    else {
//        printf("index = %d", is);
//    }
//
//    return 0;
//}
//
//
//
