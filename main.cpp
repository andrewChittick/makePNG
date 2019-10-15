//main.cpp
//Andrew Chittick
//10/15/19

#include <iostream>
#include <vector>
#include "lodepng.h"

void encodeOneStep(const char* , std::vector<unsigned char>& , unsigned , unsigned);

int main(){
	//initialize variables
	std::vector<unsigned char> picture (2500, 0);
	for (int i=0; i<500; i++){
		if (i%2 == 0){
			picture[i]=255;
		}
	}
	encodeOneStep("poop.png", picture,50,50); 
	return 0;

}


//Example 1
//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}
