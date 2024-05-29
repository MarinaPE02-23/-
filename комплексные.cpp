//Complex numbers
#include <iostream>
#include <math.h>
#include <complex>
#include <iomanip>
using namespace std;
 
int main() {
int n, k;
double real, imag, z_real, z_imag, n_rt, dn_rt;
complex< double > z( -1.0, -2.0 ); 
complex< double > z1( 1.0, 1.0 );
complex< double > z2( 4.0, -1.0 );

cout <<"z=" << z << endl; // Комплексное число выводится в виде вектора
cout << "z^sopr=" << conj( z ) << endl; // Комплексно-сопряженное
cout << "Re z=" <<  z.real() << endl; // Действительная часть комплексного числа
cout << "Im z=" << z.imag()  << endl; // Мнимая часть комплексного числа
cout << "z1 + z2=" <<  z1 + z2 << endl; // Сложение комплексных чисел
cout << "z1 - z2=" << z1 - z2 << endl; // Разность комплексных чисел
cout << "z1 * z2=" << z1 * z2 << endl; // Умножение комплексных чисел
cout << "z1 / z2=" << z1 / z2 << endl; // Деление комплексных чисел
cout << "z^3=" << pow( z, 3 ) << endl; // Возведение в степень комплексного числа
double rho = abs( z ); // Модуль комплексного числа
double phi = arg( z ); // Аргумент комплексного числа
// Тригонометрическая форма комплексного числа
cout << "z=" << rho << "*(cos(" << phi << ") + i*sin(" << phi << "))" << endl;
// Показательная форма комплексного числа
cout <<"z=" << rho << "*exp(i*" << phi << ")" << endl;
// Получаем исходное комплексное число по модулю и аргументу
cout << "z=" << polar( rho, phi ) << endl;

// Извлесение корня n степени из комплексного числа
cout << "Input complex number " ; 
cin >> real >> imag; // Ввод действительной и мнимой части через пробел
complex<double> zp(real, imag);
cout << fixed << setprecision(16) << zp << endl;
cout << "Input number n_root " ;
cin >> n_rt;
cout << "\n";
rho = abs( zp );
phi = arg( zp );
cout << "rho=" << rho << ", phi=" << phi << endl;
dn_rt = 1.0/n_rt;
for(k=0; k<n_rt; k++)
{ 
	z_real = pow( rho, float (1/n_rt)) * cos((phi + 2 * M_PI * k) / n_rt);
    z_imag = pow( rho, float (1/n_rt)) * sin((phi + 2 * M_PI * k) / n_rt);
    complex<double> z_n(z_real, z_imag);
    cout << "k=" <<k<<  ", z_k=" << z_n << "\n";
}
    

return 0;
}


