"""Обобщённое правило прямоугольников с заданием точности."""

def _rectangle_rule(func, a, b, nseg, frac):
    dx = 1.0 * (b - a) / nseg
    sum = 0.0
    xstart = a + frac * dx 
    for i in range(nseg+1):
        sum += func(xstart + i * dx)
    return sum * dx

def func(x):
    return exp(-2*x)*sin(x*8)

from math import *

print("Используем метод прямоугольников.")
print("Интегрируемая функция: f(x) = exp(-2*x)*sin(x*8).")


a=1 # левый край отрезка интегрирования
b=0 # правый край отрезка интегрирования
nseg = 2 # начальное количество сегментов
eps=1e-6 # точность
frac=0.5


print('a = ', a ,', b = ', b ,', frac = ', frac ,', eps = ', eps, sep='')

int_1 = _rectangle_rule(func, a, b, nseg, frac)
nseg *= 2
int_2 = _rectangle_rule(func, a, b, nseg, frac)

while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = _rectangle_rule(func, a, b, nseg, frac)
    nseg *= 2
    int_2 = _rectangle_rule(func, a, b, nseg, frac)

print("\nОтвет: I =", int_2, "\nКоличество разбиений:", nseg)
