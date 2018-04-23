#include "console.h"

std::string Console::getInput() {
    std::string input;
    std::cin >> input;
    return input;
}

void Console::print(std::string string) {
    std::cout << string;
}

void Console::println() {
    std::cout << "\n";
}

void Console::println(std::string string) {
    std::cout << string << "\n";
}

void Console::displayMatrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            std::cout << matrix[i][j] << "\t";
        std::cout << "\n";
    }
}

void Console::displayResult(std::vector<int> result) {
    int size = result.size();

    std::cout << "Road: " << result[0] << "\n";
    for (int i = size - 1; i > 1; i--) {
        std::cout << result[i] << " - ";
    }
    std::cout << result[1] << "\n";
}
