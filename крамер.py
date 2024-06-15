from sympy import symbols, Matrix
def cramer_rule(A, B):
    det_A = A.det()
    if det_A == 0:
        raise ValueError("Определитель матрицы коэффициентов равен нулю, метод Крамера не применим.")
    solutions = []
    for i in range(A.shape[0]):
        Ai = A.copy()
        Ai[:, i] = B
        solutions.append(Ai.det() / det_A)

    return solutions

x1, x2, x3 = symbols('x1 x2 x3')
A = Matrix([
    [2, 2, 0],
    [-1, 2, -2],
    [2, -2, 3],
])
B = Matrix([2, 3, 0])

try:
    solutions = cramer_rule(A, B)
    print("Решение методом Крамера:")
    for i, sol in enumerate(solutions, start=1):
        print(f"x{i} = {sol}")
except ValueError as e:
    print(e)