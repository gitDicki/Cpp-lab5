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
    std::ifstream inFile(sourceFilename, std::ios::binary | std::ios::in);
    if (!inFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть исходный файл '" << sourceFilename << "' для чтения." << std::endl;
        return false;
    }

    std::ofstream outFile(destFilename, std::ios::binary | std::ios::out);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть целевой файл '" << destFilename << "' для записи." << std::endl;
        inFile.close();
        return false;
    }

    int number;
    int evenCount = 0;

    while (inFile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        if (number % 2 == 0) {
            outFile.write(reinterpret_cast<const char*>(&number), sizeof(number));
            evenCount++;
        }
    }

    inFile.close();
    outFile.close();
    std::cout << "Найдено " << evenCount << " четных чисел" << std::endl;
    return true;
}

std::vector<int> Binary::readAllNumbers(const std::string& filename) {
    std::vector<int> numbers;
    std::ifstream inFile(filename, std::ios::binary | std::ios::in);

    if (!inFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл '" << filename << "' для чтения." << std::endl;
        return numbers;
    }

    int number;
    while (inFile.read(reinterpret_cast<char*>(&number), sizeof(number))) {
        numbers.push_back(number);
    }

    inFile.close();
    return numbers;
}