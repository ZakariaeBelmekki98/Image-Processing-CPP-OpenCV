#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace cv;

/*
 * struct to store an image in RGB contiguous arrays.
 *
 * */

typedef struct {
	double *R;
	double *G;
	double *B;
	size_t width, height;
} RGB_IMG; 

typedef struct {
	double *GS;
	size_t width, height;

} GRAY_IMG;



/*
 * Allocates memory to an RGB_IMG struct.
 * 	ARGUMENTS:
 * 		double width: width of the RGB components matrices.
 * 		double height: height of the RGB components matrices.
 * */

void malloc_RGB_IMG(RGB_IMG * img, size_t width, size_t height);



/*
 * Allocate memory to a GRAY_IMG struct.
 * 	ARGUMENTS:
 * 	GRAY_IMG *img: pointer to a GRAY_IMG struct object.
 * 	size_t width: width of the image to be allocated.
 * 	size_t height: height of the image to be allocated.
 *
 * */

void malloc_GRAY_IMG(GRAY_IMG *img, size_t width, size_t height);


/*
 * Export RGB_IMG to .DAT file.
 * 	ARGUMENTS: 
 * 		RGB_IMG *img: pointer to the RGB_IMG object to be exported.
 * 		const char filename[]: name of the output file and location.
 *
 * */

void save_RGB_IMG(RGB_IMG *img, const char filename[]);


/*
 * Export GRAY_IMG to .DAT file.
 *	ARGUMENTS:
 *		GRAY_IMG *img: pointed to GRAY_IMG object to be exported.
 *		const char filename[]: name of the output file and location.
 *
 * */

void save_GRAY_IMG(GRAY_IMG *img, const char filename[]);


/*
 * Converts an RGB_IMG object to a GRAY_IMG object.
 * 	ARGUMENTS:
 * 		RGB_IMG *img: pointer to the RGB_IMG to be converted to GRAY_IMG.
 *
 * */

GRAY_IMG RGB_2_GRAY(RGB_IMG *img);



/*
 * Converts an JPEG image to a a RGB_IMG struct. Uses opencv to decompress
 *  JPEG and then store it in RGB_IMG. 
 *	ARGUMENTS:
 *		- const char filename[]: JPEG image location.
 *
 * */

RGB_IMG Img2RGB_IMG(const char filename[], size_t width, size_t height);




