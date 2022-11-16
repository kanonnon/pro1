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

void remov(struct data_t *p, int index)
{
    // 先頭要素(番兵ノード)を受けとり、index 番目の要素を消去する
    int i;
    struct data_t *p_prev, *p_next;
    for (i = 0; i < index + 1; i++) {
        p = p->next;
    }
    p_prev = p->prev;
    p_next = p->next;
    p_prev->next = p_next;
    p_next->prev = p_prev;
    free(p);
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
    int d, count = 0;
    head.next = &head;
    head.prev = &head;
    printf("State Input\n");
    for (; scanf("%d", &d) != EOF;) {
        count += 1;
        struct data_t *w;
        w = (struct data_t *)malloc(sizeof(struct data_t));
        if (w == NULL) {
            printf("out of memory\n");
            exit(1);
        }
        w->num = d;
        insert(&head, w);
    }
    rewind(stdin); // キーボードバッファをクリア
    printf("State Remove\n");
    for (; scanf("%d", &d) != EOF;) {
        if (d >= count - 1) {
            printf("List doesn't have the index number : %d\n", d);
        } else {
            remov(&head, d);
        }
    }
    printall(&head);
    return 0;
}