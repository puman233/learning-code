//#include <stdio.h>
//
//int main(int argc, char *argv[]) {
//
//    union Num
//    {
//        int i;
//        char ch;
//        float f;
//    } a={101};  // 联合体只能初始化第一个成员
//    // 或使用指定成员初始化
//
//    a.ch = 'w', a.f = 68.5;
//
//    printf("%.1f\n",a.f);
//
//
//    return 0;
//}