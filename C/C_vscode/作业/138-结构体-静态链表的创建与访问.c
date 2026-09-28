#include <stdio.h>

struct Student {
    int num;
    float score;
    // 链表中每个结点需要有一个指向自身类型的结构变量
    struct Student *next;
};

int main(int argc, char *argv[]) {

    struct Student a,b,c, *head, *p;

    scanf("%d %f", &a.num, &a.score);
    scanf("%d %f", &b.num, &b.score);
    scanf("%d %f", &c.num, &c.score);

    // a, b, c结点链接为一个静态链表，head 为链表的头指针
    head = &a;
    a.next = &b;
    b.next = &c;
    c.next = NULL;

    // 输出
    p = head;

    do {
        printf("%d %5.1f\n", p->num, p->score);
        p = p->next;
    } while (p != NULL);


    return 0;
}