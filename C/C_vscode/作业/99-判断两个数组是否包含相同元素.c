//
// Created by ihyj on 2025/11/20.
//

#include <stdio.h>

int same_set(int a[], int b[], int len) {
    int i,j, a1 = 0, b1 = 0;
    for (i = 0; i < len; i++) {
        a1 = 0;
        for (j = 0; j < len; j++) {
            if (a[i] == b[j]) {
                a1 = 1;
                break;
            }
        }
        if (a1 == 0) {
            return 0;
        }
    }

    for (i = 0; i < len; i++) {
        b1 = 0;
        for (j = 0; j < len; j++) {
            if (b[i] == a[j]) {
                b1 = 1;
                break;
            }
        }
        if (b1 == 0) {
            return 0;
        }
    }


    return 1;

}


int main(int argc, char *argv[]) {

    int n, arr1[100], arr2[100], i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("%d\n", same_set(arr1, arr2, n));

    return 0;
}


