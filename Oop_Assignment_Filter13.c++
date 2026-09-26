#include<iostream>
#include"Image_Class.h"
using namespace std;
int main(){
  int trs;
  int Brightness=50;
  Image image("old_tv_image.jpg");
  Image image2(image.width, image.height);
  for(int i=0;i<image.height;i++){
    for(int j=0;j<image.width;j++){
      for(int k=0;k<image.channels;k++){
              trs= image(j,i,k)+Brightness;
              if(trs>255){
                  trs=255;
              }
              else if(trs<0){
                  trs=0;
              }
              image2(j,i,k)=trs;

               
            }


        }
    }
    cout<<"Image copied successfully!"<<endl;
 image2.saveImage("new_tv_image.jpg");
  return 0;  
}