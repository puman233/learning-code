//
// Created by ihyj on 2025/11/20.
//

#include <stdio.h>

int find(int stu[10][3], int x);

// 数据输入
void input(int stu[10][3]) {
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &stu[i][j]);
        }
    }
}

// 学生编号 从小到大
void sort(int stu[10][3]) {
    int i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9 - i; j++) {
            if (stu[j][0] > stu[j + 1][0]) {
                int t0 = stu[j][0], t1 = stu[j][1], t2 = stu[j][2];
                stu[j][0] = stu[j + 1][0], stu[j][1] = stu[j + 1][1], stu[j][2] = stu[j + 1][2];
                stu[j + 1][0] = t0, stu[j + 1][1] = t1, stu[j + 1][2] = t2;
            }
        }
    }

}

// 折半 查找 学生编号 x，找到返回下标，否则 -1
int find(int stu[10][3], int x) {
    int left = 0, right = 9;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (stu[mid][0] == x) {
            return mid;
        }
        else if (stu[mid][0] > x) {
            right = mid - 1;
        }
        else if (stu[mid][0] < x) {
            left = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    int stu[10][3], x;
    input(stu);

    scanf("%d", &x);

    sort(stu);

    int index = find(stu, x);

    if (index == -1) {
        printf("Can't find\n");
    }
    else {
        printf("score:%4d%4d\n", stu[index][1], stu[index][2]);
    }

    return 0;
}



