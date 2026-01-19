#ifndef BINARY_H
#define BINARY_H

#include <string>
#include <vector>

struct Baggage {
    char name[50];
    double weight;
};

class Binary {
public:
    bool fill(const std::string& filename, const std::vector<Baggage>& items);

    std::vector<Baggage> readAll(const std::string& filename);
};

#endif