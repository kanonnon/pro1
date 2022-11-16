#include <stdio.h>
#include <stdlib.h>

struct calc_result{
    float sum, difference, product, quotient;
} *p;

struct calc_result * get_calc_result(float x, float y)
{
    p->sum = x + y;
    p->difference = x - y;
    p->product = x * y;
    if (y == 0) {
        p->quotient = 0;
    } else {
        p->quotient = x / y;
    }
    return p;
}

int main()
{
    float x, y;
    p = (struct calc_result *)malloc(sizeof(struct calc_result));
    if (p == NULL) {
        printf("out of memory\n");
        exit(1);
    }
    printf("input two integers : ");
    scanf("%f %f",&x, &y);
    get_calc_result(x, y);
    printf("%f + %f = %f\n", x, y, p->sum);
    printf("%f - %f = %f\n", x, y, p->difference);
    printf("%f * %f = %f\n", x, y, p->product);
    printf("%f / %f = %f\n", x, y, p->quotient);
    free(p);
    return 0;
}