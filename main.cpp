//#include <stdafx.h>

#include <cmath>

#include <iostream>

using namespace std;


//-2.97095
//0.623584

float f(float x){

 return x-2*cos(x)+1;//f

}

float f1(float x){

 return 1+2*sin(x);//f'

}

float f2(float x){

return 2*cos(x);//f''

}

float Metod_Newton(float a, float b, float eps){
    /*Основная идея метода заключается в следующем: на отрезке
     * [a;b] выбирается такое число x0, при котором f(x0) имеет тот же знак,
     * что и f''(x0), т. е. выполняется условие f(x0)·f''(x0) > 0.
     *  Таким образом, выбирается точка с абсциссой x0, в которой касательная к кривой y=f(x)
     * на отрезке [a;b] пересекает ось Ox. За точку x0 сначала удобно выбирать один из концов отрезка*/

float x,x0, m = 0;

if (f(a)*f2(a)>0)
    x0 = a;
else x0 = b;

while (fabs(x - x0)>eps){
    x = x0;
    x0 = x - f(x) / f1(x);
    m++;
}

cout << " Iterations: " << m << endl;

return x;
}


float Metod_Relax(float a, float b, float eps){
float x, t, tau, m = 0;

if (f1(a)>0 && f1(b)>0){
     t = (a + b) / 2;
     tau = -2 / fabs(f1(a) + f1(b));
}else if (f1(a)<0 && f1(b)<0){
     t = (a + b) / 2;
     tau = 2 / fabs(f1(a) + f1(b));
}


while ((fabs(x - t)>eps) && (fabs(f(t))>eps)){
    x = t;
    t = x + tau*f(x);
    m++;
    }


cout << "Iterations: " << m << endl;
return t;

}


int main(){

float x, y, a, b, eps;
a=-3;
b=1;
eps = 0.00001;
x = Metod_Newton(a, b, eps);
cout << "Newton:" << x << endl;
x = Metod_Relax(a, b, eps);
cout << "Relaxation:" << x << endl;
return 0;

}







