#include <iostream>
#include <vector>

int main() {
    int size;
    std::cout << "Введите размер массивов: ";
    std::cin >> size;

    std::vector<int> arr1(size);
    std::vector<int> arr2(size);
    
    std::cout << "Введите элементы первого массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr1[i];
    }

    std::cout << "Введите элементы второго массива: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr2[i];
    }
    
    std::vector<int> arr3;
    
    for (int i = 0; i < size; ++i) {
        arr3.push_back(std::max(arr1[i], arr2[i]));
    }
    
    std::cout << "Третий массив: ";
    for (int num : arr3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
