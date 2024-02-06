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


Mat predObr(Mat frame,Scalar LowScalar,Scalar HScalar)
{
    Mat frameBlur,frame_threshold,frame2;

     medianBlur(frame, frameBlur, 7);  //фильтр сглаживания

         // int r1=69; int g1=50; int  b1=134; int r2=154; int g2=118; int b2=156;// стаканчик первое фото
        //  int r1=69; int g1=0; int  b1=0; int r2=255; int g2=255; int b2=49; // красный кубик
          inRange(frameBlur, LowScalar, HScalar,frame_threshold);
          frameBlur.copyTo(frame2, frame_threshold);

 // морфологическое открытие и закрытие
             Mat se2 = getStructuringElement(MORPH_RECT, Size(20, 20));
             Mat se1 = getStructuringElement(MORPH_RECT, Size(30, 30));
             morphologyEx(frame2, frame2, MORPH_OPEN, se2);
             morphologyEx(frame2, frame2, MORPH_CLOSE, se1);
 // ///////

         // cv::resize(frame2, frame2, cv::Size( double(frame2.cols * 0.5),double(frame2.rows) * 0.5), 0, 0, cv::INTER_LINEAR);
         //cv::resize(frame, frame, cv::Size( double(frame.cols * 0.5),double(frame.rows) * 0.5), 0, 0, cv::INTER_LINEAR);

   return  frame2;
}


void FindContr2(Mat frame2, Mat src, Mat& drawing,Point2f& rect_points1,Point2f& rect_points2,Point2f& rect_points3,Point2f& rect_points4,vector<cv::Point_<int>>& PP)
{

     Point2f rect_points[4];
     RNG rng(12345);
     Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
     Scalar color2=Scalar( 0, 0, 255 );
     int iNum=0;
     int thresh = 180;
     Mat canny_output;
     vector<vector<Point> > contours;
     Canny( frame2, canny_output, thresh, thresh*2, 3 );
     findContours( canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE );

 double area0=0,areaTemp=0;

 // ищем самый большой предмет
 for( size_t i = 0; i< contours.size(); i++ )
 {
 areaTemp = contourArea(contours[i]);//площадь
 if (areaTemp>area0){
  area0=areaTemp;
  iNum=i;
 }
 }
 // поиск прямоугольника
 //                    vector<Rect> boundRect( contours.size() );
 //                    vector<vector<Point> > contours_poly( contours.size() );
 //                    approxPolyDP( contours[iNum], contours_poly[iNum], 3, true );
 //                    boundRect[iNum] = boundingRect( contours_poly[iNum] );
 // rectangle( drawing, boundRect[iNum].tl(), boundRect[iNum].br(), color2, 2 ); // обведение в квадрат

 // поиск вершин обнаруженного предмета
                 vector<RotatedRect> minRect( contours.size() );
                 minRect[iNum] = minAreaRect( contours[iNum] );

                 minRect[iNum].points( rect_points );
                 cout <<"size rectangle " << minRect[iNum].size<< "\n";
                 cout <<"angle rectangle " << minRect[iNum].angle<< " grad \n";
                 cout << "Coordinate  rectangle "<< rect_points[0] << " , "<< rect_points[1]<< " , "<< rect_points[2]<< " , "<< rect_points[3]<< endl;


                 drawing=src;


                 for ( int j = 0; j < 4; j++ )
                   {
                       line( drawing, rect_points[j], rect_points[(j+1)%4], color,4 );
                   }
                 // ////////////////////////////

            drawContours( drawing, contours, (int)iNum, color2, 5 );
            for ( size_t iii=0; iii<4; iii++ )
             circle( drawing, rect_points[iii], 4, 0x000000 , 6 );

       PP=contours[iNum];


        for (int i=0;i<PP.size();i++)
            circle( drawing, PP[i], 4, 0x000000 , 4 );

rect_points1=rect_points[0];rect_points2=rect_points[1];rect_points3=rect_points[2];rect_points4=rect_points[3];

}
