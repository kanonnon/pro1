#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number, thousand, hundred, ten, one;
    char result;
    printf("input an integer: ");
    scanf("%d", &number);

    if (0 <= number && number <= 9999) {
        thousand = number / 1000;
        hundred = (number - thousand * 1000) / 100;
        ten = (number - thousand * 1000 - hundred * 100) / 10;
        one = number - thousand * 1000 - hundred * 100 - ten * 10;

        if (thousand != 0) {
            if (hundred != 0) {
                if (ten != 0) {
                    if (one != 0) {
                        printf("%d = %d × 1000 + %d × 100 + %d × 10 + %d\n", number, thousand, hundred, ten, one);
                    } else {
                        printf("%d = %d × 1000 + %d × 100 + %d × 10\n", number, thousand, hundred, ten);
                    }
                } else {
                    if (one != 0) {
                        printf("%d = %d × 1000 + %d × 100 + %d\n", number, thousand, hundred, one);
                    } else {
                        printf("%d = %d × 1000 + %d × 100\n", number, thousand, hundred);
                    }
                }
            } else {
                if (ten != 0) {
                    if (one != 0) {
                        printf("%d = %d × 1000 + %d × 10 + %d\n", number, thousand, ten, one);
                    }  else {
                        printf("%d = %d × 1000 + %d × 10\n", number, thousand, ten);
                    }
                } else {
                    if (one != 0) {
                        printf("%d = %d × 1000 + %d\n", number, thousand, one);
                    } else {
                        printf("%d = %d × 1000\n", number, thousand);
                    }
                }
            }
        } else {
            if (hundred != 0) {
                if (ten != 0) {
                    if (one != 0) {
                        printf("%d = %d × 100 + %d × 10 + %d\n", number, hundred, ten, one);
                    } else {
                        printf("%d = %d × 100 + %d × 10\n", number, hundred, ten);
                    }
                } else {
                    if (one != 0) {
                        printf("%d = %d × 100 + %d\n", number, hundred, one);
                    } else {
                        printf("%d = %d × 100\n", number, hundred);
                    }
                }
            } else {
                if (ten != 0) {
                    if (one != 0) {
                        printf("%d = %d × 10 + %d\n", number, ten, one);
                    }  else {
                        printf("%d = %d × 10\n", number, ten);
                    }
                } else {
                    if (one != 0) {
                        printf("%d = %d\n", number, one);
                    } else {
                        printf("0 = 0\n");
                    }
                }
            }
        }
    } else {
        printf("Incorrect input.\n");
    }
}