#include <stdio.h>
#include <math.h>

void sankakukei(float x1, float y1, float x2, float y2, float x3, float y3)
{
    float length1, length2, length3;
    length1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    length2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    length3 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    if (length1 == length2 && length2 == length3) {
        printf("sei_sankakukei\n");
    } else if (length1 == length2 || length2 == length3 || length3 == length1) {
        printf("nitouhen_sankakukei\n");
    } else {
        printf("sankakukei\n");
    }
}

void sikakukei(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
    float length1, length2, length3, length4, length5, length6, gradient1, gradient2, gradient3, gradient4;
    length1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    length2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    length3 = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
    length4 = sqrt((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1));
    length5 = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
    length6 = sqrt((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2));
    gradient1 = (y2 - y1) / (x2 - x1);
    gradient2 = (y3 - y2) / (x3 - x2);
    gradient3 = (y4 - y3) / (x4 - x3);
    gradient4 = (y1 - y4) / (x1 - x4);
    if (length1 == length2 && length1 == length3 && length1 == length4) {
        if (length5 == length6) {
            printf("seihoukei\n");
        } else {
            printf("hisigaka\n");
        }
    } else if (gradient1 == gradient3 && gradient2 == gradient4) {
        printf("heikousihenkei\n");
    } else if (gradient1 == gradient3 || gradient2 == gradient4) {
        printf("daikei\n");
    } else {
        printf("sikakukei\n");
    }
}

void gokakukei(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4, float x5, float y5)
{
    float length1, length2, length3, length4, length5;
    length1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    length2 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    length3 = sqrt((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4));
    length4 = sqrt((x4 - x5) * (x4 - x5) + (y4 - y5) * (y4 - y5));
    length5 = sqrt((x5 - x1) * (x5 - x1) + (y5 - y1) * (y5 - y1));
    if (length1 == length2 && length1 == length3 && length1 == length4 && length1 == length5) {
        printf("sei_gokakukei\n");
    } else {
        printf("gokakukei\n");
    }
}

int main()
{
    int i;
    float x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, array[5][2];
    printf("Input x,y:\n");
    for (i = 0; i < 5; i++) {
        if (scanf("%f %f", &(array[i][0]), &(array[i][1])) == EOF) {
            break;
        }
    }
    x1 = array[0][0];
    y1 = array[0][1];
    x2 = array[1][0];
    y2 = array[1][1];
    x3 = array[2][0];
    y3 = array[2][1];
    x4 = array[3][0];
    y4 = array[3][1];
    x5 = array[4][0];
    y5 = array[4][1];
    switch (i) {
        case 1:
            printf("ten\n");
            break;
        case 2:
            printf("tyokusen\n");
            break;
        case 3:
            if ((y3 - y1) / (x3 - x1) == (y2 - y1) / (x2 - x1)) {
                printf("tyokusen\n");
                break;
            }
            sankakukei(x1, y1, x2, y2, x3, y3);
            break;
        case 4:
            if ((y3 - y1) / (x3 - x1) == (y2 - y1) / (x2 - x1) && (y4 - y1) / (x4 - x1) == (y2 - y1) / (x2 - x1)) {
                printf("tyokusen\n");
                break;
            } else if ((y3 - y1) / (x3 - x1) == (y2 - y1) / (x2 - x1)) {
                sankakukei(x1, y1, x3, y3, x4, y4);
                break;
            } else if ((y4 - y2) / (x4 - x2) == (y3 - y2) / (x3 - x2)) {
                sankakukei(x1, y1, x2, y2, x4, y4);
                break;
            }
            sikakukei(x1, y1, x2, y2, x3, y3, x4, y4);
            break;
        case 5:
            if ((y3 - y1) / (x3 - x1) == (y2 - y1) / (x2 - x1) && (y4 - y1) / (x4 - x1) == (y2 - y1) / (x2 - x1) && (y5 - y1) / (x5 - x1) == (y2 - y1) / (x2 - x1)) {
                printf("tyokusen\n");
                break;
            } else if ((y3 - y1) / (x3 - x1) == (y2 - y1) / (x2 - x1) && (y4 - y1) / (x4 - x1) == (y2 - y1) / (x2 - x1)) {
                sankakukei(x1, y1, x4, y4, x5, y5);
                break;
            } else if ((y4 - y2) / (x4 - x2) == (y3 - y2) / (x3 - x2) && (y5 - y2) / (x5 - x2) == (y3 - y2) / (x3 - x2)) {
                sankakukei(x1, y1, x2, y2, x5, y5);
                break;
            } else if ((y3 - y1) / (x3 - x1) == (y2 - y1) / (x2 - x1)) {
                sikakukei(x1, y1, x3, y3, x4, y4, x5, y5);
                break;
            } else if ((y4 - y2) / (x4 - x2) == (y3 - y2) / (x3 - x2)) {
                sikakukei(x1, y1, x2, y2, x4, y4, x5, y5);
                break;
            } else if ((y5 - y3) / (x5 - x3) == (y4 - y3) / (x4 - x3)) {
                sikakukei(x1, y1, x2, y2, x3, y3, x5, y5);
                break;
            }
            gokakukei(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5);
            break;
            }
    return 0;
}