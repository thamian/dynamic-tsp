#include "distancematrix.h"

DistanceMatrix::DistanceMatrix(int size, int** matrix) {
    this->size = size;
    this->matrix = matrix;
}

DistanceMatrix::DistanceMatrix(File& file) {
    size = file.getInt();
    create();
    
    initialize(file);
    file.setPointerPosition(0);
}

DistanceMatrix::~DistanceMatrix() {
    for (int i = 0; i < size; i++)
        delete [] matrix[i];
    delete [] matrix;
}

void DistanceMatrix::create() {
    matrix = new int*[size];
    for (int i = 0; i < size; i++)
        matrix[i] = new int[size];
}

void DistanceMatrix::initialize(File& file) {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            matrix[i][j] = file.getInt();
}

int DistanceMatrix::getSize() const {
    return size;
}

int DistanceMatrix::getDistance(int i, int j) const {
    return matrix[i][j];
}

void DistanceMatrix::display() {
    Console::displayMatrix(matrix, size);
}
