#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include "libppm.h"
using namespace std;

int main(){
    string ppmInFile, ppmOutFile;
    PPM_header img_header;
    ifstream inFile;
    ofstream outFile;
    RGB_8 *img; //pointer to RGB_8 structure

    cout << "\n\nInput Image Name (in_image.ppm): ";
    cin >> ppmInFile;
    cout << "Output Image Name (out_image.ppm): ";
    cin >> ppmOutFile;

    //open the input image file in binary mode
    inFile.open(ppmInFile, ios::binary);
    if(!inFile.is_open()){
        cout << "Unable to open File: " << ppmInFile << endl;
        return 1;
    }

    //read the file and store in program
    PPM_read_header(inFile, img_header);
    cout << img_header << endl;
    img = new RGB_8[img_header.height * img_header.width];
    PPM_read_rgb_8(inFile, img_header.width, img_header.height, (RGB_8 *)img);

    //open the output file in binary mode
    outFile.open(ppmOutFile, ios::binary);
    if(!outFile.is_open()){
        cout << "Unable to open file: " << ppmOutFile << endl;
        return 1;
    }

    //grayscale the image
    toGrayScale(img, img_header.height, img_header.width);

    //flip da image lolll
    flip(img, img_header.height, img_header.width);

    //write the updated image to the output file
    PPM_write_header_8(outFile, img_header.width, img_header.height);
    PPM_write_rgb_8(outFile, img_header.width, img_header.height, (RGB_8 *)img);

    //close BOTH files
    inFile.close();
    outFile.close();

    return 0;
}