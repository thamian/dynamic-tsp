#include "convert.h"

int Convert::toBitMask(std::vector<int> vector) {
    int bitMask = 0;
    
    for (int i = 0; i < vector.size(); i++) {
        bitMask |= 1 << vector[i];
    }
    
    return bitMask;
}

int Convert::toInt(std::string string) {
    int i;
    
    try {
        i = std::stoi(string);
    } catch (std::invalid_argument& e) {
        return std::numeric_limits<int>::min();     // Minimalna wartość liczby całkowitej działa jako kod błędu.
    }
    
    return i;
}
