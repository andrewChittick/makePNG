//imageIO.cpp
//Andrew Chittick
//2/3/19

#include <iostream>

int main(){
	//initialize variables
	FILE * imageFile;
	long lSize;

	//open file
	imageFile = fopen ("rawImage.raw", "rb");

	//get size
	fseek (imageFile, 0, SEEK_END);
	lSize = ftell (imageFile);
	rewind (imageFile);

	//allocate memory
	unsigned char image1[lSize];

	//copy image
	fread (image1, 1, lSize, imageFile);
	rewind(imageFile);

	//close original file
	fclose(imageFile);

#include "lodepng.h"
#include <iostream>
	encodeOneStep(poop.png, image1,500,lSize/500); 

/*
3 ways to encode a PNG from RGBA pixel data to a file (and 2 in-memory ways).
NOTE: this samples overwrite the file or test.png without warning!
*/

//g++ lodepng.cpp examples/example_encode.cpp -I./ -ansi -pedantic -Wall -Wextra -O3

//Example 1
//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
  //Encode the image
  unsigned error = lodepng::encode(filename, image, width, height);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}
	/*
	//manipulate image
	
	//reverse it
	for (int i=0; i<lSize; i++){
		image1[i]=-image1[i];
	}
	//write file
	FILE * pFile;
	pFile = fopen ("output1.raw", "wb");
	fwrite (image1, sizeof(unsigned char), lSize, pFile);
	fclose(pFile);

	//add 20
	for (int i=0; i<lSize; i++){
		image2[i]=(int)image2[i]+20;
	}
	//write file
	FILE * pFile2;
	pFile2 = fopen ("output2.raw", "wb");
	fwrite (image2, sizeof(unsigned char), lSize, pFile);
	fclose(pFile2);

	//add 128
	for (int i=0; i<lSize; i++){
		image3[i]=(int)image3[i]+128;
	}
	//write file
	FILE * pFile3;
	pFile3 = fopen ("output3.raw", "wb");
	fwrite (image3, sizeof(unsigned char), lSize, pFile);
	fclose(pFile3);
	*/

	return 0;
}
