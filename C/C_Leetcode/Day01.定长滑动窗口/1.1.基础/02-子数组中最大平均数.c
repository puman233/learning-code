#include <stdio.h>

// 婊戝姩绐楀彛
double findMaxAverage(int* nums, int numsSize, int k) {

    int i;
    int sum = 0, maxSum = 0;
    // int n = sizeof(nums) / sizeof(nums[0]);

    for (i = 0; i < k; i++) {
        sum += nums[i];
    }

    maxSum = sum;

    for (i = k; i < numsSize; i++) {
        sum -= nums[i - k];
        sum += nums[i];
        // sum += nums[i] - nums[i - k];
        if (sum > maxSum) maxSum = sum;
        // maxSum = maxSum > sum ? maxSum : sum;
    }


    return (double)maxSum / k;

}

int main(int argc, char *argv[]) {


    return 0;
}