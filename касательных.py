#Метод касательных
from math import *
def example_function(x):
    return x*exp(x) - x - 1

#Производная
def derivative_example_function(x):
    return x* exp(x) + exp(x) - 1

def tangent_method(f, df, x0, epsilon, max_iter):
    x = x0
    for i in range(max_iter):
        f_x = f(x)
        f_derivative = df(x)
        x_new = x - f_x / f_derivative

        if abs(x_new - x) < epsilon:
            return x_new, i + 1
        x = x_new

    return None, max_iter

x0 = 1  #начальное значение
epsilon = 1e-6 #точность
max_iter=100 # число итераций
root, iterations = tangent_method(example_function, derivative_example_function, x0, epsilon, max_iter)

print(f"Корень уравнения: {root:.12f}")
print(f"Количество итераций: {iterations}")
fun=example_function(root)
print(f"Значение функции: f({root})=",fun)
