import numpy as np
import random

# Генерация случайных параметров гиперболического параболоида, плоскости, прямой и точки
def generate_random_parameters():
    a = random.uniform(1, 10)
    b = random.uniform(1, 10)
    A = random.uniform(-10, 10)
    B = random.uniform(-10, 10)
    C = random.uniform(-10, 10)
    D = random.uniform(-10, 10)
    r0 = np.array([random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10)])
    d = np.array([random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10)])
    point = np.array([random.uniform(-10, 10), random.uniform(-10, 10), random.uniform(-10, 10)])
    return a, b, A, B, C, D, r0, d, point

# Проверка принадлежности точки гиперболическому параболоиду
def is_point_on_hyperbolic_paraboloid(a, b, point):
    x, y, z = point
    return np.isclose(z, x**2 / a**2 - y**2 / b**2)

# Проверка пересечения плоскости и гиперболического параболоида
def does_plane_intersect_hyperbolic_paraboloid(a, b, A, B, C, D):
    # Замена z в уравнении плоскости на выражение гиперболического параболоида
    # A*x + B*y + C*(x**2 / a**2 - y**2 / b**2) + D = 0
    # Это уравнение имеет решения для некоторых x, y, если дискриминант квадратного уравнения по y >= 0
    coeff = [C / b**2, B - 2*C/a**2, A, D]
    roots = np.roots(coeff)
    return np.any(np.isreal(roots))

# Проверка пересечения прямой и гиперболического параболоида
def does_line_intersect_hyperbolic_paraboloid(a, b, r0, d):
    # Параметрическое уравнение прямой подставляем в уравнение гиперболического параболоида
    # z = (x0 + t*dx)^2 / a^2 - (y0 + t*dy)^2 / b^2
    t = np.linspace(-1000, 1000, 10000)  # проверка пересечения на большом промежутке
    x = r0[0] + t * d[0]
    y = r0[1] + t * d[1]
    z_line = r0[2] + t * d[2]
    z_paraboloid = x**2 / a**2 - y**2 / b**2
    return np.any(np.isclose(z_line, z_paraboloid, atol=1e-6))

# Генерация случайных параметров
a, b, A, B, C, D, r0, d, point = generate_random_parameters()

print(f"Уравнение гиперболического параболоида: z = x^2/{a**2} - y^2/{b**2}")
print(f"Уравнение плоскости: {A}x + {B}y + {C}z + {D} = 0")
print(f"Прямая: точка ({r0[0]}, {r0[1]}, {r0[2]}), вектор ({d[0]}, {d[1]}, {d[2]})")
print(f"Точка: ({point[0]}, {point[1]}, {point[2]})")

# Проверка принадлежности точки гиперболическому параболоиду
if is_point_on_hyperbolic_paraboloid(a, b, point):
    print("Точка принадлежит гиперболическому параболоиду.")
else:
    print("Точка не принадлежит гиперболическому параболоиду.")

# Проверка пересечения плоскости и гиперболического параболоида
if does_plane_intersect_hyperbolic_paraboloid(a, b, A, B, C, D):
    print("Плоскость пересекает гиперболический параболоид.")
else:
    print("Плоскость не пересекает гиперболический параболоид.")

# Проверка пересечения прямой и гиперболического параболоида
if does_line_intersect_hyperbolic_paraboloid(a, b, r0, d):
    print("Прямая пересекает гиперболический параболоид.")
else:
    print("Прямая не пересекает гиперболический параболоид.")
