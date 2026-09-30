#include <iostream>
#include "Image_Class.h"
using namespace std;

void filter_4_simple(Image& image1) {
    int frame ;
    cout << "Enter frame number : ";
    cin >> frame;
    for (int i = 0; i<image1.width ;i++) {
        for (int j = 0; j<image1.height; j++) {
            if (i<frame || i>image1.width - frame || j<frame || j>image1.height - frame) {
                image1(i,j,0)=0;
                image1(i,j,1)=0;
                image1(i,j,2)=0;
            }
        }
    }
}


void filter_4_complex(Image& image1) {
    int frame;
    cout << "Enter frame number : ";
    cin >> frame;
    for (int i = 0; i<image1.width ;i++) {
        for (int j=0; j<image1.height; j++) {
            if (i<frame || i>image1.width - frame || j<frame || j>image1.height - frame) {
                if ((i+j)%7==0) {
                    image1(i,j,0)=255;
                    image1(i,j,1)=255;
                    image1(i,j,2)=255;
                }

                else {
                    image1(i,j,0)=0;
                    image1(i,j,1)=0;
                    image1(i,j,2)=0;
                }
            }
        }
    }
}



int main() {
    Image image1("Wano 2.jpg");
    int frame_number = 30;
    filter_4_complex(image1);
    image1.saveImage("Wano_framed_complex2.jpg");


}