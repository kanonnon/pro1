#include "lib64.h"
#include <stdio.h>

int main()
{
	int i, j, k, l, nx, ny;
	BMPIMAGE im;                      // BMP画像の情報が入る変数
	float** inputimageR;
	float** outimageR;
	float** inputimageG;
	float** outimageG;
	float** inputimageB;
	float** outimageB;

	char filename[512];
	printf("Sample Program for Filtering \n");
	printf("Input Image Filename (BMP) = ");
	scanf("%s", filename,500);
	getchar();

	// BMP画像を指定したファイルから読み込む
	im = Input_BMP(filename);
	if (im == 0)
	{
		printf("No such file as '%s'\n", filename);
		exit(0);
	}

	ny = im->height; nx = im->width;   // 画像サイズを読み込んだ画像情報から獲得

	inputimageR = f2d(ny, nx);
	outimageR = f2d(ny, nx);
	inputimageG = f2d(ny, nx);
	outimageG = f2d(ny, nx);
	inputimageB = f2d(ny, nx);
	outimageB = f2d(ny, nx);

	// 画像の画素値をfloat型の2次元配列にコピー（処理のため）
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimageR[i][j] = (float)im->red[i][j];
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimageG[i][j] = (float)im->green[i][j];
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimageB[i][j] = (float)im->blue[i][j];
	/////////////////////////////////////////////////////////////////////
    int m, n, count;
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
            outimageR[i][j] = 0;
            for (m = -1; m < 2; m++) {
                for (n = -1; n < 2; n++) {
                    if (0 <= i + m && i + m < ny && 0 <= j + n && j + n < nx) {
                        if ((m == 0 && n == -1) || (m == 0 && n == 1) || (m == -1 && n == 0) || (m == 1 && n == 0)) {
                            outimageR[i][j] += inputimageR[i + m][j + n];
                        }
                        if (m == 0 && n == 0) {
                            outimageR[i][j] += inputimageR[i][j] * -4;
                        }
                    } else {
                        if ((m == 0 && n == -1) || (m == 0 && n == 1) || (m == -1 && n == 0) || (m == 1 && n == 0)) {
                            outimageR[i][j] += 255;
                        }
                    }
                }
            }
            outimageG[i][j] = 0;
            for (m = -1; m < 2; m++) {
                for (n = -1; n < 2; n++) {
                    if (0 <= i + m && i + m < ny && 0 <= j + n && j + n < nx) {
                        if ((m == 0 && n == -1) || (m == 0 && n == 1) || (m == -1 && n == 0) || (m == 1 && n == 0)) {
                            outimageG[i][j] += inputimageG[i + m][j + n];
                        }
                        if (m == 0 && n == 0) {
                            outimageG[i][j] += inputimageG[i][j] * -4;
                        }
                    } else {
                        if ((m == 0 && n == -1) || (m == 0 && n == 1) || (m == -1 && n == 0) || (m == 1 && n == 0)) {
                            outimageG[i][j] += 255;
                        }
                    }
                }
            }
            outimageB[i][j] = 0;
            for (m = -1; m < 2; m++) {
                for (n = -1; n < 2; n++) {
                    if (0 <= i + m && i + m < ny && 0 <= j + n && j + n < nx) {
                        if ((m == 0 && n == -1) || (m == 0 && n == 1) || (m == -1 && n == 0) || (m == 1 && n == 0)) {
                            outimageB[i][j] += inputimageB[i + m][j + n];
                        }
                        if (m == 0 && n == 0) {
                            outimageB[i][j] += inputimageB[i][j] * -4;
                        }
                    } else {
                        if ((m == 0 && n == -1) || (m == 0 && n == 1) || (m == -1 && n == 0) || (m == 1 && n == 0)) {
                            outimageB[i][j] += 255;
                        }
                    }
                }
            }
            if (outimageR[i][j] > 100 && outimageG[i][j] > 100 && outimageB[i][j] > 100) {
                count++;
            }
		}
	}
    /////////////////////////////////////////////////////////////////////////////
	
	if (count > nx * ny * 0.025) {
		printf("Is this a picture of a city streetscape?\n");
	} else {
		printf("Is this a picture of a landscape with the ocean reflected?\n");
	}
}