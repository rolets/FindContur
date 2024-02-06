#include <QCoreApplication>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include <iomanip>
#include "TextGrab.h"
#include "FindPoint.h"
#include "funct.h"
#include "preprocessing.h"
using namespace cv;
using namespace std;

Mat src = imread( "D:\\imgLeft_1004.bmp" );
//Mat src = imread( "D:\\1.jpg" );
Mat frame;
String TextFile ="D:\\pointsClaster_1004.txt";
Scalar color2=Scalar( 0, 0, 255 );
Scalar colorBlack=Scalar( 0, 0, 0 );
Point2f rect_points[4];
Point2f rect_points1,rect_points2,rect_points3,rect_points4;
Mat drawing = Mat::zeros( src.size(), CV_8UC3 );

void output(double dlinaX,double dlinaY,double dlinaZ,double rez,vector< vector<double> > out,int iNumMin,int iNumMax)
{
    cout<< "\n";
    cout<<"Gabariti"<< "\n";
    cout <<"Diagonal=  " << rez<<  " mm \n";
    cout <<"Dlina X=  " << dlinaX<<  " mm \n";
    cout <<"Dlina Y=  " << dlinaY<<  " mm \n";
    cout <<"Dlina Z=  " << dlinaZ<<  " mm \n";
    cout <<"Min Coordinate X=  " << out[iNumMin][2]<<" Y = " << out[iNumMin][3]<<" Z = " << out[iNumMin][4]<< "\n";
    cout <<"Max Coordinate X=  " << out[iNumMax][2]<<" Y = " << out[iNumMax][3]<<" Z = " << out[iNumMax][4]<< "\n";
    //cout <<"Max Dlina=  " << rez<<  " mm \n";
    cout <<  "\n"; cout <<  "\n";
}

void mainFunc(Scalar LowScalar,Scalar HScalar,string FileText,vector< vector<double> >& out2)
{
    Mat frame2=predObr(frame, LowScalar, HScalar); // предобработка
    imshow("DealImg2", frame2);
    vector<cv::Point_<int>> PP;
    FindContr2(frame2, src,drawing,rect_points1,rect_points2,rect_points3,rect_points4,PP); //поиск контуров
    rect_points[0] = rect_points1;rect_points[1] = rect_points2;rect_points[2] = rect_points3;rect_points[3] = rect_points4;
    cout <<"Size Point=  " << PP.size()<<  " \n";
    imshow( "Contours", drawing );

    vector< vector<double> > sarr;  //массив в котором будет храниться все значениеня из файла
    readData(TextFile, " 	 ", sarr); // записть в массив из файла

    std::vector<int> index; // массив, номера строк в файле которые попадают в объект
    index=FindPointMain(rect_points,sarr,index ); // поиск точек которые попали в контур

 // сохранение полученных данных
// vector< vector<double> > out; //массив в котором будет храниться значениеня точек которые попали в контур
 out2=saveRez(index, sarr, out2, drawing,FileText);
 double dlinaX,dlinaY,dlinaZ;
 int iNumMin=0,iNumMax=0;
 double rez =dlina(out2, drawing, dlinaX,dlinaY,dlinaZ,iNumMin,iNumMax); // функция поиска максимальной длины.

 output(dlinaX,dlinaY,dlinaZ,rez,out2,iNumMin,iNumMax);
 imshow( "Contours", drawing );
}

int main(int argc, char *argv[])
{
   frame=src;
   vector< vector<double> > out2;
   Scalar LowScalar(14, 125, 87); Scalar HScalar(101, 210, 184);//(g1, b1, r1)) // imgLeft_1004.bmp зеленый стаканчик
   mainFunc(LowScalar,HScalar,"d:\\result.txt",out2);

   vector< vector<double> > out3;
   Scalar LowScalarBall(9, 99, 184); Scalar HScalarBall(144, 184, 255);//(g1, b1, r1)) // imgLeft_1004.bmp оранжевый шарик
   mainFunc(LowScalarBall,HScalarBall,"d:\\result2.txt",out3);

//out.clear();
//sarr.clear();
//index.clear();
waitKey();
return 0;
}
