#include <stdio.h>

int i = 0, *ip;
char c = 0, *cp;

int main()
{
    ip = &i;
    cp = &c;
    printf("ip: %p\n", ip);
    printf("++ip: %p\n", ++ip);
    printf("cp: %p\n", cp);
    printf("++cp: %p\n", ++cp);
    return 0;
}