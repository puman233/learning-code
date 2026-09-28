#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = numsSize;
    int *avgs = malloc(*returnSize * sizeof(int));
    long long int sum = 0;  // 避免数据过大溢出
    int i;

    // 如果k大于数组长度，则全为-1
    if (2 * k + 1 > numsSize) {
        for (i = 0; i < numsSize; i++) {
            avgs[i] = -1;
        }
        return avgs;
    }

    for (i = 0; i < (k * 2 + 1); i++) {
        sum += nums[i];
    }

    for (i = 0; i < k; i++) {
        avgs[i] = -1;
    }

    avgs[k] = sum / (k * 2 + 1);

    for (i = k + 1; i < numsSize - k; i++) {
        sum += nums[i + k] - nums[i - k - 1];
        avgs[i] = sum / (k * 2 + 1);
    }

    for (i = numsSize - k; i < numsSize; i++) {
        avgs[i] = -1;
    }

    return avgs;
}


int main(int argc, char *argv[]) {
    return 0;
}