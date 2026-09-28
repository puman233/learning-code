#include <stdio.h>
#include <stdlib.h>

// 作废
// int isZero(int *nums, int left, int right, int m) {
//     int i, j;
//     int diffCount = 0;
//     for (i = left; i < right; i++) {
//         diffCount = 0;
//         for (j = left; j < right; j++) {
//             if (nums[i] != nums[j]) {
//                 diffCount++;
//             }
//         }
//         // 存在最多不同的元素超过判定阈值
//         if (diffCount >= m) {
//             return 1;   // yes
//         }
//     }
//     // 非子数组
//     return 0;
// }
//
// long long int sum(int* nums, int left, int right, long long int max) {
//
//     int i;
//     long long int sum = 0;
//
//     for (i = left; i < right; i++) {
//         sum += nums[i];
//     }
//
//     if (sum > max) {
//         return sum;
//     }
//     return max;
// }

// 滑动窗口
long long maxSum(int* nums, int numsSize, int m, int k) {

    // m个不相同的元素
    // 子长为k
    int i, diffNum = 0;
    long long int maxSum = 0;
    long long int currSum = 0;

    // 初始化数组为 0
    long long *find = (long long *)calloc(1000000001, sizeof(long long));

    for (i = 0; i < numsSize; i++) {

        if (i < k - 1) {
            if (find[nums[i]] == 0) {
                diffNum++;
            }
            find[nums[i]]++;
            currSum += nums[i];
            // 在窗口长度达到 k 之前，只做加元素，不判断、不滑动窗口
            continue;
        }

        currSum += nums[i];

        // 出现过是 1 未出现过是 0
        if (find[nums[i]] == 0) {
            diffNum++;
        }
        // 增加频次
        find[nums[i]]++;

        if (diffNum >= m) {
            maxSum = (maxSum > currSum) ? (maxSum) : (currSum);
        }

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


int main(int argc, char *argv[]){


    return 0;
}