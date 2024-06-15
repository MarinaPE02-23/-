import numpy as np
def jacobi_iteration(A, b, initial_guess, max_iterations=100, tolerance=1e-6):
    n = len(A)
    x = initial_guess.copy()

    for iteration in range(max_iterations):
        x_new = np.zeros_like(x)

        for i in range(n):
            s = np.dot(A[i, :i], x[:i]) + np.dot(A[i, i+1:], x[i+1:])
            x_new[i] = (b[i] - s) / A[i, i]

        if np.linalg.norm(x_new - x) < tolerance:
            return x_new

        x = x_new

    return x
# Example usage:
A = np.array([[2, 2, 0], [-1, 2, -2], [-1, 2, 3]])
b = np.array([2, 3, 0])
initial_guess = np.zeros_like(b)
solution = jacobi_iteration(A, b, initial_guess)
print("Solution:", solution)