#include <iostream>

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int main() {
    int num1, num2;
    
    std::cout << "Введите два натуральных числа: ";
    std::cin >> num1 >> num2;
    
    int digits1 = countDigits(num1);
    int digits2 = countDigits(num2);
    
    if (digits1 > digits2) {
        std::cout << num1 << " содержит больше цифр чем " << num2 << std::endl;
    } else if (digits2 > digits1) {
        std::cout << num2 << " содержит больше цифр чем " << num1 << std::endl;
    } else {
        std::cout << "Оба числа содержат одинаковое количество цифр" << std::endl;
    }
    
    return 0;
}
