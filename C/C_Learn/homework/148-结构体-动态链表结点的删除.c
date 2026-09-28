//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//
//typedef int Num;
//typedef float Score;
//
//typedef struct Node {
//    Num num;
//    Score score;
//    struct Node* next;
//} Node;
//
//// 初始化
//Node *initList(){
//    Node *head = (Node *)malloc(sizeof(Node));
//
//    if (head == NULL) {
//        return NULL;
//    }
//    head->num = 0;
//    head->score = 0;
//    head->next = NULL;
//    return head;
//}
//
//// 先获取尾节点
//Node *get_tail(Node *L) {
//    Node *p = L;
//    while (p->next != NULL) {
//        p = p->next;
//    }
//    return p;
//}
//
//// 创建新节点
//Node *creat(Node *tail, Num num, Score score) {
//    Node *p = (Node *)malloc(sizeof(Node));
//    if (p == NULL) {
//        return NULL;
//    }
//    p->num = num;
//    p->score = score;
//    tail->next = p;
//    p->next = NULL;
//    return p;
//}
//
//// 输出链表
//void print(Node *L) {
//    Node *p = L->next;
//    if (p == NULL)
//    {
//        printf("Empty list!\n");
//		return;
//    }
//	while (p != NULL) { // 跳过头节点
//        printf("%d %6.1f\n", p->num, p->score);
//        p = p->next;
//    }
//    printf("\n");
//}
//
//// 删除指定位置的节点
//int del(Node *L, int pos) {
//	// 检查位置是否合法
//    if (pos < 1 || L == NULL) {
//        printf("Position is wrong,Delete failure!\n");
//        return 0;
//    }
//
//	Node* p = L;    // p 指向头节点
//    int i;
//
//    // 找到要删除节点的前一个节点
//    for (i = 0; i < pos - 1; i++) {
//		p = p->next;    // p 指向第 pos-1 个节点
//        if (p == NULL) {
//            printf("Position is wrong,Delete failure!\n");
//            return 0;
//        }
//
//		//p = p->next;
//    }
//
//    // if (p->next == NULL) {
//    //     printf("Position is wrong,Delete failure!\n");
//    // }
//
//    //Node *q = p->next;
//
//    // p->next 就是要删除的节点
//    if (p->next == NULL) {
//        printf("Position is wrong,Delete failure!\n");
//        return 0;
//    }
//
//	Node* q = p->next;  // q 是要删除的节点
//	p->next = q->next;  // 将前一个节点的 next 指向要删除节点的下一个节点
//
//    free(q);
//
//    return 1;
//
//}
//
//// 释放链表
//void freeList(Node *L) {
//    if (L == NULL)
//    {
//        return;
//    }
//    Node *p = L->next;
//    Node *q;
//
//    while (p != NULL) {
//        q = p->next;
//        free(p);
//        p = q;
//    }
//    free(L);
//}
//
//int main(int argc, char *argv[]) {
//    int count = 0;
//    Node *list = initList();
//
//    if (list == NULL)
//    {
//        printf("Memory allocation failed!");
//        return -1;
//    }
//
//    Node *tail = get_tail(list);
//    
//	// 输入数据，直到输入 0 0 为止
//	printf("Please input:\n");
//    while (1) {
//        int num;
//        float score;
//
//        int result = scanf("%d%f", &num, &score);
//		if (result != 2) {  // 检查输入是否成功读取两个值
//            printf("Input error!\n");
//			while (getchar() != '\n' && getchar() != EOF); // 清空输入缓冲区
//            continue;
//        }
//		if (num == 0 && score == 0) {   // 输入 0 0 退出
//            if (count == 0) {
//                printf("Empty list!\n");
//            }
//            break;
//        }
//
//        count++;
//        tail = creat(tail, num, score);
//        
//        if (tail == NULL)
//        {
//            printf("Memory allocation failed!\n");
//			freeList(list);
//            return -1;
//        }
//    }
//
//	// 如果链表为空，直接退出
//    if (count == 0)
//    {
//        printf("No data !\n");
//        printf("Empty list!\n");
//		print(list);
//		freeList(list);
//		return 0;
//    }
//
//
//	// 输入要删除的节点位置
//	printf("请输入要删除的节点位置：\n");
//    int pos = 0;
//
//    int result = scanf("%d", &pos);
//
//    int ch;
//	while ((ch = getchar()) != '\n' && ch != EOF); // 清空输入缓冲区
//
//    if (result != 1) {
//        printf("Input error!\n");
//		while (getchar() != '\n' && getchar() != EOF); // 清空输入缓冲区
//        return -1;
//    }
//    else if (pos > 0 && pos <= count)
//    {
//        int delResult = del(list, pos);
//        if (delResult)
//        {
//            printf("删除成功\n");
//        }
//    }
//    else
//    {
//		printf("Position is wrong,Delete failure!\n");
//    }
//
//	while ((ch = getchar()) != '\n' && ch != EOF); // 清空输入缓冲区
//
//	// 输出链表
//    print(list);
//
//    freeList(list);
//
//    return 0;
//}
//
