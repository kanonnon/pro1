#include <stdio.h>

int x_range, y_range, count = 0, total = 0, min = 10000;
int array[10][10], status[10][10] = {0};

void search(int x, int y)
{
    int i, j, check = 0; // 上下左右どこにも動かなかったらminを-1にする
    // printf("x: %d, y: %d, num: %d, count: %d\n", x, y, array[y][x], count);
    status[y][x] = 1;
    if (array[y][x] == 8) {
        total = count;
        if (total < min || min == -1) {
            min = total;
        }
        count = 0;
        check = 1;
        status[y][x] = 0;
        return;
    }
    // 右に動くことを考える
    if (x + 1 <= x_range - 1 && array[y][x + 1] != 0 && status[y][x + 1] != 1) {
        count++;
        check = 1;
        search(x + 1, y);
    }
    // 左に動くことを考える
    if (x - 1 >= 0 && array[y][x - 1] != 0 && status[y][x - 1] != 1) {
        count++;
        check = 1;
        search(x - 1, y);
    }
    // 上に動くことを考える
    if (y - 1 >= 0 && array[y - 1][x] != 0 && status[y - 1][x] != 1) {
        count++;
        check = 1;
        search(x, y - 1);
    }
    // 下に動くことを考える
    if (y + 1 <= y_range - 1 && array[y + 1][x] != 0 && status[y + 1][x] != 1) {
        count++;
        check = 1;
        search(x, y + 1);
    }
    if (check == 0) {
        count -= 1;
        min = -1;
        return;
    }
}

int main()
{
    int start_x, start_y, i, j;
    printf("Input H W : ");
    scanf("%d %d", &y_range, &x_range);
    for (j = 0; j < y_range; j++) {
        for (i = 0; i < x_range; i++){
            scanf("%d", &(array[j][i]));
            if (array[j][i] == 5) {
                start_x = i;
                start_y = j;
            }
        }
    }
    search(start_x, start_y);
    printf("Minimum move count is %d\n", min);
    return 0;
}