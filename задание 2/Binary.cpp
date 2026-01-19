#include "Binary.h"
#include <fstream>
#include <iostream>
#include <random>
#include <algorithm>

bool Binary::fillRandom(const std::string& filename, int count) {
    std::ofstream outFile(filename, std::ios::binary | std::ios::out);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл для записи." << std::endl;
        return false;
    }

    int minVal = 1;
    int maxVal = 100;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minVal, maxVal);

    for (int i = 0; i < count; ++i) {
        int randomNumber = distrib(gen);
        outFile.write(reinterpret_cast<const char*>(&randomNumber), sizeof(randomNumber));
    }

    outFile.close();
    return true;
}

bool Binary::extract(const std::string& sourceFilename, const std::string& destFilename) {
    std::ifstream inFile(sourceFilename, std::ios::binary);
    std::ofstream outFile(destFilename, std::ios::binary);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл." << std::endl;
        return false;
    }

    int number;
    while (inFile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        outFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
    }

    inFile.close();
    outFile.close();
    return true;
}

std::vector<int> Binary::readAllNumbers(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    std::vector<int> numbers;

    if (!inFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл для чтения." << std::endl;
        return numbers;
    }

    int number;
    while (inFile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        numbers.push_back(number);
    }

    inFile.close();
    return numbers;
}

void Binary::createMatrixFromFile(const std::string& filename, std::vector<std::vector<int>>& matrix, std::vector<int>& minElements, std::vector<int>& maxElements) {
    int n;

    std::cout << "Введите размер матрицы (n x n): ";
    std::cin >> n;

    std::vector<int> numbers = readAllNumbers(filename);
    matrix.resize(n, std::vector<int>(n, 0));
    
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i * n + j < numbers.size()) {
                matrix[i][j] = numbers[i * n + j];
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < n; ++i) {
        int minElem = *std::min_element(matrix[i].begin(), matrix[i].end());
        int maxElem = *std::max_element(matrix[i].begin(), matrix[i].end());
        minElements.push_back(minElem);
        maxElements.push_back(maxElem);
        swapIter(matrix[i], minElem, maxElem);
    }
}

void Binary::swapIter(std::vector<int>& row, int& minElem, int& maxElem) {
    auto min = std::find(row.begin(), row.end(), minElem);
    auto max = std::find(row.begin(), row.end(), maxElem);

    std::iter_swap(min, max);
}

void Binary::printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

