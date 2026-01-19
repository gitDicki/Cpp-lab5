#ifndef TXT_H
#define TXT_H

#include <string>

class Txt {
public:
    static void fillRandom(const std::string& filename, int count);
    
    static int difference(const std::string& filename);
};

#endif
