#include <stdio.h>

int main()
{
    char ans;
    while (1) {
        printf("Please help me!\ninput y or n : ");
        rewind(stdin);  // キーボードバッファをクリア
        scanf("%c", &ans);
        if (ans == 'y') {
            break;
        }
        printf("Huh?\n");
    }
    printf("Thank you!\n");
    return 0;
}