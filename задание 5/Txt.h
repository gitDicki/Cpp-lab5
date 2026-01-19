#ifndef TXT_H
#define TXT_H

#include <string>

class Txt {
public:
    void fillRandom(const std::string& filename, int count);
    
    int Summ(const std::string& filename);
};

#endif
