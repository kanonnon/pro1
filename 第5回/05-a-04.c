#include <stdio.h>
#include <stdlib.h>

struct point{
    int a;
    int b;
    int c;
};

int main()
{
    struct point *p;
    p = (struct point *)malloc(sizeof(struct point));
    if (p == NULL) {
        printf("out of memory\n");
        exit(1);
    }
    printf("Input three nums : ");
    scanf("%d %d %d", &(p->a), &(p->b), &(p->c));
    printf("%d + %d + %d = %d\n", p->a, p->b, p->c, p->a + p->b + p->c);
    free(p);
    return 0;
}