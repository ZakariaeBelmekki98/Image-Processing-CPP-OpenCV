#include "ImgProcUtils.h"

void malloc_RGB_IMG(RGB_IMG *img, size_t _width, size_t _height){
	if(_width == 0 || _height == 0){
		cout << "ImgProcUtils::init_RGB_IMG: Cannot allocate memory to arrays of size 0." << endl;
		exit(1);
	}
	
	img->height = _height;
	img->width = _width;
	img->R = (double*) malloc(sizeof(double)*_width*_height);
	img->G = (double*) malloc(sizeof(double)*_width*_height);
	img->B = (double*)malloc(sizeof(double)*_width*_height);

	if(img->R == NULL || img->G == NULL || img->B == NULL) {
		cout << "ImgProcUtils::init_RGB_IMG: Could not allocate memory to RGB_IMG object." << endl;
		exit(1);	
	} 
}

void malloc_GRAY_IMG(GRAY_IMG *img , size_t _width, size_t _height){
	if(_width == 0 || _height == 0){
		cout << "ImgProcUtils::init_GRAY_IMG: Cannot allocate memory to arrays of size 0." << endl;
		exit(1);
	}
	
	img->height = _height;
	img->width = _width;
	img->GS = (double*) malloc(sizeof(double)*_width*_height);

	if(img->GS == NULL) {
		cout << "ImgProcUtils::init_GRAY_IMG: Could not allocate memory to GRAY_IMG object." << endl;
		exit(1);	
	}

}

void save_RGB_IMG(RGB_IMG *img, const char filename[]){
	ofstream file(filename);
	if(file.is_open()){
		for(int i=0; i<img->height; i++){
			for(int j=0; j<img->width; j++){
				int idx = j + i * img->width;
				file << img->R[idx] << " " << img->G[idx] << " " << img->B[idx];
				if(j <img->width-1) file << " ";
			}
			file << "\n";
		}
		file.close();
	}
	else cout << "ImgProcUtils::save_RGB_IMG(): Could not open file :" << filename << endl;

}

void save_GRAY_IMG(GRAY_IMG *img, const char filename[]){
	ofstream file(filename);
	if(file.is_open()){
		for(int i=0; i<img->height; i++) {
			for(int j=0; j<img->width; j++) {
				file << img->GS[j+i*img->width];
				if(j<img->width-1) file << " ";
			}
			file << "\n";
		}
		file.close();
	}
	else cout << "ImgProcUtils::save_GRAY_IMG(): Could not open file :" << filename << endl;

}

GRAY_IMG RGB_2_GRAY(RGB_IMG *img){
	// allocate memory to GRAY_IMG object
	GRAY_IMG gray_img;
	malloc_GRAY_IMG(&gray_img, img->width, img->height);

	// Compute grayscale from RGB values
	for(int i=0; i<img->height; i++){
		for(int j=0; j<img->width; j++){
			int idx1 = j+ i*img->width;
			gray_img.GS[idx1] = img->R[idx1] * 0.3 + img->G[idx1] * 0.59 + img->B[idx1] * 0.11;
		}
	}
	return gray_img;
}

RGB_IMG Img2RGB_IMG(const char filename[], size_t width, size_t height){
	// Load and resize image into a cv::Mat object
	Mat img = imread(filename, cv::IMREAD_COLOR);
	if(img.empty()){
		cout << "ImgProcUtils::Img2Arr: Could not read image : " << filename << endl;
	       	exit(1);
	}
	Mat img_resized;
	resize(img, img_resized, Size(width, height), INTER_NEAREST);
	int channels = img_resized.channels();  
	
	// store pixel values in an RGB_IMG object 
	RGB_IMG img_arr;
	malloc_RGB_IMG(&img_arr, width, height);	
	for(int i=0; i< img_resized.rows; i++){
		for(int j=0; j < img_resized.cols; j++){
			int idx1 = j * channels + i * img_resized.cols * channels;
			int idx2 = j + i *img_resized.cols;
			img_arr.R[idx2] = (double)img_resized.data[idx1 + 2];
			img_arr.G[idx2] = (double)img_resized.data[idx1 + 1];
			img_arr.B[idx2] = (double)img_resized.data[idx1];
		}
	}
	return img_arr;
}
