#include <stdio.h>
#include <stdlib.h>

struct data {
    int num;
    struct data *fp, *bp;
};

void push(struct data *sentinel, int n)
{
    // 番兵ノードを受け取り、値をリストに格納する
    printf("push %d\n", n);
    struct data *p, *p_next;
    p = (struct data *)malloc(sizeof(struct data));
    if (p == NULL) {
        printf("out of memory\n");
        exit(1);
    }
    p->num = n;
    p_next = sentinel->fp;
    p->fp = p_next;
    p->bp = sentinel;
    sentinel->fp = p;
    p_next->bp = p;
}

int pop_queue(struct data *sentinel)
{
    // リストをキューとみなして値を取り出す
    struct data *p, *p_prev;
    p = sentinel->bp;
    p_prev = p->bp;
    p_prev->fp = sentinel;
    sentinel->bp = p_prev;
    printf("pop %d(queue)\n", p->num);
    free(p);
    return p->num;
}

int pop_stack(struct data *sentinel)
{
    // リストをスタックみなして値を取り出す
    struct data *p, *p_next;
    p = sentinel->fp;
    p_next = p->fp;
    sentinel->fp = p_next;
    p_next->bp = sentinel;
    printf("pop %d(stack)\n", p->num);
    free(p);
    return p->num;
}

void print_data(struct data *sentinel)
{
    // リストに格納されている数値を出力する
    printf("stored nums : ");
    struct data *p;
    for (p = sentinel->bp; p != sentinel; p = p->bp) {
        printf("%d ", p->num);
    }
    printf("\n");
}

int main()
{
    int i;
    struct data sentinel;
    sentinel.fp = sentinel.bp = &sentinel;
    push(&sentinel,1);
    print_data(&sentinel);
    push(&sentinel, 2);
    print_data(&sentinel);
    push(&sentinel, 3);
    print_data(&sentinel);
    pop_queue(&sentinel);
    print_data(&sentinel);
    pop_stack(&sentinel);
    print_data(&sentinel);
    return 0;
}