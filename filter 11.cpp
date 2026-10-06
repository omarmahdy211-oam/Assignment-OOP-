#include <iostream>
#include "Image_Class.h"
using namespace std;


void filter_11 (Image& image) {
    int x ,y ;
    cout << "Enter the x and y coordinates of the image:";
    cin >> x >> y;

    int new_width ,new_height ;
    cout << "Enter the width and height of the image:";
    cin >> new_width >> new_height;

    Image new_image(new_width,new_height);

    if( x + new_width <= image.width && y + new_height <= image.height){
        for (int i = x ; i <  (x+new_width) ; i++) {
            for (int j = y ; j <  (y+new_height) ; j++) {
                new_image(i-x , j-y ,0) =image(i , j ,0);
                new_image(i-x , j-y ,1) =image(i , j ,1);
                new_image(i-x , j-y ,2) =image(i , j ,2);
            }
        }
    }
    else {
        cout << "Invalid crop dimensions!" << endl;
        return  ;
    }
    image = new_image ;
}

int main() {
    Image image ("building.jpg") ;
    filter_11(image);
    image.saveImage("11111.jpg");
}
// في الmain  هنشل if االي في الكود وخليها في الmain