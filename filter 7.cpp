#include <iostream>
#include "Image_Class.h"
using namespace std;

#include <iostream>
#include "Image_Class.h"
using namespace std;

void filter_7_light (Image& image) {
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            if (image(i,j,0)<=170) {
                image(i,j,0) = image(i , j ,0) + image(i ,j ,0 )/2 ;
            }
            else {
                image(i,j,0) = 255 ;
            }
            if (image(i,j,1)<=170) {
                image(i,j,1) = image(i , j ,1) + image(i ,j ,1 )/2 ;
            }
            else {
                image(i,j,1) = 255 ;
            }
            if (image(i,j,2)<=170) {
                image(i,j,2) = image(i , j ,2) + image(i ,j ,2 )/2 ;
            }
            else {
                image(i,j,2) = 255 ;
            }

        }
    }
}

void filter_7_dark (Image& image) {
    for (int i = 0 ; i < image.width ; i++) {
        for (int j = 0 ; j < image.height ; j++) {
            image(i , j, 0) = image(i,j,0)/2 ;
            image(i , j, 1) = image(i,j,1)/2 ;
            image(i , j, 2) = image(i,j,2)/2 ;
        }
    }
}

int main() {
    cout<< "Enter image Name"<<endl;
    string image_name ;
    getline(cin,image_name);

    Image image(image_name);
    filter_7_dark(image);



    cout<< "The result image name : " ;
    string result ;
    getline(cin,result);


    image.saveImage(result);
    return 0;
}

