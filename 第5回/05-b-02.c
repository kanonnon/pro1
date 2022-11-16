#include <stdio.h>

struct mydate {
    int year;
    int month;
    int day;
} today, tomorrow_date;

void printdate(struct mydate today)
{
    printf("Today is %04d/%02d/%02d\n", today.year, today.month, today.day);
}

struct mydate tomorrow(struct mydate date)
{
    switch(date.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if (date.day == 31) {
                date.day = 1;
                date.month += 1;
            } else {
                date.day += 1;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (date.day == 30) {
                date.day = 1;
                date.month += 1;
            } else {
                date.day += 1;
            }
            break;
        case 12:
            if (date.day == 31) {
                date.day = 1;
                date.month = 1;
                date.year += 1;
            } else {
                date.day += 1;
            }
            break;
        case 2:
            if (date.day == 29) {
                date.day = 1;
                date.month += 1;
            } else if (date.day == 28) {
                if (date.year % 400 == 0) {
                    date.day += 1;
                } else if (date.year % 4 == 0 && date.year % 100 != 0) {
                    date.day += 1;
                } else {
                    date.day = 1;
                    date.month += 1;
                }
            } else {
                date.day += 1;
            }
            break;
    }
    return date;
}

int main()
{
    scanf("%d %d %d", &(today.year), &(today.month), &(today.day));
    printdate(today);
    tomorrow_date = tomorrow(today);
    printf("Tomorrow is %04d/%02d/%02d\n", tomorrow_date.year, tomorrow_date.month, tomorrow_date.day);
    return 0;
}