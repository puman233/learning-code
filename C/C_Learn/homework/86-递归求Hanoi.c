////
//// Created by ihyj on 2025/11/17.
////
//
//#include <stdio.h>
//
//void move(char getone, char putone) {
//    // 完成打印工作
//    printf("%c--->%c\n", getone, putone);
//}
//
//void hanoi(int n, char one, char two, char three) {
//    // 递归完成盘子移动
//    if (n == 1) {
//        move(one, three);
//    } else {
//        // 把 n-1 个盘子从 A → B
//        hanoi(n - 1, one, three, two);
//        // 把 最大那一个盘子从 A → C
//        printf("%c--->%c\n", one, three);
//        // 把 n-1 个盘子从 B → C
//        hanoi(n - 1, two, one, three);
//    }
//}
//
//// int main(void) {
////     int m;
////     printf("Input the number of disks:");
////     scanf("%d", &m);
////     printf("The steps to moving %d disks:\n", m);
////     hanoi(m, 'A', 'B', 'C');
////     return 0;
//// }
