//#include <stdio.h>
//#include <string.h>
//
//struct Student {
//    int id;
//    char name[20];
//    int age;
//};
//
//int main(int argc, char *argv[]) {
//
//    int i, j;
//    int n;
//
//    scanf("%d", &n);
//
//    struct Student students[n];
//
//    for (i = 0; i < n; i++) {
//        scanf("%d %s %d", &students[i].id, students[i].name, &students[i].age);
//    }
//
//    // 姓名从低到高
//    for (i = 0; i < n - 1; i++) {
//        for (j = 0; j < n - 1 - i; j++) {
//            if (strcmp(students[j].name, students[j + 1].name) > 0) {
//                struct Student temp = students[j];
//                students[j] = students[j + 1];
//                students[j + 1] = temp;
//            }
//        }
//    }
//
//    for (i = 0; i < n; i++){
//        printf("%3d%6s%3d\n", students[i].id ,students[i].name, students[i].age);
//    }
//
//    // 年龄从低到高
//    for (i = 0; i < n - 1; i++) {
//        for (j = 0; j < n - 1 - i; j++) {
//            if (students[j].age > students[j + 1].age) {
//                struct Student temp = students[j];
//                students[j] = students[j + 1];
//                students[j + 1] = temp;
//            }
//            // 年龄相同时排序姓名
//            else if (students[j].age == students[j + 1].age) {
//                if (strcmp(students[j].name, students[j + 1].name) > 0) {
//                    struct Student temp = students[j];
//                    students[j] = students[j + 1];
//                    students[j + 1] = temp;
//                }
//            }
//        }
//    }
//
//    for (i = 0; i < n; i++) {
//        printf("%3d%6s%3d\n", students[i].id, students[i].name, students[i].age);
//    }
//
//
//    return 0;
//}