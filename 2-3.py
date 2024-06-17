import numpy as np
import random

# Генерация случайных параметров гиперболы и координат точки
def generate_random_hyperbola_and_point():
    a = random.uniform(1, 10)
    b = random.uniform(1, 10)
    x0 = random.uniform(-20, 20)
    y0 = random.uniform(-20, 20)
    return a, b, x0, y0

# Проверка принадлежности точки гиперболе
def is_point_on_hyperbola(a, b, x0, y0):
    return np.isclose(x0**2 / a**2 - y0**2 / b**2, 1)

# Нахождение координат фокусов гиперболы
def find_foci(a, b):
    c = np.sqrt(a**2 + b**2)
    return (-c, 0), (c, 0)

# Нахождение эксцентриситета гиперболы
def find_eccentricity(a, b):
    return np.sqrt(1 + (b**2 / a**2))

# Нахождение расстояния между директрисами гиперболы
def find_distance_between_directrices(a, b):
    e = find_eccentricity(a, b)
    return 2 * a / e

# Генерация случайных параметров и точки
a, b, x0, y0 = generate_random_hyperbola_and_point()

print(f"Уравнение гиперболы: x^2/{a**2} - y^2/{b**2} = 1")
print(f"Точка: ({x0}, {y0})")

# Проверка принадлежности точки гиперболе
if is_point_on_hyperbola(a, b, x0, y0):
    print("Точка принадлежит гиперболе.")
else:
    print("Точка не принадлежит гиперболе.")

# Нахождение координат фокусов гиперболы
foci = find_foci(a, b)
print(f"Фокусы гиперболы: {foci}")

# Нахождение эксцентриситета гиперболы
eccentricity = find_eccentricity(a, b)
print(f"Эксцентриситет гиперболы: {eccentricity}")

# Нахождение расстояния между директрисами гиперболы
distance_directrices = find_distance_between_directrices(a, b)
print(f"Расстояние между директрисами гиперболы: {distance_directrices}")
