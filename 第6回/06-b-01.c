#include <stdio.h>
#include <stdlib.h>

struct data_t {
    int num;
    int count;
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

int check_list(struct data_t *p, int n)
{
    // 先頭要素 p と入力された数値 n を受け取り、nがすでにリストにあるか判定する
    for (p = p->next; p != &head; p = p->next) {
        if (p->num == n) {
            p->count += 1;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int d;
    head.next = &head;
    head.prev = &head;
    for (; scanf("%d", &d) != EOF;) {
        if (check_list(&head, d) == 0) {
            struct data_t *w;
            w = (struct data_t *)malloc(sizeof(struct data_t));
            if (w == NULL) {
                printf("out of memory\n");
                exit(1);
            }
            w->num = d;
            w->count = 1;
            insert(insert_pos(&head, w), w);
        }
    }
    struct data_t *p;
    for (p = head.next; p != &head; p = p->next) {
        printf("[%d] : %d\n", p->num, p->count);
    }
    return 0;
}