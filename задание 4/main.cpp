#include <iostream>
#include <limits>
#include "Txt.h"

void correctInput(int& value) {
    while (true) {
        if (!(std::cin >> value)) {
            std::cout << "Ошибка: неверный ввод. Пожалуйста, введите число: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else if (value % 2 != 0) {
            std::cout << "Ошибка: число должно быть чётным. Попробуйте снова: ";
        } 
        else {
            break;
        }
    }
}

int main() {
    std::string file = "data.txt";
    int n;

    std::cout << "Введите количество чисел: ";
    correctInput(n);

    Txt::fillRandom(file, n);
    
    int result = Txt::difference(file);
    
    std::cout << "Разность суммы 1 и 2 половины: " << result << std::endl;

}
