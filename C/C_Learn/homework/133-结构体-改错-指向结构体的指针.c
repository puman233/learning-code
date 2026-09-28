//#include <stdio.h>
//
//struct Friends_list
//{
//    char name[10];
//    int age;
//    char telephone[13];
//};
//
//int main(int argc, char *argv[]) {
//
//    struct Friends_list friend1 = {"zhang",24,"82982543"}, *p;
//
//    p = &friend1;
//
//    /*
//        .只能用于结构体变量，不能用于结构体指针；
//        结构体指针必须使用 ->
//
//     */
//    // printf("%s %d %s\n", p.name, p.age, p.telephone);
//    printf("%s %d %s\n", p->name, p->age, p->telephone);
//    // 等价于
//    printf("%s %d %s\n", (*p).name, (*p).age, (*p).telephone);
//
//    return 0;
//}