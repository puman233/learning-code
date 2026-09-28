//
// Created by ihyj on 2025/11/22.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
 *  内存：
 *  1.静态/全局内存：
 *      静态声明的变量和全局变量使用这部分内存
 *      这些变量在程序开始运行时分配
 *      直到程序终了才消失
 *  2.自动内存（栈内存）：
 *      函数内部声明的变量使用这部分内存
 *      函数被调用时才创建
 *  3.动态内存（堆内存）：
 *      根据需求编写代码动态分配内存
 *      编写代码释放
 *      内存中的内容直到释放才消失
*/

typedef struct point {
    int x;
    int y;
} po;

int main(int argc, char *argv[]) {
    // void* malloc(size_t);
    // 如果成功，返回堆内存上分配的内存指针
    // 否则，返回空指针

    int *p = (int*)malloc(sizeof(int));
    *p = 5;
    printf("*p = %d\n",*p);
    free(p);

    char *s;
    s = (char*)malloc(sizeof(char));
    strcpy(s,"Hello World");
    printf("%s\n",s);

    int *arr = (int*)malloc(sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n",i,arr[i]);
    }
    free(arr);

    po *pos;
    pos = (po*)malloc(sizeof(po));  // 此时sizeof(po)为8字节
    pos->x = 5;
    (*pos).y = 10;
    printf("pos.x = %d,pos.y = %d\n",pos->x,pos->y);
    free(pos);


    return 0;
}


