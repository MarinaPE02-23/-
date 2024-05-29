#Метод хорд (секущих)
import math

def example_function(x):
    return x* math.exp(x)- x - 1

def chord_method(f, a, b, eps, max_iter):
    iteration = 0
    if f(a) * f(b) >= 0:
        return None

    x = a - (b - a) * f(a) / (f(b) - f(a))

    for _ in range(max_iter):
        if abs(f(x)) < eps:
            break

        if f(a) * f(x) < 0:
            b = x
        else:
            a = x

        x = a - (b - a) * f(a) / (f(b) - f(a))
        iteration += 1
    print(f"Количество итераций: {iteration}")
    return x

a=0 #левый край
b=3 #правый край
epsilon=1e-6  #точность
max_iter=1000
root = chord_method(example_function, a, b, epsilon, max_iter)
print(f"Корень уравнения: {root}")
fun=example_function(root)
print(f"Значение функции: f({root})=",fun)
