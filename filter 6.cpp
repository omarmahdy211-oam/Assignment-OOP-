#include <iostream>
#include "image_class.h"
using namespace std;

void rotate_90(Image& img) {
    Image rotated(img.height, img.width);
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            rotated(img.height - 1 - j, i, 0) = img(i, j, 0);
            rotated(img.height - 1 - j, i, 1) = img(i, j, 1);
            rotated(img.height - 1 - j, i, 2) = img(i, j, 2);
        }
    }
    img = rotated;
}

void rotate_180(Image& img) {
    Image rotated(img.width, img.height);
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            rotated(img.width - 1 - i, img.height - 1 - j, 0) = img(i, j, 0);
            rotated(img.width - 1 - i, img.height - 1 - j, 1) = img(i, j, 1);
            rotated(img.width - 1 - i, img.height - 1 - j, 2) = img(i, j, 2);
        }
    }
    img = rotated;
}

void rotate_270(Image& img) {
    Image rotated(img.height, img.width);
    for (int i = 0; i < img.width; i++) {
        for (int j = 0; j < img.height; j++) {
            rotated(j, img.width - 1 - i, 0) = img(i, j, 0);
            rotated(j, img.width - 1 - i, 1) = img(i, j, 1);
            rotated(j, img.width - 1 - i, 2) = img(i, j, 2);
        }
    }
    img = rotated;
}

void filter_6(Image& img) {
    int angle;
    cout << "Enter rotation angle (90, 180, 270): ";
    cin >> angle;

    if (angle == 90) {
        rotate_90(img);
    }
    else if (angle == 180) {
        rotate_180(img);
    }
    else if (angle == 270) {
        rotate_270(img);
    }
    else {
        cout << "Invalid angle!" << endl;
    }
}