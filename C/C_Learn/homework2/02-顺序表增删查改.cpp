//
//# define _CRT_SECURE_NO_WARNINGS
//#include<string.h>
//#include <stdlib.h>
//# include <stdio.h>
//
///*
//完成顺序表操作的如下函数：建立，初始化，增加，插入，删除。
//
//具体要求如下：
//
//1．定义一顺序表类型，并定义顺序表。
//2．将教材中顺序表的建立、初始化、插入、删除等函数实现。
//3．顺序表能够存储10名学生的基本信息（包括姓名、学号和成绩）。
//4．由主函数按照用户要求对各个顺序表操作访问。
//5．每次操作之前要有明确的说明，操作后要输出操作结果。
//6．分析顺序表的插入、删除、查找的时间和空间复杂度。
//
//下面是参考代码，关键代码段留白，请思考补充。
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//// 定义学生信息结构体
//typedef struct Student {
//    char name[10];
//    char id[9];
//    int score;
//} Student;
//
//*/
//// 存储10名学生
//#define MAXSIZE 10
//
//typedef struct Student {
//    char name[10];
//    char id[9];
//    int score;
//} Student;
//
//// define
//typedef struct {
//    Student data[MAXSIZE];
//    int length;
//} SeqList;
//// 初始化
//void initList(SeqList* L) {
//    L->length = 0;
//}
//
//// 遍历
//void ListElement(SeqList *L) {
//
//    if (L->length == 0)
//    {
//        printf("NULL\n");
//    }
//    else if (L->length > MAXSIZE)
//    {
//        printf("Out of List\n");
//    }
//    else
//    {
//        printf("%-10s\t%-8s\t%-8s\n", "学号", "姓名", "成绩");
//
//        for (int i = 0; i < L->length; i++)
//        {
//            printf("%-9s\t%-10s\t%-8d\n", L->data[i].id, L->data[i].name, L->data[i].score);
//        }
//        printf("\n");
//    }
//}
//
//// 增
//int addElement(SeqList* L, const char *name, const char *id, int score) {
//    if (L->length >= MAXSIZE)
//    {
//        printf("Out of List\n");
//        return 0;
//    }
//    strcpy(L->data[L->length].name, name);
//    strcpy(L->data[L->length].id, id);
//    L->data[L->length].score = score;
//    L->length++;
//    return 1;
//}
//
//
//// 插
//int insertElement(SeqList* L, const char* name, const char* id, int score, int pos) {
//
//    if (L->length >= MAXSIZE)
//    {
//        printf("Out of List\n");
//        return 0;
//    }
//    if (pos < 1 || pos > L->length + 1)
//    {
//        printf("Invalid\n");
//        return 0;
//    }
//    // 尾插
//    if (pos == L->length + 1)
//    {
//        addElement(L, name, id, score);
//        return 1;
//    }
//    else if (pos <= L->length)
//    {
//        // 后挪
//        for (int i = L->length; i >= pos; i--)
//        {
//            strcpy(L->data[i].name, L->data[i - 1].name);
//            strcpy(L->data[i].id, L->data[i - 1].id);
//            L->data[i].score = L->data[i - 1].score;
//        }
//        strcpy(L->data[pos - 1].name, name);
//        strcpy(L->data[pos - 1].id, id);
//        L->data[pos - 1].score = score;
//        L->length++;
//        return 1;
//    }
//    return 0;
//}
//
//// 删
//int delElement(SeqList* L, int pos) {
//
//    if (L->length == 0)
//    {
//        printf("NULL\n");
//        return 0;
//    }
//    if (pos < 1 || pos > L->length)
//    {
//        printf("Invaild\n");
//        return 0;
//    }
//
//    // 前挪
//    for (int i = pos; i < L->length; i++)
//    {
//        strcpy(L->data[i - 1].name, L->data[i].name);
//        strcpy(L->data[i - 1].id, L->data[i].id);
//        L->data[i - 1].score = L->data[i].score;
//    }
//
//    L->length--;
//    return 1;
//
//}
//
//// 查(name or id)
//int findElement(SeqList* L, const char* search) {
//
//    if (L->length == 0)
//    {
//        printf("NULL\n");
//        return 0;
//    }
//    for (int i = 0; i < L->length; i++)
//    {
//        if (strcmp(L->data[i].name, search) == 0 || strcmp(L->data[i].id, search) == 0) {
//            return i + 1;
//        }
//    }
//    printf("Not Found\n");
//    return 0;
//}
//
//
//int main(void) {
//
//    // 初始化
//    SeqList StuList;
//    initList(&StuList);
//    printf("初始化成功\n");
//
//    // test data
//    char dataName[3][50] = {
//        "hello", "newTest", "Alice"
//    };
//    char dataId[3][20] = {
//        "001", "002", "003"
//    };
//    int dataScore[3] = {
//        12, 24, 48
//    };
//
//    // 增
//    for (int i = 0; i < 3; i++)
//    {
//        addElement(&StuList, dataName[i], dataId[i], dataScore[i]);
//    }
//    addElement(&StuList, "Miku", "O1", 16);
//    // output:
//    printf("初始数据如下：\n");
//    ListElement(&StuList);
//
//    // 插
//    insertElement(&StuList, "REJ", "004", 99, 2);
//    ListElement(&StuList);
//    // error data
//    printf("插入位置错误：\n");
//    insertElement(&StuList, "error", "000", 10, 20);
//    printf("不变：\n");
//    ListElement(&StuList);
//
//    // 删
//    printf("删除第3行数据后：\n");
//    delElement(&StuList, 3);
//    ListElement(&StuList);
//    printf("删除第99行数据后：\n");
//    delElement(&StuList, 99);
//    ListElement(&StuList);
//
//    // 茶
//    printf("「Alice」的位置：{ %d }行\n", findElement(&StuList, "Alice"));
//    printf("「NULL」的位置：{ %d }行\n", findElement(&StuList, "NULL"));
//    printf("「001」的位置：{ %d }行\n", findElement(&StuList, "001"));
//    printf("「O1」的位置：{ %d }行\n", findElement(&StuList, "O1"));
//    ListElement(&StuList);
//
//	return 0;
//}
