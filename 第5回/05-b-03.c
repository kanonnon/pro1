#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
};

struct circle {
    struct point point;
    float radius;
};

int circle_intersect(struct circle a, struct circle b)
{
    float sum, difference, d, x, y;
    sum = a.radius + b.radius;
    difference = fabsf(a.radius - b.radius);
    x = a.point.x - b.point.x;
    y = a.point.y - b.point.y;
    d = sqrt(x*x + y*y);
    if (difference < d && d < sum) {
        return 2;
    } else if (d == sum || d == difference) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    int count;
    struct circle a_circle, b_circle;
    printf("Input 1st Circle(x, y, r) : ");
    scanf("%f %f %f", &(a_circle.point.x), &(a_circle.point.y), &(a_circle.radius));
    printf("Input 2nd Circle(x, y, r) : ");
    scanf("%f %f %f", &(b_circle.point.x), &(b_circle.point.y), &(b_circle.radius));
    count = circle_intersect(a_circle, b_circle);
    printf("Circles have %d intersect point\n", count);
    return 0;
}