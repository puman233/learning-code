//#include <stdio.h>
//#include <string.h>
//
//struct Person {
//    char name[100];
//
//    int count;
//};
//
//
//int main(int argc, char *argv[]) {
//
//    int i,j;
//
//    char leader_name[100];
//
//    struct Person leader[3] = {
//        {"Li", 0},
//        {"Zhang", 0},
//        {"Wang", 0}
//    };
//
//    for (i = 0; i < 10; i++) {
//        scanf("%s", leader_name);
//        for (j = 0; j < 3; j++) {
//            if (strcmp(leader_name, leader[j].name) == 0) {
//                leader[j].count++;
//            }
//        }
//    }
//
//    for (i = 0;i < 3;i++) {
//        printf("%5s:%d\n", leader[i].name, leader[i].count);
//    }
//
//    return 0;
//}