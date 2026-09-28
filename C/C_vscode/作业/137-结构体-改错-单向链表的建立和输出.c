#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int num;
    struct Node *next;
};

int main(void)
{
    struct Node *head, *tail, *p;
    // head 始终指向第一个节点
    // tail 始终指向最后一个节点 即 NULL
    int num;
    int size = sizeof(struct Node);

    // 初始化链表
    head=tail=NULL;

    printf("Please input:\n");
    scanf("%d", &num);

    /*creat the single linked list*/
    while(num != 0)     // 输入0退出
    {
        p = (struct Node *) malloc(size);   // 产生一个新节点
        // p = malloc(sizeof(struct Node));
        p->num = num;
        p->next = NULL;

        if (head == NULL) {
            head = tail = p;
        }
        else {
            tail->next = p;
            tail = p;
        }
        scanf("%d", &num);
    }

    /*output the single linked list*/
    printf("The single linked list is:\n");

    for(p = head; p != NULL; p = p->next)
        printf("%d\n", p->num);


    return 0;
}