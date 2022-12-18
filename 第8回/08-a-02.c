#include <stdio.h>

int main()
{
    int year, month;
    printf("input year, month : ");
    scanf("%d %d", &year, &month);
    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        printf("This month has thirty-one days\n");
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("This month has thirty days\n");
        break;
    case 2:
        switch (year % 4) {
        case 0:
            if (year % 100 == 0 && year % 400 != 0) {
                printf("This month has twenty-eight days\n");
            } else {
                printf("This month has twenty-nine days\n");
            }
            break;
        default: 
            printf("This month has twenty-eight days\n");
            break;
        }
        break;
    }
    return 0;
}