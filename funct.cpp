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

vector< vector<double> > saveRez(vector<int>index, vector< vector<double> >sarr, vector< vector<double> > out,Mat drawing,string fileStr)
{
Scalar colorBlue=0x0000ff;
    ofstream F(fileStr);
    for ( size_t iii=0; iii<index.size(); iii++ ) {
    //cout <<"Yes x=" << index[iii]<< "\n";
    circle( drawing, Point(sarr[index[iii]][1],sarr[index[iii]][0]), 4, colorBlue, 4 );
    out.push_back(sarr[index[iii]]); // создание массива только с нужными точками
            for (int y=0;y<9;y++)
            F<<sarr[index[iii]][y] <<" ";
        F<< "\n";
    }
    F.close();



    //for ( size_t i=0; i<out.size(); i++ ) {
    //            for ( size_t j=0; j<out[0].size(); j++ ) {
    //                cout << out[i][j] << "\t";
    //            }
    //            cout << "\n";
    //        }

return out;

}
//struct Velocity {
//    double dlinaX;
//    double dlinaY;
//    double dlinaZ;
//    double iNumMin;
//    double iNumMax;
//};

double dlina (vector< vector<double> >out,Mat drawing,double& dlinaX,double& dlinaY,double& dlinaZ, int& iNumMin,int& iNumMax)
{
   Scalar colorBlack=Scalar( 0, 0, 0 );
    double Temp=0,minCoord=10000,maxCoord=0;
    for ( size_t i=0; i<out.size(); i++ )
    {
     Temp = out[i][1]+out[i][0];
        if (Temp<minCoord){
            minCoord=Temp;
            iNumMin=i;
        }
        if (Temp>maxCoord){
            maxCoord=Temp;
            iNumMax=i;
        }
    }

    //cout <<"iNumMin=" << iNumMin<<"iNumMax=" << iNumMax<< "\n";
    circle( drawing, Point(out[iNumMin][1],out[iNumMin][0]), 4, colorBlack, 8 );
    circle( drawing, Point(out[iNumMax][1],out[iNumMax][0]), 4, colorBlack, 8 );
    line(drawing, Point(out[iNumMin][1],out[iNumMin][0]), Point(out[iNumMax][1],out[iNumMax][0]),colorBlack, 2);

    double arg1=pow(out[iNumMax][2]-out[iNumMin][2],2);
    double arg2=pow(out[iNumMax][3]-out[iNumMin][3],2);
    double arg3=pow(out[iNumMax][4]-out[iNumMin][4],2);
    double rez = sqrt(arg1+arg2+arg3);

    dlinaX=out[iNumMax][2]-out[iNumMin][2];
    dlinaY=out[iNumMax][3]-out[iNumMin][3];
    dlinaZ=out[iNumMax][4]-out[iNumMin][4];


return rez;

}






