#include <stdio.h>
#include <stdlib.h>

struct data_t {
    int num;
    struct data_t *next, *prev;
} head;

void insert(struct data_t *p, struct data_t *w)
{
    struct data_t *q;
    q = p->prev;
    w->next = p;
    w->prev = q;
    q->next = w;
    p->prev = w;
}

void printall(struct data_t *p)
{
    struct data_t *w;
    for (w = p->next; w != p; w = w->next) {
        printf("[p: %p, bp: %p, fp: %p, data:%d]\n", w, w->prev, w->next, w->num);
    }
}

int main()
{
    int d;
    head.next = &head;
    head.prev = &head;
    for (; scanf("%d", &d) != EOF;) {
        struct data_t *w;
        w = (struct data_t *)malloc(sizeof(struct data_t));
        if (w == NULL) {
            printf("out of memory\n");
            exit(1);
        }
        w->num = d;
        insert(&head, w);
    }
    printall(&head);
    return 0;
}