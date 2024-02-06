#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#include "FindPoint.h"

using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::cout;


vector<int> FindPointMain(cv::Point2f rect_points[4], vector< vector<double> >sarr, vector<int> index )
{

    double x1,x2,x3,x4,y1,y2,y3,y4;
    double x,y;
// процент
  double procent=0.01;

  // точки прямоугольника
     x1=rect_points[0].x;y1=rect_points[0].y;x2=rect_points[1].x;y2=rect_points[1].y;x3=rect_points[2].x;y3=rect_points[2].y;x4=rect_points[3].x;y4=rect_points[3].y;
     x1=x1-(x1*procent);
     y1=y1-(y1*procent);
     x2=x2+(x2*procent);
     y2=y2-(y2*procent);
     x3=x3+(x3*procent);
     y3=y3+(y3*procent);
     x4=x4-(x4*procent);
     y4=y4+(y4*procent);
    double PoitsF[4][4];
    PoitsF[0][0]=x1;PoitsF[0][1]=y1;PoitsF[1][0]=x2;PoitsF[1][1]=y2;
    PoitsF[2][0]=x3;PoitsF[2][1]=y3;PoitsF[3][0]=x4;PoitsF[3][1]=y4;



  for ( size_t iii=0; iii<sarr.size(); iii++ ) {

    // искомая точка
    x=sarr[iii][1];
    y=sarr[iii][0];
    if (FindPoint(PoitsF, x, y))
      {
        index.push_back(iii);
        //ind++;
       // cout <<"Yes x=  " << x <<" y=  " << y<< "\n"; // точка внутри прямоугольника
        //out[index][0]=x;
       // out[index][1]=y;
     //   cout <<"Yes x=  " << x <<" y=  " << y <<"\n"; // точка внутри прямоугольника
      // circle( drawing, Point(x22,y22), 4, color, 4 );
      }
     }


return index;
}



bool FindPoint(double PoitsF[4][4], double x,double y)
{
     double d,xNew,yNew;
     double x1,x2,x3,x4,y1,y2,y3,y4;
     x1=PoitsF[0][0];y1=PoitsF[0][1];
     x2=PoitsF[1][0];y2=PoitsF[1][1];
     x3=PoitsF[2][0];y3=PoitsF[2][1];
     x4=PoitsF[3][0];y4=PoitsF[3][1];
    // формула поиска точки внутри прямоугольника
   d=((x3-x2)*(y1-y2))-((x1-x2)*(y3-y2));
   xNew=(((y1-y2)*(x-x2))-((x1-x2)*(y-y2)))/d;
   yNew=((-(y3-y2)*(x-x2))+((x3-x2)*(y-y2)))/d;
  // cout <<"x= "<< xNew << " y= "<< yNew << "\n";

if (xNew>=0 && xNew<=1 && yNew>=0 && yNew<=1)
    return true;
 else
     return false;
}
