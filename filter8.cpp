#include <iostream>
#include "Image_Class.h"
using namespace std;
void filter_8(Image& image2) {
    int newWidth , newHeight;
    cout<<"Enter width and height: ";
    cin>>newWidth>>newHeight;
    Image resized_image(newWidth,newHeight);
    for (int i=0;i<newWidth;++i) {
        for (int j=0;j<newHeight;++j) {
            int orig_i = i*image2.width/newWidth;
            int orig_j = j*image2.height/newHeight;
            for (int c = 0; c < image2.channels; ++c) {
                resized_image(i, j, c) = image2(orig_i, orig_j, c);
            }
        }
    }
    image2 = resized_image;
}
int main() {
    Image image2 ("samurai.jpg");
    filter_8(image2);
    image2.saveImage("resized_samurai1.jpg");
}