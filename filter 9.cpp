#include <iostream>
#include <algorithm>
#include "Image_Class.h"
using namespace std;

void filter_9(Image& image, Image& image2, int option) {
    int new_width, new_height;
    if (option == 1) {
        new_width = max(image.width, image2.width);
        new_height = max(image.height, image2.height);
    } else {
        new_width = min(image.width, image2.width);
        new_height = min(image.height, image2.height);
    }

    Image new_image(new_width, new_height);

    for (int i = 0; i < new_width; i++) {
        for (int j = 0; j < new_height; j++) {
            int x1 = i, y1 = j, x2 = i, y2 = j;
            if (option == 1) {
                x1 = i * image.width / new_width;
                y1 = j * image.height / new_height;
                x2 = i * image2.width / new_width;
                y2 = j * image2.height / new_height;
            }
            for (int k = 0; k < 3; k++) {
                new_image(i, j, k) = (image(x1, y1, k) + image2(x2, y2, k)) / 2;
            }
        }
    }
    image = new_image;
}

int main() {
    string name1, name2, out_name;
    int option;

    cout << "Enter the first image name: ";
    getline(cin, name1);
    Image image(name1);

    cout << "Enter the second image name: ";
    getline(cin, name2);
    Image image2(name2);

    cout << "1) Resize to biggest  2) Common area: ";
    cin >> option;
    cin.ignore();

    filter_9(image, image2, option);

    cout << "Enter the output image name: ";
    getline(cin, out_name);
    image.saveImage(out_name);
}