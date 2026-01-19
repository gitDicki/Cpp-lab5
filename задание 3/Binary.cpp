#include "Binary.h"
#include <fstream>
#include <iostream>

bool Binary::fill(const std::string& filename, const std::vector<Baggage>& items) {
    std::ofstream outFile(filename, std::ios::binary);
    if (!outFile) return false;

    for (const auto& item : items) {
        outFile.write(reinterpret_cast<const char*>(&item), sizeof(Baggage));
    }
    outFile.close();
    return true;
}

std::vector<Baggage> Binary::readAll(const std::string& filename) {
    std::vector<Baggage> items;
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) return items;

    Baggage item;
    while (inFile.read(reinterpret_cast<char*>(&item), sizeof(Baggage))) {
        items.push_back(item);
    }
    inFile.close();
    return items;
}