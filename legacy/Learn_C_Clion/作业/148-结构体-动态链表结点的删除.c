#include <stdio.h>
#include <stdlib.h>

typedef int Num;
typedef float Score;

typedef struct Node {
    Num num;
    Score score;
    struct Node* next;
} Node;

// 初始化
Node *initList(){
    Node *head = (Node *)malloc(sizeof(Node));

    if (head == NULL) {
        return NULL;
    }
    head->num = 0;
    head->score = 0;
    head->next = NULL;
    return head;
}

// 先获取尾节点
Node *get_tail(Node *L) {
    Node *p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
}

Node *creat(Node *tail, Num num, Score score) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        return NULL;
    }
    p->num = num;
    p->score = score;
    tail->next = p;
    p->next = NULL;
    return p;
}

void print(Node *L) {
    Node *p = L->next;
    while (p != NULL) {
        printf("%d%6.1f\n", p->num, p->score);
        p = p->next;
    }
    printf("\n");
}

int del(Node *L, int pos) {

    if (pos < 1) {
        printf("Position is wrong,Delete failure!\n");
        return 0;
    }

    Node *p = L;
    int i;

    for (i = 0; i < pos - 1; i++) {
        p = p->next;
        if (p == NULL) {
            printf("Position is wrong,Delete failure!\n");
            return 0;
        }
    }

    // if (p->next == NULL) {
    //     printf("Position is wrong,Delete failure!\n");
    // }

    Node *q = p->next;

    if (q == NULL) {
        printf("Position is wrong,Delete failure!\n");
    }

    p->next = q->next;
    free(q);
    return 1;

}

void freeList(Node *L) {
    Node *p = L->next;
    Node *q;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    free(L);
}

int main(int argc, char *argv[]) {
    int count = 0;
    Node *list = initList();
    Node *tail = get_tail(list);
    while (1) {
        int num;
        float score;
        scanf("%d%f", &num, &score);
        if (num == 0 && score == 0) {
            if (count == 0) {
                printf("Empty list!\n");
            }
            break;
        }
        count++;
        tail = creat(tail, num, score);
    }

    int pos = 0;
    scanf("%d", &pos);

    del(list, pos);

    print(list);

    freeList(list);

    return 0;
}