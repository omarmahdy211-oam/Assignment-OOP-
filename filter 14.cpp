#include <iostream>
#include "Image_Class.h"
using namespace std;


void filter_14(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            if (i % 3 == 0) {
                image(j, i, 0) = image(j, i, 0) * 0.4;
                image(j, i, 1) = image(j, i, 1) * 0.4;
                image(j, i, 2) = image(j, i, 2) * 0.4;
            } else {
                image(j, i, 0) = image(j, i, 0) * 0.85;
                image(j, i, 2) = image(j, i, 2) * 0.90;
            }
        }
    }
}





int main() {
    Image image ("luffy.jpg") ;
    filter_14(image);
    image.saveImage("14.jpg");
}
