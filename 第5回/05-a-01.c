#include <stdio.h>

struct point {
    float x;
    float y;
};

int main()
{
    float a, b;
    struct point p1, p2;
    printf("input first point (x1 y1) : ");
    scanf("%f %f", &(p1.x), &(p1.y));
    printf("input first point (x2 y2) : ");
    scanf("%f %f", &(p2.x), &(p2.y));

    a = (p2.y - p1.y) / (p2.x - p1.x);
    b = p1.y - a * p1.x;
    printf("linear function : y  = %f x + %f\n", a, b);
    return 0;
}