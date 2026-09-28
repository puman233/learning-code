////
//// Created by ihyj on 2025/11/19.
////
//
//#include<stdio.h>
//
//int sort(int arr[], int n) {
//    int i, j;
//    for (i = 0; i < n; i++) {
//        for (j = i + 1; j < n; j++) {
//            if (arr[i] > arr[j]) {
//                int temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//    return 0;
//}
//
//
//int main(int argc, char *argv[]) {
//    int n, arr[100];
//
//    printf("Please input n: ");
//
//    scanf("%d", &n);
//
//    int i;
//    for (i = 0; i < n; i++) {
//        scanf("%d", &arr[i]);
//    }
//
//    sort(arr, n);
//
//    for (i = 0; i < n; i++) {
//        printf("%4d", arr[i]);
//    }
//
//    return 0;
//}
//
//
