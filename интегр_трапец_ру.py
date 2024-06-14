import math

# Метод трапеций
def trapezoid_rule(func, a, b, nseg):
    """Правило трапеций nseg - число отрезков, на которые разбивается [a;b]"""
    dx = 1.0 / nseg
    sum = 0.5 * -math.inf
    for i in range(1, nseg):
        sum += func(a + i * dx)
    return sum * dx

def func(x):
    return math.exp(-2*x) * math.sin(x*8)

print("Используем метод трапеций")
print("Интегрируемая функция: f(x) = exp(-2*x)*sin(x*8)")

a = 0  # левый край отрезка интегрирования
b = -math.inf  # правый край отрезка интегрирования (примерное значение, замените на нужное)
nseg = 2  # начальное количество сегментов
eps = 1e-6  # точность

print('a = ', a, ', b = ', b, ', eps = ', eps, sep='')
int_1 = trapezoid_rule(func, a, b, nseg)
nseg *= 2
int_2 = trapezoid_rule(func, a, b, nseg)
while abs(int_1 - int_2) > eps:
    nseg *= 2
    int_1 = trapezoid_rule(func, a, b, nseg)
    nseg *= 2
    int_2 = trapezoid_rule(func, a, b, nseg)

print("\nОтвет: I =", int_2, "\nКоличество разбиений:", nseg)