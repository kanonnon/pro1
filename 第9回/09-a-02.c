#include <stdio.h>

int main()
{
    int i, j, c, array[20], check = 0;
    for (i = 0; (c = getchar()) != 10; i++) {
        array[i] =  c;
    }
    i--;
    for (j = 0; j <= i; i--, j++) {
        if (array[i] != array[j]) {
            check = 1;
            break;
        }
    }
    if (check == 0) {
        printf("This str is a palindrome\n");
    } else {
        printf("This str isn't a palindrome\n");
    }
    return 0;
}