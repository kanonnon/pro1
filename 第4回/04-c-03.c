#include <stdio.h>

int x = 8, i, score = 0;

int myrand()
{
    x = (13 * x + 5) % 24;
    return x % 5 + 1;
}

void game(int random)
{
    int input;
    printf("Please expect a number (1 to 5) : ");
    scanf("%d", &input);
    printf("your expection: %d, random number: %d\n", input, random);
    if (random == input) {
        score++;
        printf("Correct! your score: %d\n", score);
    } else {
        printf("Incorrect. your score: %d\n", score);
    }

}

int main()
{
    for (i = 0; i < 10; i++) {
        game(myrand());
        if (score == 3) {
            printf("Clear!\n");
            break;
        }
        printf("remaining : %d\n", 10 - i - 1);
        if (i == 9) {
            printf("Game over.\n");
        }
    }
}