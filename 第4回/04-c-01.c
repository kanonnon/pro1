#include <stdio.h>

int main()
{
    int number, i, j, alphabet[100], result;
    char element;
    printf("Input shift num: ");
    scanf("%d", &number);
    printf("Input text: ");
    for (i = 0; ; i++) {
        scanf("%c", &element);
        alphabet[i] = element;
        if (i != 0 && !('a' <= element && element <= 'z')) {
            break;
        }
    }
    printf("Cipher text: ");
    for (j = 1; j < i; j++) {
        result = alphabet[j] + number;
        if (result < 97) {
            result += 26;
        } else if (122 < result) {
            result -= 26;
        }
        printf("%c", result);
    }
    printf("\n");
    return 0;
}