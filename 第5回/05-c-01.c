#include <stdio.h>
#include <math.h>

struct point {
    float x;
    float y;
    float z;
} point_list[20];

struct max_area_three_point {
    struct point max_area_point_a;
    struct point max_area_point_b;
    struct point max_area_point_c;
} max_area_point_list[20];

int main()
{
    int count, i, j, a, b, c;
    float max_area = 0;
    printf("Input N : ");
    scanf("%d", &count);

    // N個の点を入力する
    for (i = 0; i < count; i++) {
        printf("Input (x, y, z) : ");
        scanf("%f %f %f", &(point_list[i].x), &(point_list[i].y), &(point_list[i].z));
    }

    i = 0;
    for (a = 0; a < count - 2; a++) {
        for (b = a + 1; b < count - 1; b++) {
            for (c = b + 1; c < count; c++) {
                // 3点を選ぶ
                struct point point_a = point_list[a];
                struct point point_b = point_list[b];
                struct point point_c = point_list[c];

                // 面積を求める
                struct point ab_vector = {(point_b.x - point_a.x), (point_b.y - point_a.y), (point_b.z - point_a.z)};
                struct point ac_vector = {(point_c.x - point_a.x), (point_c.y - point_a.y), (point_c.z - point_a.z)};
                float ab_ab = ab_vector.x * ab_vector.x + ab_vector.y * ab_vector.y + ab_vector.z * ab_vector.z;
                float ac_ac = ac_vector.x * ac_vector.x + ac_vector.y * ac_vector.y + ac_vector.z * ac_vector.z;
                float ab_ac = ab_vector.x * ac_vector.x + ab_vector.y * ac_vector.y + ab_vector.z * ac_vector.z;
                float area = sqrt(ab_ab * ac_ac - ab_ac * ab_ac) / 2;

                // 最大の面積かどうか確かめる
                if (area > max_area + 0.00001) {
                    // 最大の面積が新しいとき
                    max_area = area;
                    for (j = 1; j <= i; j++) {
                        max_area_point_list[j].max_area_point_a.x = 0;
                        max_area_point_list[j].max_area_point_b.x = 0;
                        max_area_point_list[j].max_area_point_c.x = 0;
                        max_area_point_list[j].max_area_point_a.y = 0;
                        max_area_point_list[j].max_area_point_b.y = 0;
                        max_area_point_list[j].max_area_point_c.y = 0;
                    }
                    max_area_point_list[0].max_area_point_a.x = point_a.x;
                    max_area_point_list[0].max_area_point_b.x = point_b.x;
                    max_area_point_list[0].max_area_point_c.x = point_c.x;
                    max_area_point_list[0].max_area_point_a.y = point_a.y;
                    max_area_point_list[0].max_area_point_b.y = point_b.y;
                    max_area_point_list[0].max_area_point_c.y = point_c.y;
                    max_area_point_list[0].max_area_point_a.z = point_a.z;
                    max_area_point_list[0].max_area_point_b.z = point_b.z;
                    max_area_point_list[0].max_area_point_c.z = point_c.z;
                    i = 0;
                } else if (fabsf(area - max_area) <= 0.00001) {
                    // 最大の面積が同一のとき
                    i++;
                    max_area_point_list[i].max_area_point_a.x = point_a.x;
                    max_area_point_list[i].max_area_point_b.x = point_b.x;
                    max_area_point_list[i].max_area_point_c.x = point_c.x;
                    max_area_point_list[i].max_area_point_a.y = point_a.y;
                    max_area_point_list[i].max_area_point_b.y = point_b.y;
                    max_area_point_list[i].max_area_point_c.y = point_c.y;
                    max_area_point_list[i].max_area_point_a.z = point_a.z;
                    max_area_point_list[i].max_area_point_b.z = point_b.z;
                    max_area_point_list[i].max_area_point_c.z = point_c.z;
                }
                // printf("Points : (%f, %f, %f), (%f, %f, %f), (%f, %f, %f)\n", point_a.x, point_a.y, point_a.z, point_b.x, point_b.y, point_b.z, point_c.x, point_c.y, point_c.z);
                // printf("%f\n", area);
            }
        }
    }

    // 結果を表示する
    printf("Max area : %f\n", max_area);
    for (j = 0; j <= i; j++) {
        struct point a = max_area_point_list[j].max_area_point_a;
        struct point b = max_area_point_list[j].max_area_point_b;
        struct point c = max_area_point_list[j].max_area_point_c;
        if (!(a.x == 0 && b.x == 0 && c.x == 0 && a.y == 0 && b.y == 0 && c.y == 0)) {
            printf("Points : (%f, %f, %f), (%f, %f, %f), (%f, %f, %f)\n", a.x, a.y, a.z, b.x, b.y, b.z, c.x, c.y, c.z);
        }
    }
}