#include <iostream>
#include "Image_Class.h"
using namespace std;


void filter_1(Image& image) {
    for (int i = 0; i < image.width;i++) {
        for (int j = 0; j < image.height;j++) {
            unsigned int avg = 0;

            for (int k = 0 ; k < 3; k++) {
                avg += image (i, j, k);
            }
            avg = avg/3;
            for (int k = 0 ; k < 3; k++) {
                image (i,j,k) = avg;
            }
        }
    }
}

int main() {
    cout << "Enter image name" << endl;
    string image_name;
    getline (cin,image_name);
    Image image(image_name);
    filter_1(image);

    cout<<"The result image name:";
    string result ;
    getline (cin,result);
    image.saveImage(result);
    return 0;
}





