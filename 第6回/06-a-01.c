#include <stdio.h>
#include <stdlib.h>

struct number {
    int i;
    struct number *next, *prev;
} head;

void insert(struct number *p_prev, struct number *p)
{
    struct number *p_next;
    p_next = p_prev->next;
    p->next = p_next;
    p->prev = p_prev;
    p_prev->next = p;
    p_next->prev = p;
}

int main()
{
    int i;
    head.next = &head;
    head.prev = &head;
    printf("input 5 numbers : ");
    for (i = 0; i < 5; i++) {
        struct number *p;
        p = (struct number *)malloc(sizeof(struct number));
        if (p == NULL) {
            printf("out of memory\n");
            exit(1);
        }
        scanf("%d", &(p->i));
        insert(&head, p);
    }
    struct number *p;
    printf("number list : ");
    for (p = head.prev; p != &head; p = p->prev) {
        printf("%d ", p->i);
    }
    printf("\nnumber list : ");
    for (p = head.next; p != &head; p = p->next) {
        printf("%d ", p->i);
    }
    printf("\n");
    return 0;
}