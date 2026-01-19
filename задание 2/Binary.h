#ifndef BINARY_H
#define BINARY_H

#include <string>
#include <vector>

class Binary {
public:
    bool fillRandom(const std::string& filename, int count);

    bool extract(const std::string& sourceFilename, const std::string& destFilename);

    std::vector<int> readAllNumbers(const std::string& filename);

    void createMatrixFromFile(const std::string& filename, std::vector<std::vector<int>>& matrix, 
        std::vector<int>& minElements, std::vector<int>& maxElements);

    void swapIter(std::vector<int>& row, int& minElem, int& maxElem);

    void printMatrix(const std::vector<std::vector<int>>& matrix);
};

#endif
