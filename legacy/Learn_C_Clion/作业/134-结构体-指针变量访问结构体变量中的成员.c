#include <stdio.h>
#include <string.h>

struct Student {
    long int num;
    char name[20];
    char sex;
    float score;
};

int main(int argc, char *argv[]) {

    struct Student stu, *p;

    p = &stu;

    stu.num = 89101;
    strcpy(p->name, "Li Lin");
    p->sex = 'M';
    (*p).score = 89.5;
    printf(" No:%ld\n name:%s\n sex:%c\n score:%f\n", (*p).num, p->name, p->sex, p->score);



    return 0;
}