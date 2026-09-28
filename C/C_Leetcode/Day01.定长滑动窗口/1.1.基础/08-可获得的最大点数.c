#include <stdio.h>

/*
 *  滑动窗口
 *
 *      从 n 个元素中的 k 个元素求最优路径（maxSum）
 *
 *      滑动窗口角度 windows = n - k
 *
 *      找出数组中总和为 n - k 的连续子数组 minSum
 *
 *      总和(totalSum) 减去 minSum = maxSum

 */

int maxScore(int* cardPoints, int cardPointsSize, int k) {
    int i;
    int currSum = 0, minSum = 0, totalSum = 0;

    for (i = 0; i < cardPointsSize; i++) {
        totalSum += cardPoints[i];
    }

    for (i = 0; i < cardPointsSize - k; i++) {
        currSum += cardPoints[i];
    }

    minSum = currSum;

    for (i = cardPointsSize - k; i < cardPointsSize; i++) {
        currSum += cardPoints[i];
        currSum -= cardPoints[i - cardPointsSize + k];
        minSum = currSum < minSum ? currSum : minSum;
    }

    return totalSum - minSum;
}


// 错误的 错误的“贪心”，都算不上“贪心”
// int maxScore(int* cardPoints, int cardPointsSize, int k) {
//
//     int i, kNum = 0;
//     long long int sum = 0;
//
//     // 最大 i 为中位数
//     for (i = 0; i < cardPointsSize / 2 + 1 && kNum <= k; i++) {
//         // 判断一级
//         if (cardPoints[i] <= cardPoints[cardPointsSize - i - 1]) {
//             // 判断二级
//             if (cardPoints[i + 1] <= cardPoints[cardPointsSize - i]) {
//                 sum += cardPoints[cardPointsSize - i];
//             }
//             else {
//                 sum += cardPoints[i + 1];
//             }
//         }
//         else {
//             sum += cardPoints[i];
//         }
//         kNum++;
//     }
//
//     return sum;
//
// }


int main(int argc, char *argv[]) {

    return 0;
}