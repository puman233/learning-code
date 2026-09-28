//
// Created by ihyj on 2025/11/22.
//

#include<stdio.h>

typedef int myType1;
typedef char myType2;

/*
 *  typedef struct 结构体名(可省略){
 *      数据类型 变量名;
 *      数据类型 变量名;
 *  } 别名;

 */
typedef struct point {
    int x;
    int y;
} po;   // 加了别名后可以在使用变量时不声明struct



int main(int argc, char *argv[]) {
    myType1 x, y;
    x = 5, y = 10;
    printf("x = %d,y = %d\n",x,y);

    po p;
    p.x = 3;
    p.y = 5;
    printf("p.x = %d,p.y = %d\n",p.x,p.y);

    return 0;
}


