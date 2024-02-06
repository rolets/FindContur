#ifndef FINDPOINT_H
#define FINDPOINT_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::cout;


bool FindPoint(double PoitsF[4][4], double x,double y);
vector<int> FindPointMain(cv::Point2f rect_points[4], vector< vector<double> >sarr, vector<int> index );


#endif // FINDPOINT_H
