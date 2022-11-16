#include <stdio.h>

#define STUDENT_MAX 10

struct student_data {
    int number, height, weight;
};

int main()
{
    int i;
    struct student_data data, tallest = {0, 0, 0}, shortest = {0, 100000, 0}, heaviest= {0, 0, 0}, lightest = {0, 0, 100000};
    for (i = 0; i < STUDENT_MAX; i++) {
        printf("Input student number, height, weight : ");
        scanf("%d %d %d", &(data.number), &(data.height), &(data.weight));
        if (data.number < 0 || data.height < 0 || data.weight < 0) {
            break;
        }
        if (tallest.height < data.height) {
            tallest.height = data.height;
            tallest.number = data.number;
        }
        if (shortest.height > data.height) {
            shortest.height = data.height;
            shortest.number = data.number;
        }
        if (heaviest.weight < data.weight) {
            heaviest.weight = data.weight;
            heaviest.number = data.number;
        }
        if (lightest.weight > data.weight) {
            lightest.weight = data.weight;
            lightest.number = data.number;
        }
    }
    printf("Tallest student number is %d (%dcm)\n", tallest.number, tallest.height);
    printf("Shortest student number is %d (%dcm)\n", shortest.number, shortest.height);
    printf("Heaviest student number is %d (%dkg)\n", heaviest.number, heaviest.weight);
    printf("Lightest student number is %d (%dkg)\n", lightest.number, lightest.weight);
    return 0;
}