
//libppm.h given file

#pragma once
#include <iostream>
using namespace std;

const char PPM_MAGIC_1='P';
const char PPM_MAGIC_2='6';

struct PPM_header {
	int width;
	int height;
	int max_color;
}; 
struct RGB_8 {
	char r;
	char g;
	char b;
};

void PPM_read_header(ifstream &inp, PPM_header &ppm_header);
ostream &operator<<(ostream &os, const RGB_8 &rgb);
void PPM_read_rgb_8(ifstream &inp, int width, int height, RGB_8 *img);
void PPM_write_header_8(ofstream &outp, int width, int height);
void PPM_write_rgb_8(ofstream &outp, int width, int height, RGB_8 *img);
ostream &operator<<(ostream &os, const PPM_header &header);
void toGrayScale(RGB_8 *img, int width, int height);
void flip(RGB_8 *img, int width, int height);
