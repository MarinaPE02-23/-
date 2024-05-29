//Метод дихотомии
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double func(double x)
{
  return x*exp(x)-x-1.0;
}
double find(double x0, double x1, double eps)
{
  double left = x0, right = x1, x, fl, fr, f;
  int iter = 0;
  cout << "a = " << x0 << "; b = " << x1 << "; ";
  do {
    x = (left + right) / 2;
    f = func(x);
    if (f > 0) right = x;
    else left = x;
    iter++;
  } while (fabs(f) > eps && iter<20000);
  cout <<"\nNumber of iterations is " << iter  << ". " << endl;
  return x;
}
int main() 
{
  double x0,x1,x,eps;
  cout << "a = ";
  cin >>x0;
  cout << "b = ";
  cin >>x1;
  cout << "eps = ";
  cin >>eps;
  x=find(x0,x1,eps);
  cout <<"Root x= "<< fixed << setprecision(16) << x;
  cout <<"\nFunction value f(x)="<< func(x);
  cin.get(); 
  return 0;
}
