#include <stdio.h>
#include <string.h>

struct Student {
    int num;
    char name[20];
    float score;
};

int main(int argc, char *argv[]) {
    struct Student stu[5] = {
        {10101, "Zhang", 78},
        {10103, "Wang", 98.5},
        {10106, "Li", 86},
        {10108, "Ling", 73.5},
        {10110, "Sun", 100},
    };
    // stu->num = 10000, strcpy(stu->name, "Hallo"), stu->score = 0;

    struct Student temp;

    const int n = 5;

    int i, j, k;

    for (i = 0; i < n - 1; i++) {
        k = i;
        for (j = i + 1; j < n; j++) {
            if (stu[j].score > stu[k].score) {
                k = j;
            }
            temp = stu[k];
            stu[k] = stu[i];
            stu[i] = temp;
        }
    }

    for (i = 0; i < n; i++) {
        printf("%6d %8s %6.2f\n", stu[i].num, stu[i].name, stu[i].score);
    }

    return 0;

}