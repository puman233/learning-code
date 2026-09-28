//#include <stdio.h>
//
//struct friends {
//    char name[20];
//    int birthday;
//    char phonenum[20];
//};
//
//
//int main(int argc, char *argv[]) {
//
//    // 朋友数 n < 10
//    int n;
//
//    printf("Input n:");
//    scanf("%d", &n);
//
//    struct friends boos[n];
//
//    int i;
//
//    for (i = 0; i < n; i++) {
//        printf("Input the name,birthday,number of the %d friend:", i + 1);
//        scanf("%s %d %s", boos[i].name, &boos[i].birthday, boos[i].phonenum);
//    }
//
//    for (i = 0; i < n - 1; i++) {
//        for (int j = i + 1; j < n; j++) {
//            struct friends temp;
//            if (boos[i].birthday > boos[j].birthday) {
//                temp = boos[i];
//                boos[i] = boos[j];
//                boos[j] = temp;
//            }
//        }
//    }
//
//    for (i = 0; i < n; i++) {
//        printf("%s %d %s\n", boos[i].name, boos[i].birthday, boos[i].phonenum);
//    }
//
//
//    return 0;
//}