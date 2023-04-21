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
    int bayerpattern[] = {0, 8, 2, 10, 12, 4, 14, 6, 3, 11, 1, 9, 15, 7, 13, 5};
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
            if ((bayerpattern[(i % 4) * 4 + (j % 4)] * 16 + 8) <= inputimageR[i][j]) {
			    outimageR[i][j] = 255;
			    outimageG[i][j] = 255;
			    outimageB[i][j] = 255;
            } else {
                outimageR[i][j] = 0;
			    outimageG[i][j] = 0;
			    outimageB[i][j] = 0;
            }
		}
	}
    /////////////////////////////////////////////////////////////////////////////
	
	// float型の2次元配列からIMAGE構造体データにコピー
	// コピーする前に0以下の値は0に、255以上の値は255にしている
	// 同じ処理をRGBそれぞれについて繰り返している
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageB[i][j] > 255.0) outimageB[i][j] = 255.0;
			if (outimageB[i][j] < 0.0) outimageB[i][j] = 0.0;
			im->blue[i][j] = (unsigned char)(outimageB[i][j]);
		}
	}

	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageR[i][j] > 255.0) outimageR[i][j] = 255.0;
			if (outimageR[i][j] < 0.0) outimageR[i][j] = 0.0;
			im->red[i][j] = (unsigned char)(outimageR[i][j]);
		}
	}
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageG[i][j] > 255.0) outimageG[i][j] = 255.0;
			if (outimageG[i][j] < 0.0) outimageG[i][j] = 0.0;
			im->green[i][j] = (unsigned char)(outimageG[i][j]);
		}
	}
	// BMP画像としてファイルにセーブ
	printf("Output Image Filename (BMP)  = ");
	scanf("%s", filename,500);
	getchar();
	Output_BMP(im, filename);
}
