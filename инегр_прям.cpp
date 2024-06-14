#include <iostream>
#include <iomanip>
#include <cmath>
#include <math.h>
#include <cstdlib>

using namespace std;
 
double f(double x)
{
    return pow(x, 4) * sqrt(8 + pow(x, 2)); // Функция для интегрирования
}
 
int main()
{
    setlocale(LC_ALL, "rus");
    double a,b,x,h;
    int n_point;
    double sum = 0.0;
    cout<<"Введите нижний предел  a="; 
	cin>>a;
    cout<<"Введите верхний предел  b="; 
	cin>>b;
    cout<<"Введите число точек n="; 
	cin>>n_point; 
	
    h = double((b-a)/n_point);
    cout<<"Величина шага h="<<fixed<<setprecision(12)<<h<< endl; 
    for (x = a; x <=b; x+=h)
	  sum += f(x-h);
    sum*=h;
    cout <<"Значение интеграла для метода левых прямоугольников:"<<endl;
    cout <<"I="<<sum<<endl;

    for (x = a; x <=b; x+=h)
        sum += f(x-h/2);
    sum*=h;
    cout <<"Значение интеграла для метода прямоугольников со средней точкой:"<<endl;
    cout <<"I="<<sum<<endl;
        
    for (x = a; x <=b; x+=h)
        sum += f(x);
    sum*=h;
    cout <<"Значение интеграла для метода правых прямоугольников:"<<endl;
    cout <<"I="<<sum<<endl;
    
    return 0;
}
