// hogel.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hogel_improved_res.h"

class hogel_improved_res;

int main(int argc, char* argv[])
{

	int sz = 1; 
	int tr = 2;
	unsigned int seed = 5;  

	Chogel_improved_res H1;
	double res = 1.0;

	int scaleFactor = 5; 
	double noise = 0.5; 
	// Define parameters for initial view 
	printf("Excel resolution for hogel elements!\n");

	H1.setAspectRatio(scaleFactor);

	// Setup lens combinations and u,v and focal length parameters
	H1.getHogelRes(&res);
	 

	int xDimensionOutput = 256;
	int yDimensionOutput = 256;
     // Specify image dimensions and properties
	if (res > 0.0)
		H1.getDataDimensions(sz, &tr);


	// Scale and enhance image properties based on image resolution improvement and 
	// visualization
	H1.improveImagesResVision();
	cout << "image resolution " << res << endl;
 

	// Integrate with OpenCV and enhance based on smoothing and artifact removal
//	H1.openCVWrapperEnhance(originalImages,originalImages ,noise,seed);

	// Integrate with OpenCV and enhance based on smoothing and artifact removal at certain output dimensions
//	 H1.openCVWrapperEnhanceDisp(originalImages,originalImages, xDimOutput, yDimOutput, noise);


	// restore scale factors to obtain the original image and native resolution
	// Store for future application in archived/compressed format
	return 1;
}
 