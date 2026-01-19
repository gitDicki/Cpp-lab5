#include "Txt.h"
#include <fstream>
#include <iostream>
#include <vector>

void Txt::shortestLongest(const std::string& inp, const std::string& out) {
    std::ifstream inFile(inp);
    if (!inFile.is_open()) return;

    std::string line, shortest, longest;
    bool first = true;

    while (std::getline(inFile, line)) {
        if (first) {
            shortest = longest = line;
            first = false;
        } else {
            if (line.length() < shortest.length()) shortest = line;
            if (line.length() > longest.length()) longest = line;
        }
    }
    inFile.close();

    std::ofstream outFile(out);
    if (outFile.is_open() && !first) {
        std::cout << "Самая короткая: " << shortest << std::endl;
        std::cout << "Самая длинная: " << longest << std::endl;

        outFile << shortest << std::endl;
        outFile << longest << std::endl;
        outFile.close();
    }
}
