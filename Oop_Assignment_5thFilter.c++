#include<iostream>
#include"Image_Class.h"
using namespace std;
int main(){
    
 Image image("luffy.jpg");

 for(int j=image.width/2;j<image.width;j++){
    for(int i=0;i<image.height;i++){

        
        for(int k=0;k<image.channels;k++){
            int temp =image(j,i,k);
         image(j,i,k)=image((image.width-1)-j,i,k);
         image((image.width-1)-j,i,k)=temp;
        }
    }
    
    
}
image.saveImage("luffy_flipflop_right&lift.jpg");
cout<<"aha";
return 0;
}