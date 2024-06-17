#include <iostream>
#include <cmath>

using namespace std;

double f(double x1, double x2) {
    return x1 + 5 * x2 + exp(x1 * x1 + x2 * x2);
}

double partial_derivative_x1(double x1, double x2) {
    return 1 + 2 * x1 * exp(x1 * x1 + x2 * x2);
}

double partial_derivative_x2(double x1, double x2) {
    return 5 + 2 * x2 * exp(x1 * x1 + x2 * x2);
}

double coordinate_descent(double& x1, double& x2, double learning_rate, double tolerance, int max_iter) {
    for (int iter = 0; iter < max_iter; ++iter) {
        double prev_x1 = x1;
        double prev_x2 = x2;

        x1 = x1 - learning_rate * partial_derivative_x1(x1, x2);

        x2 = x2 - learning_rate * partial_derivative_x2(x1, x2);

        if (fabs(x1 - prev_x1) < tolerance && fabs(x2 - prev_x2) < tolerance) {
            break;
        }
    }

    return f(x1, x2);
}

int main() {
    double x1 = 1.0;
    double x2 = 1.0; 
    double learning_rate = 0.01;
    double tolerance = 1e-6;
    int max_iter = 10000;

    double optimal_value = coordinate_descent(x1, x2, learning_rate, tolerance, max_iter);

    cout << "Optimal value of the function: " << optimal_value << endl;
    cout << "Optimal point: (" << x1 << ", " << x2 << ")" << endl;

    return 0;
}
