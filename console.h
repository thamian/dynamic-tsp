#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

#include "convert.h"
#include "message.h"
#include "distancematrix.h"

class Console {
    
public:
    static std::string getInput();

    static void print(std::string string);
    static void println();
    static void println(std::string string);

    static void displayMatrix(int** matrix, int size);
    static void displayResult(std::vector<int> result);
};

#endif //CONSOLE_H
