#include <iostream>
#include "Image_Class.h"
using namespace std;


void filter_16(Image& image4) {
    for (int i = 0; i < image4.width; ++i) {
        for (int j = 0; j < image4.height; ++j) {

            int red = image4(i, j, 0);
            int green = image4(i, j, 1);
            int blue = image4(i, j, 2);

            int newRed = min(255, red + 100);
            int newGreen = max(0, green - 50);
            int newBlue = max(0, blue - 50);

            image4(i, j, 0)=newRed;
            image4(i, j, 1)=newGreen;
            image4(i, j, 2)=newBlue;
        }
    }
}





int main() {
    Image image ("samurai.jpg") ;
    filter_16(image);
    image.saveImage("samurai.jpg");
}
