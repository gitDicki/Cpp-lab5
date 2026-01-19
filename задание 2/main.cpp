#include "Binary.h"
#include <iostream>

int main() {
    Binary binary;

    int elements;
    std::cout << "Введите колличество чисел: ";
    std::cin >> elements;

    binary.fillRandom("numbers.bin", elements);
    std::vector<std::vector<int>> matrix;
    std::vector<int> minElements;
    std::vector<int> maxElements;

    binary.createMatrixFromFile("numbers.bin", matrix, minElements, maxElements);

    std::cout << "Исходная матрица:" << std::endl;
    binary.printMatrix(matrix);

    for (size_t i = 0; i < minElements.size(); ++i) {
        std::cout << "Строка " << i + 1 << ": Минимальный элемент = " << minElements[i]
                  << ", Максимальный элемент = " << maxElements[i] << std::endl;
    }

    for (size_t i = 0; i < matrix.size(); ++i) {
        binary.swapIter(matrix[i], minElements[i], maxElements[i]);
    }

    std::cout << "Матрица после замены минимальных и максимальных элементов:" << std::endl;
    binary.printMatrix(matrix);

}
