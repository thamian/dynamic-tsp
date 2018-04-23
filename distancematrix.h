#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <iostream>

#include "console.h"
#include "file.h"

class DistanceMatrix {
    int size;
    int** matrix;
    
    void create();
    
    void initialize(File& file);
    
public:
    DistanceMatrix(int size, int** matrix);
    DistanceMatrix(File& file);
    ~DistanceMatrix();

    int getDistance(int i, int j) const;
    int getSize() const;
    
    void display();
};

#endif //SQUAREMATRIX_H
