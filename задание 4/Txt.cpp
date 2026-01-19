#include "Txt.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

void Txt::fillRandom(const std::string& filename, int count) {
    std::ofstream out(filename);
    if (!out) return;

    srand(time(0));
    std::cout << "Числа: ";
    for (int i = 0; i < count; ++i) {
        int num = rand() % 100;
        out << num << "\n";
        std::cout << num << " ";
    }
    std::cout << std::endl;
    out.close();
}

int Txt::difference(const std::string& filename) {
    std::ifstream in(filename);
    std::vector<int> numbers;
    int val;

    while (in >> val) numbers.push_back(val);
    in.close();

    int half = numbers.size() / 2;
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < numbers.size(); ++i) {
        if (i < half) sum1 += numbers[i];
        else sum2 += numbers[i];
    }
    
    return sum1 - sum2;
}

