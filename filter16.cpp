#include <iostream>
#include "Image_Class.h"
using namespace std;
#include "Image_Class.h"
#include <iostream>
#include <algorithm>

void filter_16(Image& image4) {
    for (int i = 0; i < image4.width; ++i) {
        for (int j = 0; j < image4.height; ++j) {

            int red = image4.getPixel(i, j, 0);
            int green = image4.getPixel(i, j, 1);
            int blue = image4.getPixel(i, j, 2);

            int newRed = std::min(255, red + 100);
            int newGreen = std::max(0, green - 50);
            int newBlue = std::max(0, blue - 50);

            image4.setPixel(i, j, 0, newRed);
            image4.setPixel(i, j, 1, newGreen);
            image4.setPixel(i, j, 2, newBlue);
        }
    }
}

int main() {
    Image image2 ("mario.bmp");
    filter_16(image2);
    image2.saveImage("mario1.bmp");
}