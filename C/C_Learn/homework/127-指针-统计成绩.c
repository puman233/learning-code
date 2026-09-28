//#include <stdio.h>
//#include <stdlib.h>
//
//float first_class_average(float **a) {
//    int i;
//    float sum = 0;
//
//    for (i = 0; i < 4; i++){
//        sum += *(*(a + i) + 0);
//    }
//
//    return sum / 4.0;
//}
//
//// 找出两门及以上课程不及格的学生
//void find_lower(float **a) {
//    int i, j;
//    int find_count = 0;
//    float sum = 0;
//
//    for (i = 0; i < 4; i++) {
//        find_count = 0;
//        sum = 0;
//        for (j = 0; j < 5; j++) {
//            sum += *(*(a + i) + j);
//            if (*(*(a + i) + j) < 60) {
//                find_count++;
//            }
//        }
//        if (find_count >= 2) {
//            printf("No %d: %.1f %.1f %.1f %.1f %.1f average: %.1f\n", i + 1, *(*(a + i) + 0), *(*(a + i) + 1), *(*(a + i) + 2), *(*(a + i) + 3), *(*(a + i) + 4), sum / 5.0);
//        }
//    }
//}
//
//// 找出平均成绩up90 或 全部成绩up85
//void find_upper(float **a) {
//    int i, j;
//    float sum_upper = 0;
//    int find_upper = 0;
//
//    for (i = 0; i < 4; i++) {
//        find_upper = 0;
//        sum_upper = 0;
//        for (j = 0; j < 5; j++) {
//            sum_upper += *(*(a + i) + j);
//            if (*(*(a + i) + j) >= 85) {
//                find_upper++;
//            }
//        }
//        if ((sum_upper / 5.0) >= 90 || find_upper >= 5) {
//            printf("No %d: %.1f %.1f %.1f %.1f %.1f average: %.1f\n", i + 1, *(*(a + i) + 0), *(*(a + i) + 1), *(*(a + i) + 2), *(*(a + i) + 3), *(*(a + i) + 4), sum_upper / 5.0);
//        }
//    }
//}
//
//
//int main(int argc, char *argv[]) {
//    int i,j;
//
//    float **a = malloc(4 * sizeof(float*));
//
//    for (i = 0; i < 4; i++) {
//        *(a + i) = malloc(5 * sizeof(float));
//    }
//
//    for (i = 0; i < 4; i++) {
//        for (j = 0; j < 5; j++) {
//            scanf("%f", *(a + i) + j);
//        }
//    }
//
//    float first_aver = first_class_average(a);
//
//    printf("Average of course 1: %.1f\n", first_aver);
//
//    printf("More than 2 failed courses:\n");
//    find_lower(a);
//
//    printf("Average score >=90 or all courses >=85:\n");
//    find_upper(a);
//
//
//    for (i = 0; i < 4; i++) {
//        free(*(a + i));
//    }
//    free(a);
//
//
//    return 0;
//}