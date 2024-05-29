//Метод касательных
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double func(double x)
{
  return x * exp(x) - x - 1;
}

double dfunc(double x)
{
  return x*exp(x) + exp(x) - 1;
}

double find(double x, double eps)
{
  double f, df; int iter = 0;
  cout << "x_0 = " << x << " ";
  do {
    f = func(x);
    df = dfunc(x);
    x = x - f / df;
    iter++;
  } while (fabs(f) > eps && iter<20000);
  cout <<"\nNumber of iterations is " << iter  << endl;
  return x;
}
int main() 
{
  double x0, x, eps;
  cout << "x_0 = ";
  cin >>x0;
  cout << "eps = ";
  cin >>eps;
  x=find(x0,eps);
  cout <<"Root x = "<< fixed << setprecision(16) << x;
  cout <<"\nFunction value f(x)="<< func(x);
  cin.get(); 
  return 0;
}
