#include <stdio.h>
#include <stdlib.h>

typedef int Num;
typedef float Score;

typedef struct Node {
    Num num;
    Score score;
    struct Node* next;
} Node;

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

// 鍏堣幏鍙栧熬鑺傜偣
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
    print(list);

    freeList(list);

    return 0;
}