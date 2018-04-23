#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <limits>
#include <vector>

class Convert {
    
public:
    static int toBitMask(std::vector<int> vector);
    static int toInt(std::string string);
};

#endif // CONVERT_H
