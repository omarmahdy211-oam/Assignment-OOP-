#include <iostream>
#include "Image_Class.h"
using namespace std;


void filter_5_horizontal(Image& image) {
        for (int i = 0; i < image.width / 2; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    swap(image(i, j, k), image(image.width - 1 - i, j, k));
                }
            }
        }
    }

void filter_5_vertical(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height / 2; j++) {
            for (int k = 0; k < 3; k++) {
                swap(image(i, j, k), image(i, image.height - 1 - j, k));
            }
        }
    }
}


int main() {
    cout << "Enter image name" << endl;
    string image_name;
    getline(cin, image_name);
    Image image(image_name);

    cout << "1) Horizontal flip" << endl;
    cout << "2) Vertical flip" << endl;
    cout << "Choose: ";
    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
        case 1:
            filter_5_horizontal(image);
            break;
        case 2:
            filter_5_vertical(image);
            break;
    }

    cout << "The result image name:";
    string result;
    getline(cin, result);
    image.saveImage(result);
    return 0;
}