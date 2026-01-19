#include "Txt.h"
#include <iostream>
#include <fstream>
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

int Txt::Summ(const std::string& filename) {
    std::ifstream in(filename);
    int sum = 0;
    int val;

    while (in >> val) {
        sum += val;
    }
    return sum;
}
