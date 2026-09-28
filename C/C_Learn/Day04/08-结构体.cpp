////
//// Created by ihyj on 2025/11/22.
////
//
//#include<stdio.h>
//
///*
//*   struct 结构体名{
//*       数据类型 变量名;
//*       数据类型 变量名;
//*       ...
//*   };
// *
//
// */
//
//struct point {
//    int x;
//    int y;
//};
//
//// 结构体函数
//struct point create_point(int x, int y) {
//    struct point temp;
//    temp.x = x;
//    temp.y = y;
//    return temp;
//}
//
//int main(int argc, char *argv[]) {
//    struct point p;
//    p.x = 100;
//    p.y = 200;
//    printf("p.x = %d,p.y = %d\n",p.x,p.y);
//
//    struct point p2 = create_point(5,10);
//    printf("p.x = %d,p.y = %d\n",p2.x,p2.y);
//
//    struct point *p3;
//    p3 = &p;
//    (*p3).x = 10;
//    (*p3).y = 20;
//    printf("x=%d, y=%d\n", p.x, p.y);
//    // p3->x == (*p3).x
//    // p3->y == (*p3).y
//    printf("p.x = %d,p.y = %d\n",p3->x,p3->y);
//
//    return 0;
//}
//
