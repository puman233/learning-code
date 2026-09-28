#include <stdio.h>

struct stu     /* student information */
{
    int no;
    char name[10];
    char gen[3];
    int age;
};

int main(int argc, char *argv[]) {
    struct stu p;

    printf("Please input Number,Name,Gender,Age:\n");
    scanf("%d %s %c %d", &p.no, p.name, p.gen, &p.age);
    printf("Number:%d, Name:%s, Gender:%c, Age:%d\n", p.no, p.name, p.gen[0], p.age);

    return 0;
}