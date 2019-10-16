//main.cpp
//Andrew Chittick
//10/15/19

#include <iostream>
#include <vector>
#include "lodepng.h"

void encodeOneStep(const char* , std::vector<unsigned char>& , unsigned , unsigned);

int main(){
	//make a white 200 * 200
	std::vector<unsigned char> picture (160000, 255);

	//make some blue lines
	for (int i=0; i<160000; i+=4){
		if (i%400==0){
			picture[i]=0;
			picture[i+1]=0;

			picture[i+4]=0;
			picture[i+5]=0;

			picture[i+8]=0;
			picture[i+9]=0;
		}
	}
	encodeOneStep("poop.png", picture,200,200); 
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
