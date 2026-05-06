
//libppm.cpp given file

#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "libppm.h"

/*************************************************************************
	Function: PPM_read_header()
	Purpose:  Reads the header of a PPM (P6) image file.
			  Ensures the magic number is correct and extracts width, 
			       height, and max color value.
			  Throws an error if the magic number is incorrect.
	Input: 	  File stream object and a reference to a PPM_header struct var
	Returns:  void
**************************************************************************/
void PPM_read_header(ifstream &inp, PPM_header &ppm_header) {
	char ppm_magic_1, ppm_magic_2;
	int width;
	int height;
	int max_color;
	char space;
	
	inp >> ppm_magic_1;
	inp >> ppm_magic_2;
	
	if (ppm_magic_1 != PPM_MAGIC_1 || ppm_magic_2 != PPM_MAGIC_2) {
		cout << "File does not begin with PPM magic number";
		return;
	}
	
	inp >> width;
	ppm_header.width = width;
	
	inp >> height;
	ppm_header.height = height;

	inp >> max_color;
	ppm_header.max_color = max_color;

	//inp >> space;		// finish the header
	inp.read(&space, 1);

	return;
}

/*************************************************************************
	Function: overloaded << operator 
	Purpose:  Print an RGB_8 struct as "R G B" values.
**************************************************************************/
ostream &operator<<(ostream &os, const RGB_8 &rgb) {
	os << (int) rgb.r << " " << (int) rgb.g << " " << (int) rgb.b;
	return os;
}

/*************************************************************************
	Function: PPM_read_rgb_8()
	Purpose:  Reads the RGB pixel data from a binary PPM (P6) image file 
	          into an array.
			  Throws an error if the read operation fails.
	Input: 	  File stream object, integers for width & height, 
	          and a pointer to RGB_8 struct var
	Returns:  void
**************************************************************************/
void PPM_read_rgb_8(ifstream &inp, int width, int height, RGB_8 *img) {
  inp.read((char *)img, sizeof(RGB_8)*width*height);
  if (!inp) {
    stringstream ss;
    ss << "error: only " << inp.gcount() << " could be read";
    throw runtime_error(ss.str());		
  }
}

/*************************************************************************
	Function: PPM_write_header_8
	Purpose:  Writes the header for a PPM (P6) image file.
			  Includes magic number, width, height, and maximum 
			       color value.
	Input: 	  File stream object, integers for width & height, 
	Returns:  void
**************************************************************************/
void PPM_write_header_8(ofstream &outp, int width, int height) {
  // write the header
  outp << PPM_MAGIC_1 << PPM_MAGIC_2 << (char) 10 << width << (char) 10 
       << height << (char) 10 << 255 << (char) 10;
}


/*************************************************************************
	Function: PPM_write_rgb_8
	Purpose:  Writes RGB pixel data to a binary PPM (P6) image file.
			  Throws an error if the write operation fails.
	Input: 	  File stream object, integers for width & height, 
	               and a pointer to a RGB_8 structure variable
	Returns:  void
**************************************************************************/
void PPM_write_rgb_8(ofstream &outp, int width, int height, RGB_8 *img) {	
	// write the image
	outp.write((char *)img, sizeof(RGB_8) * width * height);
	if (!outp) {
	  stringstream ss;
	  ss << "error: only " << outp.tellp() << " could be written";
	  throw runtime_error(ss.str());		
	}

}

/*************************************************************************
	Function: overloaded << operator 
	Purpose:  Print the PPM header information.
	          Displays width, height, and max color value.
**************************************************************************/
ostream &operator<<(ostream &os, const PPM_header &header) {
	os << header.width << " " << header.height << " " << header.max_color;
	return os;
}

/*************************************************************************
	Function: toGrayscale()
	Purpose:  Convert the image to grayscale using the luminosity method,
	          which re-calculates the red, green, and blue values 
			  according to the following formula:
			            grayval = 0.21*red + 0.72*green + 0.07*blue
			  The color called grayval is repeated as the red, green, and 
			  blue component for that pixel in the image.
**************************************************************************/
void toGrayScale(RGB_8 *img, int height, int width) {
	int index;
	unsigned char grayval;
	
	for(int row=0; row<height; row++) {
		for(int col=0; col<width; col++) {
			index = row*width+col;
			
			grayval = static_cast<unsigned char>(
                0.21 * static_cast<unsigned char>(img[index].r) +
                0.72 * static_cast<unsigned char>(img[index].g) +
                0.07 * static_cast<unsigned char>(img[index].b));
			img[index].r = grayval;
            img[index].g = grayval;
            img[index].b = grayval;
		}
	}
	
}


/*************************************************************************
	Function: flip()
	Purpose:  Flips an image horizontally, mirroring it from left to right.
	Input:    Pointer to RGB_8 image data, image width, image height
	Returns:  void
**************************************************************************/
void flip(RGB_8 *img, int height, int width) {
	int left_index, right_index;
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width / 2; col++) {
            left_index = row * width + col;
            right_index = row * width + (width - col - 1);
            swap(img[left_index], img[right_index]);
        }
    }
}


