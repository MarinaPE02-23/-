#include <iostream>
#include <cmath>
#include <random>

using namespace std;

// Структура для хранения координат точки
struct Point {
    double x, y, z;
};

// Структура для хранения параметров прямой
struct Line {
    Point a; // Точка на прямой
    Point d; // Направляющий вектор
};

// Функция для генерации случайного числа в диапазоне
double getRandomNumber(double min, double max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

// Функция для нахождения угла между двумя прямыми
double angleBetweenLines(const Line& l1, const Line& l2) {
    double dotProduct = l1.d.x * l2.d.x + l1.d.y * l2.d.y + l1.d.z * l2.d.z;
    double mag1 = sqrt(l1.d.x * l1.d.x + l1.d.y * l1.d.y + l1.d.z * l1.d.z);
    double mag2 = sqrt(l2.d.x * l2.d.x + l2.d.y * l2.d.y + l2.d.z * l2.d.z);
    return acos(dotProduct / (mag1 * mag2));
}

// Функция для определения параллельности прямых
bool areParallel(const Line& l1, const Line& l2) {
    double crossX = l1.d.y * l2.d.z - l1.d.z * l2.d.y;
    double crossY = l1.d.z * l2.d.x - l1.d.x * l2.d.z;
    double crossZ = l1.d.x * l2.d.y - l1.d.y * l2.d.x;
    return (crossX == 0 && crossY == 0 && crossZ == 0);
}

// Функция для нахождения расстояния между параллельными прямыми
double distanceBetweenParallelLines(const Line& l1, const Line& l2) {
    double num = fabs((l2.a.x - l1.a.x) * l1.d.y * l1.d.z +
                      (l2.a.y - l1.a.y) * l1.d.z * l1.d.x +
                      (l2.a.z - l1.a.z) * l1.d.x * l1.d.y);
    double den = sqrt(l1.d.x * l1.d.x + l1.d.y * l1.d.y + l1.d.z * l1.d.z);
    return num / den;
}

// Функция для нахождения расстояния от точки до прямой
double distanceFromPointToLine(const Line& l, const Point& p) {
    double num = sqrt(pow((p.y - l.a.y) * l.d.z - (p.z - l.a.z) * l.d.y, 2) +
                      pow((p.z - l.a.z) * l.d.x - (p.x - l.a.x) * l.d.z, 2) +
                      pow((p.x - l.a.x) * l.d.y - (p.y - l.a.y) * l.d.x, 2));
    double den = sqrt(l.d.x * l.d.x + l.d.y * l.d.y + l.d.z * l.d.z);
    return num / den;
}

// Функция для нахождения точки пересечения двух прямых
bool intersectionOfLines(const Line& l1, const Line& l2, Point& intersection) {
    // Находим пересечение прямых
    double a1 = l1.d.x, b1 = -l2.d.x, c1 = l2.a.x - l1.a.x;
    double a2 = l1.d.y, b2 = -l2.d.y, c2 = l2.a.y - l1.a.y;
    double a3 = l1.d.z, b3 = -l2.d.z, c3 = l2.a.z - l1.a.z;

    double det = a1 * (b2 * c3 - b3 * c2) - b1 * (a2 * c3 - a3 * c2) + c1 * (a2 * b3 - a3 * b2);
    
    if (fabs(det) < 1e-9) {
        return false; // Прямые не пересекаются
    }

    double t = ((l2.a.x - l1.a.x) * (l2.a.y * l1.d.z - l1.d.y * l2.a.z) -
                (l2.a.y - l1.a.y) * (l2.a.x * l1.d.z - l1.d.x * l2.a.z) +
                (l2.a.z - l1.a.z) * (l2.a.x * l1.d.y - l1.d.x * l2.a.y)) / det;

    intersection.x = l1.a.x + t * l1.d.x;
    intersection.y = l1.a.y + t * l1.d.y;
    intersection.z = l1.a.z + t * l1.d.z;
    
    return true;
}

int main() {
    // Генерация случайных параметров для двух прямых и координат точки
    Line l1 = { { getRandomNumber(-10, 10), getRandomNumber(-10, 10), getRandomNumber(-10, 10) }, 
                { getRandomNumber(-10, 10), getRandomNumber(-10, 10), getRandomNumber(-10, 10) } };
    Line l2 = { { getRandomNumber(-10, 10), getRandomNumber(-10, 10), getRandomNumber(-10, 10) }, 
                { getRandomNumber(-10, 10), getRandomNumber(-10, 10), getRandomNumber(-10, 10) } };
    Point p = { getRandomNumber(-10, 10), getRandomNumber(-10, 10), getRandomNumber(-10, 10) };

    // Вывод параметров прямых и координат точки
    cout << "Прямая 1: точка (" << l1.a.x << ", " << l1.a.y << ", " << l1.a.z << "), вектор ("
         << l1.d.x << ", " << l1.d.y << ", " << l1.d.z << ")" << endl;
    cout << "Прямая 2: точка (" << l2.a.x << ", " << l2.a.y << ", " << l2.a.z << "), вектор ("
         << l2.d.x << ", " << l2.d.y << ", " << l2.d.z << ")" << endl;
    cout << "Точка: (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;

    // Нахождение угла между прямыми
    double angle = angleBetweenLines(l1, l2) * 180.0 / M_PI; // перевод угла в градусы
    cout << "Угол между прямыми: " << angle << " градусов" << endl;

    // Определение параллельности прямых
    if (areParallel(l1, l2)) {
        cout << "Прямые параллельны." << endl;
        double distance = distanceBetweenParallelLines(l1, l2);
        cout << "Расстояние между параллельными прямыми: " << distance << endl;
    } else {
        cout << "Прямые не параллельны." << endl;
        Point intersection;
        if (intersectionOfLines(l1, l2, intersection)) {
            cout << "Точка пересечения прямых: (" << intersection.x << ", " << intersection.y << ", " << intersection.z << ")" << endl;
            double distanceToIntersection = sqrt(pow(p.x - intersection.x, 2) + pow(p.y - intersection.y, 2) + pow(p.z - intersection.z, 2));
            cout << "Расстояние от заданной точки до точки пересечения прямых: " << distanceToIntersection << endl;
        }
    }

    // Расчет расстояния от точки до каждой прямой
    double distance1 = distanceFromPointToLine(l1, p);
    double distance2 = distanceFromPointToLine(l2, p);
    cout << "Расстояние от точки до прямой 1: " << distance1 << endl;
    cout << "Расстояние от точки до прямой 2: " << distance2 << endl;

    return 0;
}
