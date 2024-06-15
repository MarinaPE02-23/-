#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
using namespace std;
 
int main()
{
//Объявляем переменные:
int i, j, n, m;
 
//Создаем массив:
    cout << "Enter the number of equations:" << endl;
         cin >> n;
 
         m = n + 1;
    float **matrix = new float *[n];
         for (i=0; i<n; i++)
             matrix[i] = new float [m];
 
//Инициализируем:
    for (i = 0; i<n; i++)
    {
        for (j = 0; j<m; j++)
        {
            if (j == n)
            {
                cout << "This element is the value of the " << i+1 <<" line:" << endl;
            }
            cout << "Element: " << "[" << i+1 << ";" << j+1 << "]: "<<endl;
            cin >> matrix[i][j];
            cout << endl;
        }
    }
 
//Выводим массив:
cout << "Matrix: " << endl;
 
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            if (j == n)
            {
                cout << "|";
            }
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
 
cout << endl;
 
int k, nl, nc;
float o=0;//Перемнная для поиска самого большого по модулю элемента в матрице. 
float p=0;//Перемнная для поиска самого большого по модулю элемента в матрице.
float tmp=0;//Временная перемнная для прямого хода метода Гаусса.
float *xx = new float[m];//Массив-результат решения методом Гаусса без учета перемены столбцов местами.
int z;//Переменная для приведения к верхнетреугольному виду.
 
for (k=0; k<n; k++)
{   
 
//Поиск ведущего элемента:
for (i=k; i<n; i++)
    {
        for (j=k; j<n; j++)
        {
            o=fabs(matrix[i][j]);
            if (fabs(o)>fabs(p))
            {
                p=fabs(o);//Нашли значение самого большого элемента.
                nl=i;//Нашли номер строки с самым большим элементом.
                nc=j;//Нашли номер столбца с самым большим элементом.
            }
        }
    }
 
//Перестановка строк:
if (nl!=0)
{
     for(i=k; i<n+1; i++)
    {
            float tmp_line = 0;//Временная переменная для перестановки строк местами.
            tmp_line = matrix[nl][i];
            matrix[nl][i] = matrix[k][i];
            matrix[k][i] = tmp_line;
    }
}
 
 
//Прямой ход, приведение к верхнетреугольному виду:
    for (i=k; i<n; i++)
     {
       tmp=matrix[i][i];
         for (j=n;j>=i;j--)//Нормализация.
         {
             matrix[i][j]=matrix[i][j]/tmp;
         }
           for (j=i+1;j<n;j++)
          {
             tmp=matrix[j][i];
               for (z=n;z>=i;z--)
             matrix[j][z]=matrix[j][z]-tmp*matrix[i][z];
          }
      }
}
 
//Выводим массив после поиска ведущего элемента, его перестановки,нормализации и приведения матрицы к верхнетреугольному виду:
cout << "Matrix (after conversion): " << endl;
    for (i=0; i<n; i++)
    {
        for (j=0; j<m; j++)
        {
            if (j == n)
            {
                cout << "|";
            }
            cout << matrix[i][j]<<" ";
        }
        cout << endl;
    }
cout << endl;
 
//Обратный ход:
    xx[n-1] = matrix[n-1][n];
     for (i=n-2; i>=0; i--)
       {
           xx[i] = matrix[i][n];
           for (j=i+1;j<n;j++)
           {
               xx[i]=xx[i]-matrix[i][j]*xx[j];
           }
       }
 
//Выводим решения
    for (i=0; i<n; i++)
    {
        cout << xx[i] << " ";
        cout << endl;
    }
 
//Удаляем массив:
delete[] matrix;
 
getch();
return 0;
}