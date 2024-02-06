#ifndef FUNCT_H
#define FUNCT_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
double dlina (vector< vector<double> >out,Mat drawing,double& dlinaX,double& dlinaY,double& dlinaZ, int& iNumMin,int& iNumMax);
vector< vector<double> > saveRez(vector<int>index, vector< vector<double> >sarr, vector< vector<double> > out,Mat drawing,string fileStr);
//void FindCon(Mat frame,Point2f rect_points[4],int iNum,Mat src,Mat drawing);

#endif // FUNCT_H
