#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE 32

struct data {
    char word[MAX_LINE];
    struct data *next, *prev;
} head;

void insert(struct data *p, struct data *w)
{
    struct data *q;
    q = p->prev;
    w->next = p;
    w->prev = q;
    q->next = w;
    p->prev = w;
}

struct data *insert_pos(struct data *p, struct data *w)
{
    for (p = p->next; p != &head; p = p->next) {
        if (strcmp(p->word, w->word) > 0) {
            break;
        }
    }
    return p;
}

void printasc(struct data *p)
{
    for (p = p->next; p != &head; p = p->next) {
        printf("%s", p->word);
    }
}

int main()
{
    int i = 0, check;
    head.next = &head;
    head.prev = &head;
    while (1) {
        struct data *w;
        w = (struct data *)malloc(sizeof(struct data));
        if (w == NULL) {
            printf("out of memory\n");
            exit(1);
        }
        if (fgets(w->word, MAX_LINE, stdin) == NULL) {
            break;
        }
        insert(insert_pos(&head, w), w);
    }
    printasc(&head);
    return 0;
}