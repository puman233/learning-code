//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 100
//
//typedef int ElementType;
//
//typedef struct {
//    ElementType *data;
//    int length;
//} SeqList;
//
//// 初始化
//SeqList *initList(){
//    // 无需传参，自己声明 *L
//    SeqList *L = (SeqList*)malloc(sizeof(SeqList));
//    L->data = (ElementType*)malloc(sizeof(ElementType)*MAXSIZE);
//    L->length = 0;
//
//    return L;
//}
//
//// 顺序表 - 尾增法
//int appendElement(SeqList *L, ElementType e) {
//    if (L->length >= MAXSIZE) {
//        printf("Fully!\n");
//        return 1;
//    }
//    L->data[L->length++] = e;
//    return 0;
//}
//
//// 顺序表 - 遍历
//void listElement(SeqList *L) {
//    for (int i = 0; i < L->length; i++) {
//        printf("%d ", L->data[i]);
//    }
//    printf("\n");
//}
//
//// 顺序表 - 指定位置插入元素
//int insertElement(SeqList *L, ElementType e, int position) {
//    if (L->length >= MAXSIZE) {
//        printf("Fully!\n");
//        return 0;
//    }
//    if (position < 1 || position > L->length) {
//        printf("Invalid!\n");
//        return 0;
//    }
//    // 如果插入的位置是最后位置（即插入到末尾）
//    if (position == L->length) {
//        appendElement(L, e);  // 直接将元素添加到末尾
//        return 0;
//    }
//    if (position <= L->length) {
//        // 往后挪元素
//        for (int i = L->length - 1; i > position - 1; i--) {
//            L->data[i + 1] = L->data[i];
//        }
//        L->data[position - 1] = e;
//        L->length++;
//    }
//    return 1;
//}
//
//// 顺序表 - 指定位置 删除元素
//int deleteElement(SeqList *L, int position) {
//    if (L->length == 0) {
//        printf("Empty!\n");
//        return 0;
//    }
//    if (position < 1 || position > L->length) {
//        printf("Invalid!\n");
//        return 0;
//    }
//    if (position < L->length) {
//        // 往前挪元素
//        for (int i = position; i < L->length; i++) {
//            L->data[i - 1] = L->data[i];
//        }
//        L->length--;
//    }
//
//    return 1;
//
//}
//
//// 顺序表 - 查找元素 第一次出现的位置
//int findElement(SeqList *L, ElementType e){
//    if (L == NULL) {
//        printf("Empty!\n");
//        return 0;
//    }
//    if (L->length == 0) {
//        printf("Empty!\n");
//        return 0;
//    }
//    for (int i = 0; i < L->length; i++) {
//        if (L->data[i] == e) {
//            return i + 1;
//        }
//    }
//    printf("Invalid!\n");
//    return 0;
//}
//
//
//
//int main(int argc, char *argv[]) {
//
//    // 声明顺序表
//    // SeqList list;
//    // initList(&list);
//    SeqList *list = initList();
//
//    printf("Success. length: %d\n", list->length);
//    printf("Memory: %zu\n", sizeof(list->data));
//
//    printf("Old:\n");
//    appendElement(list, 'a');
//    appendElement(list, 'b');
//    appendElement(list, 'c');
//    appendElement(list, 100);
//    appendElement(list, 101);
//    appendElement(list, 102);
//    listElement(list);
//
//    printf("New:\n");
//    insertElement(list, 'a', 2);
//    insertElement(list, 'b', 3);
//    insertElement(list, 'c', 4);
//    listElement(list);
//
//    printf("After delete:\n");
//    deleteElement(list, 2);
//    deleteElement(list, 101);  // error
//    deleteElement(list, 4);
//    deleteElement(list, 5);
//    listElement(list);
//
//
//    printf("%d --> %d\n", 100, findElement(list, 100));
//
//    free(list->data);
//    free(list);
//    return 0;
//}
