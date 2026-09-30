#include <iostream>
#include "image_class.h"
using namespace std;

void filter_2(Image& img) {
    for (int i=0 ; i<img.width ; i++) {
        for (int j=0 ; j<img.height ; j++) {
           int avg=((img(i,j,0)+img(i,j,1)+img(i,j,2))/3);
            if (avg < 128) {
                img(i, j ,0) =0 ;
                img(i, j ,1) =0 ;
                img(i, j ,2) =0 ;
            }
            else {
                img(i, j ,0) =255 ;
                img(i, j ,1) =255 ;
                img(i, j ,2) =255 ;
            }
        }
    }

}