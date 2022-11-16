#include <stdio.h>
#include <stdlib.h>

struct data_t {
    int num;
    struct data_t *next, *prev;
} head;

void insert(struct data_t *p, struct data_t *w)
{
    // p の指す要素の前に w の指す要素を挿入する
    struct data_t *q;
    q = p->prev;
    w->next = p;
    w->prev = q;
    q->next = w;
    p->prev = w;
}

struct data_t *insert_pos(struct data_t *p, struct data_t *w)
{
    // 先頭要素 p を受け取り、w の挿入する位置を返す
    for (p = p->next; p != &head; p = p->next) {
        if (p->num > w->num) {
            break;
        }
    }
    return p;
}

void printasc(struct data_t *p)
{
    // 先頭要素 p を受けとり、連結されている要素を昇順で表示する
    for (p = p->next; p != &head; p = p->next) {
        printf("%d ", p->num);
    }
    printf("\n");
}

void printdsc(struct data_t *p)
{
    // 先頭要素 p を受けとり、連結されている要素を高順で表示する
    for (p = p->prev; p != &head; p = p->prev) {
        printf("%d ", p->num);
    }
    printf("\n");
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
        insert(insert_pos(&head, w), w);
    }
    printasc(&head);
    printdsc(&head);
    return 0;
}