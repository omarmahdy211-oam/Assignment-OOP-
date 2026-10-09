#include <iostream>
#include "Image_Class.h"
using namespace std;




void filter_10(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            int avg = (image(i, j, 0) + image(i, j, 1) + image(i, j, 2)) / 3;
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }

    Image result(image.width, image.height);
    int limit = 30;

    for (int i = 0; i < image.width - 1; ++i) {
        for (int j = 0; j < image.height - 1; ++j) {
            int diffX = abs(image(i, j, 0) - image(i + 1, j, 0));
            int diffY = abs(image(i, j, 0) - image(i, j + 1, 0));

            if (diffX > limit || diffY > limit) {
                result(i, j, 0) = 0;
                result(i, j, 1) = 0;
                result(i, j, 2) = 0;
            } else {
                result(i, j, 0) = 255;
                result(i, j, 1) = 255;
                result(i, j, 2) = 255;
            }
        }
    }

    image = result;
}



int main() {
    Image image ("luffy.jpg") ;
    filter_10(image);
    image.saveImage("10.jpg");
}
