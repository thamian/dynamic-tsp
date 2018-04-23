#ifndef LIBRARYOBJECT_H
#define LIBRARYOBJECT_H

#include <memory>

#include "convert.h"
#include "distancematrix.h"
#include "file.h"

class LibraryObject {
    int dimension;
    int** matrix;
    std::string edgeWeightType;
    std::string edgeWeightFormat;
    
    void executeCommand(std::string command, File& file);
    
    void loadMatrix(File& file);
    void loadFullMatrix(File& file);
    void loadUpperDiagRow(File& file);
    void loadLowerDiagRow(File& file);
    void loadUpperRow(File& file);
    void loadLowerRow(File& file);
    
    void copyLowerToUpper();
    void copyUpperToLower();
    
public:
    LibraryObject(File& file);
    ~LibraryObject();
    
    DistanceMatrix* toDistanceMatrix();
};

#endif // LIBRARYOBJECT_H
