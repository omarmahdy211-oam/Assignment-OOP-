#include <iostream>
#include "Image_Class.h"
using namespace std;
void filter_12(Image& image3) {
    int Radius = 3;
    cout << "Enter Radius level: ";
    cin >> Radius;

    int newWidth = image3.width;
    int newHeight = image3.height;

    Image blurredImage(newWidth, newHeight);

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            int sumR = 0, sumG = 0, sumB = 0;
            int count = 0;

            for (int deltax = -Radius; deltax <= Radius; deltax++) {
                for (int deltay = -Radius; deltay <= Radius; deltay++) {
                    int ni = i + deltax;
                    int nj = j + deltay;

                    if (ni >= 0 && ni < newWidth && nj >= 0 && nj < newHeight) {
                        sumR += image3(ni, nj, 0);
                        sumG += image3(ni, nj, 1);
                        sumB += image3(ni, nj, 2);
                        count++;
                    }
                }
            }

            if (count > 0) {
                blurredImage(i, j, 0) = sumR / count;
                blurredImage(i, j, 1) = sumG / count;
                blurredImage(i, j, 2) = sumB / count;
            }
        }
    }

    for (int i = 0; i < newWidth; i++) {
        for (int j = 0; j < newHeight; j++) {
            for (int c = 0; c < 3; c++) {
                image3(i, j, c) = blurredImage(i, j, c);
            }
        }
    }
}
int main() {
    Image image3("BlueCar.jpg");

    filter_12(image3);

    image3.saveImage("BlueCar4.jpg");
    cout << "Done! Image blurred and saved successfully as BlueCar4.jpg" << endl;

    return 0;
}
// note:To make the code run more quickly add this code to the "CMAKELists.txt in the project
//the code is "set(CMAKE_BUILD_TYPE Release)"