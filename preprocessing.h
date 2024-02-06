#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
using namespace cv;


Mat predObr(Mat frame,Scalar LowScalar,Scalar HScalar);
void FindContr2(Mat frame2, Mat src, Mat& drawing,Point2f& rect_points1,Point2f& rect_points2,Point2f& rect_points3,Point2f& rect_points4,vector<cv::Point_<int>>& PP);

#endif // PREPROCESSING_H
