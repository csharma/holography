#include "stdafx.h"
#include "hogel_improved_res.h"

 
Chogel_improved_res::Chogel_improved_res() { 
	m_xWinLat = 256.;
	m_yWinLat = 256.;

	m_xdims = 512;
	m_ydims = 512;
	m_zdims = 512;

	m_ztime = 10;
	double s = 0.45;
	double r = 0.1;

	m_aspectRatio = 2.; 
	int spaceAlloc= 1;

		for (int ii=0; ii <2; ii++) 
			for (int jj=0; jj < 512; jj++) {
				s = 0.45; r = 0.1;
		 	m_originalImage[ii][jj] = s*r;
		}

		spaceAlloc = 512*512*pow(2,10);

		// Allocation is 512*64 bit values
		cout << " memory requirements " << spaceAlloc <<endl;
		  
}
 
Chogel_improved_res::~Chogel_improved_res() { 

}

void Chogel_improved_res::computeAspectRatio(int *scaleFactor) { 
  
	float x1, x2, y1, y2;

	x1 = 0.0; x2 = 512;
	y1 = 0.0; y2 = 512; 
	
	m_xWinLat = abs(x2-x1);
	m_yWinLat = abs(y2-y1);


	/* make pixels circular instead of square,?, measure projection on longitudinal axes */
	while (m_xWinLat > 0)	
  	  m_aspectRatio = int(m_yWinLat/m_xWinLat);
 
}


void Chogel_improved_res::getAspectRatio(int *scaleFactor) { 

	*scaleFactor = m_aspectRatio; 
//	return m_aspectRatio;
}

void Chogel_improved_res::setHogelRes(double hogelRes) {
	
	m_dHogelRes =  hogelRes;
}

// Computes hogel resolution based on focal length and optimal diffraction grating width
// for interference fringes.
void Chogel_improved_res::getHogelRes(double *res) {

	// focal length at diffration gratings corresponding to optimal distance from lense
	double f= 100;
	double f0 = 150;
	int m = 2.5; // magnification factor
	double z= 10.0; // shear

		
	double expr = sqrt(f*f+f0+2*f)/z +1.5*m*f0;
		
	*res = (expr+1.5*m*f0)/1000.0; 
	
}

void Chogel_improved_res::getDataDimensions(int returnSize, int *sz){
	*sz = returnSize ;
}

int Chogel_improved_res::setDataDims(int xsize, int ysize){
 
	return 512;
}
 
void Chogel_improved_res::setDataRes(double dataDims){
 
	printf(" here's  how the resolution could be modified in projection plane\t\n");
	cout << dataDims << endl;
	int  xsize = int(dataDims);
	int  ysize = int(dataDims);

	//this->getDataDims(&xsize, &ysize);
	this->setDataDims(xsize, ysize);
	
}
	
void Chogel_improved_res::getDataDims(int *dxsize, int *dysize) {
	
	m_xdims = 512.;
	m_ydims = 512.;

	// default z dimensions and temporal width
	m_zdims = 512.;
	m_ztime = 2;
}

// numerical reconstruction of hogels and optical computing based on 
// original image projection and visualization
int Chogel_improved_res::numericalOptimizers(int dataBounds[MAX][MAX], double hogelSize, int *xRes, int *yRes)
{
	// Include apply computing libraries to compute fast fourier transforms and IFT
	//
	
	for (int ii = 0; ii <2; ii++)  
		for (int jj =0; jj<512; jj++) {
		m_originalImage[ii][jj] = rand( )/256;
	}

	return 1;
}

void Chogel_improved_res::setAspectRatio(int scaleFactor){

	m_aspectRatio = scaleFactor;

	cout << " aspect ratio " << m_aspectRatio << endl;
}
  
bool Chogel_improved_res::getComputeXfms(double *xfm) {

	return S_FALSE;
}

void Chogel_improved_res::setComputeXfms(double xfm[4][4]) { 

	double s = -0.45; 
	double r = 0.145; // sin(theta) = 0145

	for (int ii=0; ii <4; ii++) 
		for (int jj=0; jj < 4; jj++) 
			xfm[ii][jj] = ii*jj;

	xfm[0][3] = 0; xfm[1][3] =0; xfm[2][3]=0; xfm[3][3] =1;

	for (  ii = 0; ii < 4; ii++) {	
		for ( int  jj =0;jj < 4; jj++) {
			s = 0.45; r = 0.1;
			xfm[ii][jj] = s*r;
		}
	}// for loop with rows, columns and values associated with various elements


}


// Wrapper functions for OpenCV for original image processing, analysis
void Chogel_improved_res::openCVWrapperEnhance(double originalImages[512][512],double outputImages[512][512],
												double noise, unsigned int seed) {


}
 
// Wrapper functions for OpenCV for original images, processing, analysis, display and enhancement.
void Chogel_improved_res::openCVWrapperEnhanceDisp(double displayImages[MAX][MAX],double outputImages[512][512],
							int xDimOutput,int yDimOutput, double noise) {

}


void Chogel_improved_res::improveImagesResVision() { 

}