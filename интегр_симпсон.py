#Метод Симпсона
def simpson_rule(func, a, b, nseg):
    if nseg % 2 == 1:
        nseg += 1
    dx = 1.0 * (b - a) / nseg
    sum = (func(a) + 4 * func(a + dx) + func(b))
    nseg = int(nseg / 2)
    for i in range(1, nseg):
        sum += 2 * func(a + (2 * i) * dx) + 4 * func(a + (2 * i + 1) * dx)

    return sum * dx / 3

def func(x):
    return x**4*(8+x**2)**-1

from math import *

print("Используем метод Симпсона")
print("Интегрируемая функция: f(x) = x^4*(8+x^2)^-1")

a=1 
b=2 
nseg = 1000 

print('a = ', a ,', b = ', b , sep='')

int = simpson_rule(func, a, b, nseg)

print("\nОтвет: I =", int, "\nКоличество разбиений:", nseg)
