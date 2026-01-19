#include <iostream>
#include <limits>
#include "Txt.h"

void correctInput(int& value) {
    while (!(std::cin >> value)) {
        std::cout << "Ошибка: неверный ввод. Пожалуйста, введите число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    int n;
    std::cout << "Введите количество чисел: ";
    correctInput(n);
    
    Txt txt;
    std::string file = "data.txt";

    txt.fillRandom(file, n);

    int sum = txt.Summ(file);
    std::cout << "Сумма всех элементов в файле: " << sum << std::endl;
}
