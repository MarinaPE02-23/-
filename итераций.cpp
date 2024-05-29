////Метод итераций
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double func(double x)
{
  return x*exp(x)-x-1.0;
}

double find(double x, double eps)
{
  double x_1, x_2; 
  int iter = 0;
  x_2 = x;
  do {
    x_1=x_2;
    x_2 = x*exp(x)-1.0;
    cout << x_2 << "\n";
    iter++;
  } while (fabs(x_2 - x_1) > eps && iter<20);
  cout <<"\nNumber of iterations is " << iter  << endl;
  return x_2;
}
int main() 
{ 
  double x0, eps, root;
  cout << "x_0 = ";
  cin >>x0;
  cout << "eps = ";
  cin >>eps;
  root=find(x0, eps);
  cout <<"Root x = "<< fixed << setprecision(16) << root;
  cout <<"\nFunction value f(x)="<< func(root);
  cin.get(); 
  return 0;
}

