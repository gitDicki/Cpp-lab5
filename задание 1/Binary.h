#ifndef BINARY_H
#define BINARY_H

#include <string>
#include <vector>

class Binary {
public:
    
    bool fillRandom(const std::string& filename, int count);

    bool extract(const std::string& sourceFilename, const std::string& destFilename);

    std::vector<int> readAllNumbers(const std::string& filename);
};

#endif