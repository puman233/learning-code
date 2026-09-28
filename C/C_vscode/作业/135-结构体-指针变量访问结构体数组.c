#include <stdio.h>

struct Student {
    int num;
    char name[20];
    char sex;
    int age;
}   stu[3] = {
    {10101, "LiLin", 'M', 18},
    {10102, "ZhangYun", 'M', 19},
    {10104, "WangMin", 'F', 20},
};

int main(int argc, char *argv[]) {
    struct Student *p;

    for (p = stu; p < stu + 3; p++) {
        printf("%d %s %c %d\n", p->num, p->name, p->sex, p->age);
    }


    return 0;
}