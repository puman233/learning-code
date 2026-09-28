#include <stdio.h>

int numOfSubarrays(int* arr, int arrSize, int k, int threshold) {
    // 平均值阈值 threshold

    int i;
    int sum = 0, sumThreshold = threshold * k, count = 0;

    for (i = 0; i < k; i++) {
        sum += arr[i];
    }
    // maxSum = sum;
    if (sum >= sumThreshold) {
        count++;
    }

    for (i = k; i < arrSize; i++) {
        sum += arr[i] - arr[i - k];
        if (sum >= sumThreshold) {
            count++;
        }
    }

    return count;

}


int main(int argc, char *argv[]) {
    return 0;
}