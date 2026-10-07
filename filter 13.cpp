#include <iostream>
#include "Image_Class.h"
using namespace std;



void filter_13(Image& image) {
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                if (image(i, j, 0) <= 204) {
                    image(i, j, 0) = image(i, j, 0) + image(i, j, 0) / 4;
                }
                else {
                    image(i, j, 0) = 255;
                }

                if (image(i, j, 1) <= 225) {
                    image(i, j, 1) = image(i, j, 1) + image(i, j, 1) / 8;
                }
                else {
                    image(i, j, 1) = 255;
                }

                image(i, j, 2) = image(i, j, 2) - image(i, j, 2) / 8;
            }
        }
    }

    int main() {
        Image image("Wano 1.jpg");
        filter_13(image);
        image.saveImage("sunshine wano.jpg");
        return 0;
    }