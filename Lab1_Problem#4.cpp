/*
Author: Shancong Mou
Class: ECE6122
Last Date Modified: 09/12/2020
Description:
This si for La1 problem4
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
double a = 5, b = 10;

void NextPoint(double *xx1, double *yy1, double *xx2, double *yy2)
{
    // here, x1,y1 is the initial point of the inlet ray, and x2,y2 are the intersection of the ellipse
    double x1,y1,x2,y2;
    x1  = *xx1;
    y1 = *yy1;
    x2 = *xx2;
    y2 = *yy2;
    double err = 0.0000001;
    double A, B, C; // Ax +By+c=0 of inlet ray
    double xhat, yhat; // point on the symetric line
    double m, c;  // y = m x +c outlet ray
    double x31, x32, x3, y3; //next point
    A = 4*x2;
    B = y2;
    C = - pow(y2, 2) - 4 * pow(x2, 2);
    xhat = ( (pow(B, 2) - pow(A, 2)) * x1 - 2*A*B*y1-2*A*C )/ (pow(A,2) + pow(B,2));
    yhat = ( -2*A*B*x1 + (pow(A,2) - pow(B,2)) *y1 - 2*B*C )/ (pow(A,2) + pow(B,2));
    m = (yhat - y2) / (xhat - x2);
    c = -(yhat - y2) / (xhat - x2)*xhat + yhat;
    x31 =( -2 * pow(a,2) * m * c + pow( pow( 2 * pow(a,2) * m * c, 2)  - 4* (pow(a,2)*pow(m,2)+pow(b,2)) * ( pow(a,2)* (pow(c,2)-pow(b,2)) ) , 0.5 ) )/ (2 * (pow(a,2)*pow(m,2)+pow(b,2)));
    x32 =( -2 * pow(a,2) * m * c - pow( pow( 2 * pow(a,2) * m * c, 2)  - 4* (pow(a,2)*pow(m,2)+pow(b,2)) * ( pow(a,2)* (pow(c,2)-pow(b,2)) ) , 0.5 ) )/ (2 * (pow(a,2)*pow(m,2)+pow(b,2)));
    // to fin dnext point
    if ( std::abs(x31-x2) < err){
        x3 = x32;
    }
    else{
        x3 = x31;
    }
    y3 = m * x3 + c;
//    std::cout << *xx1<<std::endl;
    *xx1 = x2;
    *yy1 = y2;
    *xx2 = x3;
    *yy2 = y3;
}



int main() {
    std::ofstream ofs;
    int Iter = 0;
    double a,b,c,d ;
    a = 0.0;
    b = 10.1;
    c = 1.4;
    d = -9.6;
    do {
        Iter =Iter + 1;
        NextPoint (&a, &b, &c, &d);
        std::cout<<c<<std::endl;
    }while(c>0.01 || c<-0.01);

   std::cout << Iter;
//    ofs.open("output4.txt");
    ofs << Iter;
    ofs.close();
    return 0;
}
