#if !defined(AFX_CHOGEL_IMPROVED_RES_H__2351D4D4_3BE7_4F6A_A71D_C9FE3892FEAC__INCLUDED_)
#define AFX_CHOGEL_IMPROVED_RES_H__2351D4D4_3BE7_4F6A_A71D_C9FE3892FEAC__INCLUDED_

  
#include <iomanip.h>
#include <math.h>
#include <vector>

#define HOGEL_SIZE 0.4
#define MAX 512

#define S_TRUE 1
#define S_FALSE 0
class Chogel_improved_res {
public:
 
	Chogel_improved_res();
	virtual ~Chogel_improved_res();

	void getDataDimensions(int sz, int *retSize);
	int setDataDims(int xsize, int ysize);
	
	void getHogelRes(double *res);
	void setHogelRes(double res);
	
	void getDataDims(int *xsize, int *ysize);
	void setDataRes(double dataDims);
	
	void getAspectRatio(int *scaleFactor);
	void setAspectRatio(int scaleFactor);

	bool getComputeXfms(double *xfm);
	void setComputeXfms(double xfm[4][4]);

	 
	void computeAspectRatio(int *scaleFactor);
	void improveImagesResVision();

 	 
	int numericalOptimizers(int dataBounds[MAX ][MAX ], double hogelSize, int *xRes, int *yRes);
	
    void openCVWrapperEnhance(double originalImages[MAX][MAX], double outputImages[MAX][MAX], double noise, unsigned int seed);
	void openCVWrapperEnhanceDisp(double displayImages[MAX][MAX],double outputImages[MAX][MAX],int xDimOutput,int yDimOutput, double noise);
	 
 	
protected:
	double magnifZoom; 
	int m_xWinLat;
	int m_yWinLat;


private:
	int m_iDataDims;
	double m_dHogelRes;

	int m_xdims;
	int m_ydims;
	int m_zdims;
	 
	float m_ztime;

	int m_aspectRatio;
  	int m_originalImage[2][512];
};   
#endif