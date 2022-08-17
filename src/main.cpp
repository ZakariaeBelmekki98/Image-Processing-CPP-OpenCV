#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <stdlib.h>

#include "ImgProcUtils.h"

#define SHOW_IMG_SHELL "python pyscript/show_img.py "
#define RGB " RGB"
#define GRAY " GRAY"

using namespace std;

int main(){
	RGB_IMG img = Img2RGB_IMG("data/141.png", 32, 32);
	save_RGB_IMG(&img, "data/rgb_img.dat");
	GRAY_IMG gray_img = RGB_2_GRAY(&img);
	save_GRAY_IMG(&gray_img, "data/gray_img.dat");	
	
	char buffer[256];
	strcpy(buffer, SHOW_IMG_SHELL);
	strcat(buffer, "gray_img.dat");
	strcat(buffer, GRAY);

	system(buffer);
	return 0;
}
