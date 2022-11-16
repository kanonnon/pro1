#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score;
    printf("input your score: ");
    scanf("%d", &score);

    if (0 > score || score > 100) {
        printf("error: input from 0 to 100. \n");
    } else if (score >= 50) {
        printf("you passed the examination.\n");
    } else {
        printf("you failed the examination.\n");
    }
}