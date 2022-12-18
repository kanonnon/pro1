#include <stdio.h>
#include <stdlib.h>

struct alpha {
    int code, count;
    struct alpha *next, *prev;
} head;

void insert(struct alpha *p, struct alpha *w)
{
    struct alpha *q;
    q = p->prev;
    w->next = p;
    w->prev = q;
    q->next = w;
    p->prev = w;
}

struct alpha *insert_pos(struct alpha *p, struct alpha *w)
{
    for (p = p->next; p != &head; p = p->next) {
        if (p->code > w->code) {
            break;
        }
    }
    return p;
}

void printasc(struct alpha *p)
{
    int i;
    for (p = p->next; p != &head; p = p->next) {
        for (i = 0; i < p->count; i++) {
            printf("%c", p->code);
        }
    }
    printf("\n");
}

int search(struct alpha *p, int c)
{
    for (p = p->next; p != &head; p = p->next) {
        if (p->code == c) {
            p->count += 1;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i, c;
    head.next = &head;
    head.prev = &head;
    while (!(48 <= (c = getchar()) && c <= 57)) {
        struct alpha *w;
        if (c == 10 || search(&head, c) == 1) {
            continue;
        }
        w = (struct alpha *)malloc(sizeof(struct alpha));
        if (w == NULL) {
            printf("out of memory\n");
            exit(1);
        }
        w->code = c;
        w->count = 1;
        insert(insert_pos(&head, w), w);
    }
    printasc(&head);
    return 0;
}