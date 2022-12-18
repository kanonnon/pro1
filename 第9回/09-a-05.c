#include <stdio.h>

void disp_array(int array[][4])
{
    int i, j;
    for (j = 0; j < 3; j++) {
        for (i = 0; i < 4; i++) {
            printf("%d ", array[j][i]);
        }
        printf("\n");
    }
}

int main()
{
    int array[3][4] = { {11,12,13,14},
                        {15,16,17,18},
                        {19,20,21,22} };
    disp_array(array);
    return 0;
}