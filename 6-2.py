import numpy as np

def f(x1, x2):
    return x1 + 2 * x2 + 4 * np.sqrt(1 + x1**2 + x2**2)

def grad_f(x1, x2):
    common_term = 4 / np.sqrt(1 + x1**2 + x2**2)
    df_dx1 = 1 + x1 * common_term
    df_dx2 = 2 + x2 * common_term
    return np.array([df_dx1, df_dx2])

def line_search(x, grad, alpha=1.0, beta=0.5, sigma=1e-4):
    t = alpha
    while f(x[0] - t * grad[0], x[1] - t * grad[1]) > f(x[0], x[1]) - sigma * t * np.dot(grad, grad):
        t *= beta
    return t

def steepest_descent(x_init, learning_rate=1.0, tolerance=1e-6, max_iter=1000):
    x = np.array(x_init)
    for i in range(max_iter):
        grad = grad_f(x[0], x[1])
        if np.linalg.norm(grad) < tolerance:
            break
        step_size = line_search(x, grad)
        x = x - step_size * grad
    return x, f(x[0], x[1])

x_init = [1.0, 1.0]  # Начальная точка
opt_point, opt_value = steepest_descent(x_init)

print(f"Optimal value of the function: {opt_value}")
print(f"Optimal point: ({opt_point[0]}, {opt_point[1]})")
