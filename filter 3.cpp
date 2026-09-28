#include <iostream>
#include "Image_Class.h"
using namespace std;

void filter_3(Image& image) {
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            image(i ,j , 0) = 255 - image(i ,j , 0);
            image(i ,j , 1) = 255 - image(i ,j , 1);
            image(i ,j , 2) = 255 - image(i ,j , 2);
        }
    }
}

int main() {
    cout<< "Enter image Name"<<endl;
    string image_name ;
    getline(cin,image_name);

    Image image(image_name);
    filter_3 (image);



    cout<< "The result image name : " ;
    string result ;
    getline(cin,result);


    image.saveImage(result);
    return 0;
}