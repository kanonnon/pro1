#include <stdio.h>

struct mydate {
    int year;
    int month;
    int day;
} date;

void printdate(struct mydate date)
{
    printf("%04d/%02d/%02d\n", date.year, date.month, date.day);
}

int main()
{
    scanf("%d %d %d", &(date.year), &(date.month), &(date.day));
    printdate(date);
    return 0;
}