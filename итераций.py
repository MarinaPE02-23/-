#Метод итераций
from math import *

def example_function(x):
    return x*exp(x) - x - 1
def simple_iteration_method(x_0, epsilon):
    x = x_0
    iter = 0
    while True:

        x_new = x*exp(x) - x - 1
        if abs(x_new - x) < epsilon:
            print(f"Количество итераций: {iter}")            
            return x_new
        x = x_new
        iter +=1

x_0=0 #начальное значение
epsilon=1e-6 #точность
root = simple_iteration_method(x_0, epsilon)
print(f"Решение уравнения: x = {root}")
fun=example_function(root)
print(f"Значение функции: f({root})=",fun)

