#include "lib64.h"
#include <stdio.h>

int main()
{
	int i, j, k, l, nx, ny;
    int r[256] = {0}, g[256] = {0}, b[256] = {0}, brightness, r_max = 0, g_max = 0, b_max = 0;
	BMPIMAGE im, im_r, im_g, im_b;                      
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

	im = Input_BMP(filename);
	if (im == 0)
	{
		printf("No such file as '%s'\n", filename);
		exit(0);
	}

	ny = im->height; nx = im->width;   

	inputimageR = f2d(ny, nx);  
	outimageR = f2d(ny, nx);    
	inputimageG = f2d(ny, nx);  
	outimageG = f2d(ny, nx);    
	inputimageB = f2d(ny, nx);  
	outimageB = f2d(ny, nx);    

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
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
            brightness = (int)inputimageR[i][j];
			r[brightness]++;
            brightness = (int)inputimageG[i][j];
            g[brightness]++;
            brightness = (int)inputimageB[i][j];
            b[brightness]++;
		}
	}
    for (i = 0; i < 256; i++) {
        if (r[i] > r_max) {
            r_max = r[i];
        }
        if (g[i] > g_max) {
            g_max = g[i];
        }
        if (b[i] > b_max) {
            b_max = b[i];
        }
    }
    for (j = 0; j < nx; j++) {
        for (i = 0; i < (int)((float)r[j] / r_max * 255); i++) {
            outimageR[ny - 1 - i][j] = 255;
        }
        for (i = 0; i < (int)((float)g[j] / g_max * 255); i++) {
            outimageG[ny - 1 - i][j] = 255;
        }
        for (i = 0; i < (int)((float)b[j] / b_max * 255); i++) {
            outimageB[ny - 1 - i][j] = 255;
        }
    }
    /////////////////////////////////////////////////////////////////////////////
	im_r = Generate_BMP(filename, ny, nx);
    im_g = Generate_BMP(filename, ny, nx);
    im_b = Generate_BMP(filename, ny, nx);

	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageB[i][j] > 255.0) outimageB[i][j] = 255.0;
			if (outimageB[i][j] < 0.0) outimageB[i][j] = 0.0;
			im_b->blue[i][j] = (unsigned char)(outimageB[i][j]);
		}
	}

	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageR[i][j] > 255.0) outimageR[i][j] = 255.0;
			if (outimageR[i][j] < 0.0) outimageR[i][j] = 0.0;
			im_r->red[i][j] = (unsigned char)(outimageR[i][j]);
		}
	}
	for (i = 0; i < ny; i++) {
		for (j = 0; j < nx; j++) {
			if (outimageG[i][j] > 255.0) outimageG[i][j] = 255.0;
			if (outimageG[i][j] < 0.0) outimageG[i][j] = 0.0;
			im_g->green[i][j] = (unsigned char)(outimageG[i][j]);
		}
	}

	printf("Red Histogram Filename (BMP)  = ");
	scanf("%s", filename,500);
	getchar();
	Output_BMP(im_r, filename);
    printf("Green Histogram Filename (BMP)  = ");
	scanf("%s", filename,500);
	getchar();
	Output_BMP(im_g, filename);
    printf("Blue Histogram Filename (BMP)  = ");
	scanf("%s", filename,500);
	getchar();
	Output_BMP(im_b, filename);
}


