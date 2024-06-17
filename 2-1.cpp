#include <iostream>
#include <cmath>
#include <random>

using namespace std;

// Структура для хранения координат точки
struct Point {
    double x;
    double y;
};

// Функция для генерации случайного числа в диапазоне
double getRandomNumber(double min, double max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

// Функция для нахождения расстояния от точки до прямой ax + by + c = 0
double distanceFromPointToLine(double a, double b, double c, const Point& p) {
    return fabs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
}

// Функция для нахождения точки пересечения двух прямых
Point intersectionOfLines(double a1, double b1, double c1, double a2, double b2, double c2) {
    Point intersection;
    double det = a1 * b2 - a2 * b1;
    if (det == 0) {
        cerr << "Прямые параллельны и не пересекаются." << endl;
        exit(1); // Выход из программы
    } else {
        intersection.x = (b2 * c1 - b1 * c2) / det;
        intersection.y = (a1 * c2 - a2 * c1) / det;
    }
    return intersection;
}

// Функция для нахождения угла между двумя прямыми
double angleBetweenLines(double a1, double b1, double a2, double b2) {
    double dotProduct = a1 * a2 + b1 * b2;
    double mag1 = sqrt(a1 * a1 + b1 * b1);
    double mag2 = sqrt(a2 * a2 + b2 * b2);
    return acos(dotProduct / (mag1 * mag2));
}

int main() {
    // Генерация случайных параметров прямых и координат точки
    double a1 = getRandomNumber(-10, 10);
    double b1 = getRandomNumber(-10, 10);
    double c1 = getRandomNumber(-10, 10);
    double a2 = getRandomNumber(-10, 10);
    double b2 = getRandomNumber(-10, 10);
    double c2 = getRandomNumber(-10, 10);
    Point p = { getRandomNumber(-10, 10), getRandomNumber(-10, 10) };

    cout << "Прямая 1: " << a1 << "x + " << b1 << "y + " << c1 << " = 0" << endl;
    cout << "Прямая 2: " << a2 << "x + " << b2 << "y + " << c2 << " = 0" << endl;
    cout << "Точка: (" << p.x << ", " << p.y << ")" << endl;

    // Расчет расстояний от точки до прямых
    double distance1 = distanceFromPointToLine(a1, b1, c1, p);
    double distance2 = distanceFromPointToLine(a2, b2, c2, p);
    cout << "Расстояние от точки до прямой 1: " << distance1 << endl;
    cout << "Расстояние от точки до прямой 2: " << distance2 << endl;

    // Нахождение точки пересечения прямых
    Point intersection = intersectionOfLines(a1, b1, c1, a2, b2, c2);
    cout << "Точка пересечения прямых: (" << intersection.x << ", " << intersection.y << ")" << endl;

    // Расчет расстояния от заданной точки до точки пересечения прямых
    double distanceToIntersection = sqrt(pow(p.x - intersection.x, 2) + pow(p.y - intersection.y, 2));
    cout << "Расстояние от заданной точки до точки пересечения прямых: " << distanceToIntersection << endl;

    // Расчет угла между прямыми
    double angle = angleBetweenLines(a1, b1, a2, b2) * 180.0 / M_PI; // перевод угла в градусы
    cout << "Угол между прямыми: " << angle << " градусов" << endl;

    return 0;
}
