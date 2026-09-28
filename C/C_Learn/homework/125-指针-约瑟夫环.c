//
//#include <stdio.h>
//#include <stdlib.h>
//
//void circle(int a[], int n) {
//    int i = 0;
//    int count = 1;
//    int exit = n;
//
//    while ( 1 ) {
//
//        if (exit == 0) {
//            break;
//        }
//        i++;
//        if (i >= n) {
//            i = 0;
//        }
//
//        if (*(a + i) > 0) {
//            count++;
//            if (count == 3) {
//                printf("%d ", *(a + i));
//                *(a + i) = 0;
//                count = 0;
//                exit--;
//            }
//        }
//        else if (*(a + i) < 1) {
//            continue;
//        }
//
//    }
//}
//
//int main(int argc, char *argv[]) {
//
//    // n 个人
//    int n;
//
//    printf("Input number of person: n= ");
//    scanf("%d", &n);
//
//    // 初始化数组
//    int i;
//    int *a = (int*)malloc(n * sizeof(int));
//    for (i = 0; i < n; i++) {
//        *(a+i) = i+1;
//    }
//
//    circle(a, n);
//
//
//    free(a);
//
//    return 0;
//}
//
