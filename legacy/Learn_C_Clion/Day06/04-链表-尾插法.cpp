#include <stdio.h>
#include <stdlib.h>

// 链表储存结构
// --- 1. 定义存储结构 ---
typedef int ElementType; // 给 int 起个别名，方便以后把链表改成存 float 或 char

typedef struct Node {
    ElementType Data;    // 数据域：存放节点的值
    struct Node* Next;   // 指针域：存放下一个节点的内存地址（指向后继）
} Node;

// --- 2. 单链表初始化 ---
// 目的：创建一个“头结点”，它是整个链表的领头羊，不存有效数据
Node *initList() {
    // malloc 在堆区申请一块 Node 大小的内存，并返回其地址
    Node *head = (Node*)malloc(sizeof(Node));

    if (head == NULL) return NULL; // 安全检查：防止内存申请失败

    head->Data = 0;      // 头结点的数据域通常设为 0 或 链表当前长度
    head->Next = NULL;   // 刚开始，头结点后面谁也没有，所以是指向 NULL
    return head;         // 返回这个头结点的地址
}

// 单链表 - 尾插法
// 获取尾节点地址
Node *get_tail(Node *L) {
    Node *p = L;
    while (p->Next != NULL) {
        p = p->Next;
    }
    return p;
}

Node *insertTail(Node *tail, ElementType e) {
    Node *p = (Node*)malloc(sizeof(Node));
    p->Data = e;
    tail->Next = p;
    p->Next = NULL;
    return p;
}

// 单链表 - 遍历
void listNode(Node *L) {
    Node *p = L->Next;
    while (p != NULL) {
        printf("%d\n", p->Data);
        p = p->Next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    Node *list = initList();
    // 先获取尾节点
    Node *tail = get_tail(list);

    tail = insertTail(tail, 10);
    tail = insertTail(tail, 20);
    tail = insertTail(tail, 30);
    listNode(list);

    return 0;
}