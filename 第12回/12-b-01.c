#include "lib64.h"
#include <stdio.h>

int main()
{
	int i, j, k, l, nx, ny;
	BMPIMAGE im;
	float** inputimage1R;
    float** inputimage2R;
	float** outimageR;
	float** inputimage1G;
    float** inputimage2G;
	float** outimageG;
	float** inputimage1B;
    float** inputimage2B;
	float** outimageB;

	char filename1[512], filename2[512];
	printf("Sample Program for Filtering \n");
	printf("Input Image Filename 1 (BMP) = ");
	scanf("%s", filename1, 500);
	getchar();
    printf("Input Image Filename 2 (BMP) = ");
	scanf("%s", filename2, 500);
	getchar();

	// BMP画像を指定したファイルから読み込む
	im = Input_BMP(filename1);
	if (im == 0)
	{
		printf("No such file as '%s'\n", filename1);
		exit(0);
	}

	ny = im->height; nx = im->width;   // 画像サイズを読み込んだ画像情報から獲得

	inputimage1R = f2d(ny, nx);
    inputimage2R = f2d(ny, nx);
	outimageR = f2d(ny, nx);
	inputimage1G = f2d(ny, nx);
    inputimage2G = f2d(ny, nx);
	outimageG = f2d(ny, nx);
	inputimage1B = f2d(ny, nx);
    inputimage2B = f2d(ny, nx);
	outimageB = f2d(ny, nx);

	// 画像の画素値をfloat型の2次元配列にコピー（処理のため）
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimage1R[i][j] = (float)im->red[i][j];
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimage1G[i][j] = (float)im->green[i][j];
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimage1B[i][j] = (float)im->blue[i][j];

    im = Input_BMP(filename2);
	if (im == 0)
	{
		printf("No such file as '%s'\n", filename2);
		exit(0);
	}
    for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimage2R[i][j] = (float)im->red[i][j];
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimage2G[i][j] = (float)im->green[i][j];
	for (i = 0; i < ny; i++)
		for (j = 0; j < nx; j++)
			inputimage2B[i][j] = (float)im->blue[i][j];
	/////////////////////////////////////////////////////////////////////
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			outimageR[i][j] = inputimage1R[i][j] + inputimage2R[i][j];
			outimageG[i][j] = inputimage1G[i][j] + inputimage2G[i][j];
			outimageB[i][j] = inputimage1B[i][j] + inputimage2B[i][j];
		}
	}/////////////////////////////////////////////////////////////////////////////
	
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
	scanf("%s", filename1 ,500);
	getchar();
	Output_BMP(im, filename1);
}
