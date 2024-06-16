#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>

using namespace std;


int main()
{ 
  double hl, hr, hc, h, fl, fr, fc, f2;
  double x[5] = { -1.0, 0.0, 1.0, 2.0, 3.0 };
  double y[5] = { -0.5, 0.0, 0.5, 1.86603, 1.0 };  
  h = 0.1; // шаг, с которым вычисляем производную
 
  // приближенно вычисляем первую производную различными способами при x=0
  hl = x[1]-x[0];
  fl = (y[1] - y[0]) / hl; // левая
  hr = x[2]-x[1];
  fr = (y[2] - y[1]) / hr; // правая
  hc=x[1]-x[0];
  fc = (y[2] - y[0]) / (2.0 * hc); // центральная
 
  // приближенно вычисляем вторую производную при x=0
  h=x[1]-x[0];
  f2 = (y[2] - 2 * y[1] + y[0]) / (h * h);
 
 // выводим результаты на экран
 cout<<"x = "<<x[1]<<"\n";
 cout<<"yl = "<<fl<<"\n";
 cout<<"yr = "<<fr<<"\n";
 cout<<"yc = "<<fc<<"\n";
 cout<<"y2 = "<<f2<<"\n";
 system("pause");
}