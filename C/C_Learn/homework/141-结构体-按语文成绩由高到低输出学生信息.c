//#include <stdio.h>
//#include <stdlib.h>
//
//struct Student {
//    int id;
//    char name[100];
//    char gender;
//    int age;
//    float chinese;
//    float math;
//    float english;
//};
//
//
//int main(int argc, char *argv[]) {
//
//    struct Student stu[4] = {
//        {1, "zhangsan", 'M', 20, 86.3, 88.5, 78.5},
//        {2, "lisi", 'F', 18, 78.5, 76.3, 68.5},
//        {3, "wangwu", 'M', 19, 90.2, 85.6, 84.6},
//        {4, "zhaoliu", 'F', 21, 76.5, 90.5, 85.5},
//    };
//
//    int i, j;
//
//    // 结构体可以整体赋值
//
//    for (i = 0; i < 3; i++) {
//        struct Student temp;
//        for (j = i + 1; j < 4; j++) {
//            if (stu[i].chinese < stu[j].chinese) {
//                temp = stu[i];
//                stu[i] = stu[j];
//                stu[j] = temp;
//            }
//        }
//    }
//
//    for (i = 0; i < 4; i++) {
//        printf("%2d%10s%2c%4d%6.2f%6.2f%6.2f\n", stu[i].id, stu[i].name, stu[i].gender, stu[i].age, stu[i].chinese, stu[i].math, stu[i].english);
//    }
//
//    return 0;
//}