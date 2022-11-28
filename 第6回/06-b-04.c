#include <stdio.h>
#include <stdlib.h>

struct data_t {
    int num, math, science, english;
    float average;
    struct data_t *num_next, *num_prev, *ave_next, *ave_prev;
} head;

void sort(struct data_t *w)
{
    struct data_t *num_p, *num_q, *ave_p, *ave_q;
    for (num_p = head.num_next; num_p != &head; num_p = num_p->num_next) {
        if (num_p->num > w->num) {
            break;
        }
    }
    num_q = num_p->num_prev;
    w->num_next = num_p;
    w->num_prev = num_q;
    num_q->num_next = w;
    num_p->num_prev = w;
    for (ave_p = head.ave_next; ave_p != &head; ave_p = ave_p->ave_next) {
        if (ave_p->average > w->average) {
            break;
        }
    }
    ave_q = ave_p->ave_prev;
    w->ave_next = ave_p;
    w->ave_prev = ave_q;
    ave_q->ave_next = w;
    ave_p->ave_prev = w;
}

int main()
{
    head.num_next = &head;
    head.num_prev = &head;
    head.ave_next = &head;
    head.ave_prev = &head;
    for (;;) {
        struct data_t *w;
        w = (struct data_t *)malloc(sizeof(struct data_t));
        if (w == NULL) {
            printf("out of memory\n");
            exit(1);
        }
        printf("Input ID, Math, Science English : ");
        scanf("%d %d %d %d", &(w->num), &(w->math), &(w->science), &(w->english));
        w->average = (float)(w->math + w->science + w->english) / 3;
        if (w->num < 0) {
            break;
        }
        sort(w);
    }
    struct data_t *w;
    printf("[ID]\n");
    for (w = head.num_next; w != &head; w = w->num_next) {
        printf("ID : %d, Math : %d, Science : %d, English : %d\n", w->num, w->math, w->science, w->english);
    }
    printf("[Average]\n");
    for (w = head.ave_next; w != &head; w = w->ave_next) {
        printf("Average : %f, ID : %d\n", w->average, w->num);
    }
    return 0;
}