#include <stdio.h>

float calc(float a, float b, char operator)
{
    if (operator == '+') {
        return a + b;
    }  if (operator == '-') {
        return a - b;
    } else if (operator == '*') {
        return a * b;
    } else if (operator == '/') {
        if (b == 0) {
            return 0;
        } else {
            return a / b;
        }
    } else {
        return 0;
    }
}

int main(void)
{
    float a = 1234, b = 5678;
    printf("%f + %f = %f\n", a, b, calc(a, b, '+'));
    printf("%f - %f = %f\n", a, b, calc(a, b, '-'));
    printf("%f * %f = %f\n", a, b, calc(a, b, '*'));
    printf("%f / %f = %f\n", a, b, calc(a, b, '/'));
    return 0;
}