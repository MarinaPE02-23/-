// Метод трапеций без задания точности
#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>
using namespace std;

// Функция вычисления определенного интеграла
double Integral(double *f, double step, int n) {
  int i;
  double sum = 0;
  sum = 0.5 * (f[0] + f[n-1]);
  for (i = 1; i < n-1; i++) 
    sum += f[i];
  sum *= step;
  return sum;
}
int main() {
  setlocale(LC_ALL, "rus");
  double *f;
  double a, b; 
  double step, x;
  double sum=0.0;
  int i, n_point;
    cout<<"Введите нижний предел  a="; 
	cin>>a;
    cout<<"Введите верхний предел  b="; 
	cin>>b;
    cout<<"Введите число точек n="; 
	cin>>n_point; 
  f = (double*)malloc(n_point * sizeof(double));
  step = (b-a) / n_point; // величина шага (высота трапеций)
      cout<<"Величина шага h="<<fixed<<setprecision(12)<<step<< endl; 
  x = 0.0;
  // Инициализация значений функции f(t)
  for (i = 0; i<n_point; i++) {
    f[i] = pow(x, 4) * sqrt(8 + pow(x, 2)); // Функция для интегрирования
    x += step;
  }
  sum = Integral(f, step, n_point); // вычисление интеграла
  cout<<"Значение интеграла I="<<sum<< endl;
  return 0;
}