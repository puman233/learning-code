#include <stdio.h>
#include <stdlib.h>

long long maximumSubarraySum(int* nums, int numsSize, int k) {

    int i, diffNum = 0;

    long long int maxSum = 0, currSum = 0;

    // 哈希表
    long long *find = (long long*)calloc(1000001, sizeof(long long));

    for (i = 0; i < numsSize; i++) {
        if (i < k - 1) {
            if (find[nums[i]] == 0) {
                diffNum++;
            }
            find[nums[i]]++;
            currSum += nums[i];
            continue;
        }

        // 窗口进入 i
        currSum += nums[i];

        if (find[nums[i]] == 0) {
            diffNum++;
        }
        // 增加频次
        find[nums[i]]++;

        // 全部元素不相等才比较大小
        if (diffNum == k) {
            maxSum = (maxSum > currSum) ? maxSum : currSum;
        }

        // 窗口 离开 i - k + 1
        currSum -= nums[i - k + 1];

        if (find[nums[i - k + 1]] == 1) {
            diffNum--;
        }
        // 减小频次
        find[nums[i - k + 1]]--;
    }

    free(find);

    return maxSum;

}

int main(int argc, char *argv[]) {

    return 0;
}
