#include "Binary.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    Binary binary;

    const std::string file1 = "numbers.bin";

    int elements = 20;
    std::cout << "Введите колличество чисел в исходном файле: ";
    std::cin >> elements;

    std::string file2 = "number2.bin";

    std::cout << "\n";
   
    if (binary.fillRandom(file1, elements)) {

        std::vector<int> sourceNumbers = binary.readAllNumbers(file1);
        if (!sourceNumbers.empty()) {
            for (int num : sourceNumbers) {
                std::cout << num << " ";
            }
            std::cout << "\n" << std::endl;

            if (binary.extract(file1, file2)) {

            std::cout << "Содержимое файла с четными числами: " << std::endl;
            std::vector<int> evenNumbers = binary.readAllNumbers(file2);
            if (!evenNumbers.empty()) {
                for (int num : evenNumbers) {
                    std::cout << num << " ";
                }
                std::cout << std::endl;
            }
        }
    } 
    else {
        std::cout << "Ошибка" << std::endl;
    }
    }
        
}