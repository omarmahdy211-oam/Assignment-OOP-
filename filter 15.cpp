#include <iostream>
#include "Image_Class.h"
using namespace std;


void filter_15 (Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            if (image(i,j,0)<=170) {
                image(i,j,0) = image(i , j ,0) + image(i ,j ,0 )/2 ;
            }
            else {
                image(i,j,0) = 255 ;
            }

            image(i,j,1) = image(i , j ,1) - image(i ,j ,1 )/4 ;


            if (image(i,j,2)<=170) {
                image(i,j,2) = image(i , j ,2) + image(i ,j ,2 )/2 ;
            }
            else {
                image(i,j,2) = 255 ;
            }
        }
    }


}





int main() {
    Image image ("luffy.jpg") ;
    filter_15(image);
    image.saveImage("13.jpg");
}
