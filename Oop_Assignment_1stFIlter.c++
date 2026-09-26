#include<iostream>
#include"Image_class.h"
using namespace std;
int main(){
 Image image("building.jpg");
 for(int i=0;i<image.width;i++){

    for(int j=0;j<image.height;j++){

        for(int k=0;k<image.channels;k++){
            image(i,j,k)=image(i,j,0);



        }

    }


 }
 

 image.saveImage("building_filter1.jpg");
 cout<<"aha";

    return 0;
}