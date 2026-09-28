#include <stdio.h>
#include <stdlib.h>

// 链表储存结构
// --- 1. 定义存储结构 ---
typedef int ElementType; // 给 int 起个别名，方便以后把链表改成存 float 或 char

typedef struct Node {
    ElementType Data;    // 数据域：存放节点的值
    struct Node* Next;   // 指针域：存放下一个节点的内存地址（指向后继）
} Node;

// 单链表 - 初始化
// 目的：创建一个“头结点”，它是整个链表的领头羊，不存有效数据
Node *initList() {
    // malloc 在堆区申请一块 Node 大小的内存，并返回其地址
    Node *head = (Node*)malloc(sizeof(Node));

    if (head == NULL) return NULL; // 安全检查：防止内存申请失败

    head->Data = 0;      // 头结点的数据域通常设为 0 或 链表当前长度
    head->Next = NULL;   // 刚开始，头结点后面谁也没有，所以是指向 NULL
    return head;         // 返回这个头结点的地址
}


// 单链表 - 头插法
// 头插法的顺序和排列的顺序是相反的
// 特点：每次新来的节点都强行挤在“头结点”和“第一个节点”之间
int insertHead(Node* L, ElementType e) {
    // 1. 创建新节点 p
    Node *p = (Node*)malloc(sizeof(Node));

    if (p == NULL) return 0;    // 创建失败 返回 0

    // 2. 装载数据
    p->Data = e;

    // 3. 核心指针操作（顺序不能错！）
    // 第一步：让新节点 p 指向原本在头结点后面的那个人
    p->Next = L->Next;

    // 第二步：让头结点 L 指向新节点 p
    L->Next = p;

    return 1;
}



// 单链表 - 遍历
void listNode(Node *L) {
    Node *p = L->Next;
    while (p != NULL) {   // 只要还没走到尽头（NULL）
        printf("%d -> \n", p->Data); // 打印当前节点数据
        p = p->Next;      // 指针后移：把 p 变成下一个节点的地址
    }
    printf("\n");
}

/*
    *初始状态：[头节点] -> NULL
    插入 10：
    10 看到头节点后面没人，直接站过去。
    结果：[头节点] -> 10 -> NULL
    插入 20：
    20 插队到头节点后面，把 10 挤到了后面。
    结果：[头节点] -> 20 -> 10 -> NULL
    插入 30：
    30 再次插队，抢占了第一位，把 20 和 10 都往后推。
    结果：[头节点] -> 30 -> 20 -> 10 -> NULL

 */

int main(int argc, char *argv[]) {
    Node *head = initList();
    Node *list = initList();
    insertHead(list, 10);
    insertHead(list, 20);
    insertHead(list, 30);
    listNode(list);

    return 0;
}