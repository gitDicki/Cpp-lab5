#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>
#include "Binary.h"

void correctInput(double& value) {
    while (!(std::cin >> value)) {
        std::cout << "Ошибка: неверный ввод. Пожалуйста, введите число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

int main() {
    double m;

    std::cout << "Введите m: "; 
    correctInput(m);

    std::string filename = "Baggage.bin";
    Binary L;

    std::vector<Baggage> initialData = {
        {"Чемодан", 0.0},
        {"Сумка", 0.0},
        {"Коробка", 0.0},
        {"Рюкзак", 0.0},
        {"Ящик", 0.0}
    };
    
    std::cout << "Введите вес 5 предметов:\n";
    for (int i = 0; i < initialData.size(); ++i) {
        std::cout << initialData[i].name << ": ";
        correctInput(initialData[i].weight);
    }

    L.fill(filename, initialData);

    std::vector<Baggage> allBaggage = L.readAll(filename);
    if (allBaggage.empty()) return 1;

    double totalWeight = 0;
    for (const auto& item : allBaggage) {
        totalWeight += item.weight;
    }
    double average = totalWeight / allBaggage.size();

    std::cout << "\nОбщая средняя масса: " << std::fixed << std::setprecision(2) << average << " кг\n";
    std::cout << "Порог отклонения m: " << m << " кг\n\n";
    std::cout << "Подходящий багаж:\n";

    bool found = false;
    for (const auto& item : allBaggage) {
        if (std::abs(item.weight - average) <= m) {
            std::cout << "- " << item.name << " (масса: " << item.weight << " кг)" << std::endl;
            found = true;
        }
    }

    if (!found) std::cout << "Ни один багаж не подходит под условие." << std::endl;
}