#include "libraryobject.h"

LibraryObject::LibraryObject(File& file) {
    bool exit = false;
    while (!exit) {
        std::string command = file.getString();
        executeCommand(command, file);
        
        if (file.eof())
            exit = true;
    }
}

LibraryObject::~LibraryObject() {
    for (int i = 0; i < dimension; i++)
        delete [] matrix[i];
    delete [] matrix;
}

void LibraryObject::executeCommand(std::string command, File& file) {
    if (command == "DIMENSION" || command == "DIMENSION:") {
        std::string value = file.getString();
        if (value != ":") {
            dimension = Convert::toInt(value);
        } else {
            dimension = Convert::toInt(file.getString());
        }
    } else if (command == "EDGE_WEIGHT_TYPE" || command == "EDGE_WEIGHT_TYPE:") {
        std::string value = file.getString();
        if (value != ":") {
            edgeWeightType = value;
        } else {
            edgeWeightType = file.getString();
        }
    } else if (command == "EDGE_WEIGHT_FORMAT" || command == "EDGE_WEIGHT_FORMAT:") {
        std::string value = file.getString();
        if (value != ":") {
            edgeWeightFormat = value;
        } else {
            edgeWeightFormat = file.getString();
        }
    } else if (command == "NODE_COORD_SECTION" || command == "NODE_COORD_SECTION:") {
        
        
        
    } else if (command == "EDGE_WEIGHT_SECTION" || command == "EDGE_WEIGHT_SECTION:") {
        loadMatrix(file);
    } else {
        file.getLine();
    }    
}

DistanceMatrix* LibraryObject::toDistanceMatrix() {
    int** copyMatrix = new int*[dimension];
    for (int i = 0; i < dimension; i++)
        copyMatrix[i] = new int[dimension];
    
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            copyMatrix[i][j] = matrix[i][j];
    
    DistanceMatrix* distanceMatrix = new DistanceMatrix(dimension, copyMatrix);
    return distanceMatrix;
}

void LibraryObject::loadMatrix(File& file) {
    matrix = new int*[dimension];
    for (int i = 0; i < dimension; i++)
        matrix[i] = new int[dimension];
    
    if (edgeWeightType == "EXPLICIT" && edgeWeightFormat == "FULL_MATRIX") {
        loadFullMatrix(file);
    } else if (edgeWeightType == "EXPLICIT" && edgeWeightFormat == "UPPER_DIAG_ROW") {
        loadUpperDiagRow(file);
    } else if (edgeWeightType == "EXPLICIT" && edgeWeightFormat == "LOWER_DIAG_ROW") {
        loadLowerDiagRow(file);
    } else if (edgeWeightType == "EXPLICIT" && edgeWeightFormat == "UPPER_ROW") {
        loadUpperRow(file);
    } else if (edgeWeightType == "EXPLICIT" && edgeWeightFormat == "LOWER_ROW") {
        loadLowerRow(file);
    } else {
        std::cout << "error";
    }
    
    for (int i = 0; i < dimension; i++)
        matrix[i][i] = 0;
}

void LibraryObject::loadFullMatrix(File& file) {
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < dimension; j++)
            matrix[i][j] = file.getInt();
}

void LibraryObject::loadUpperDiagRow(File& file) {
    for (int i = 0; i < dimension; i++)
        for (int j = i; j < dimension; j++)
            matrix[i][j] = file.getInt();
    copyUpperToLower();
}

void LibraryObject::loadLowerDiagRow(File& file) {
    for (int i = 0; i < dimension; i++)
        for (int j = 0; j < i + 1; j++)
            matrix[i][j] = file.getInt();
    copyLowerToUpper();
}

void LibraryObject::loadUpperRow(File& file) {
    for (int i = 0; i < dimension; i++)
        for (int j = i + 1; j < dimension; j++)
            matrix[i][j] = file.getInt();
    copyUpperToLower();
}

void LibraryObject::loadLowerRow(File& file) {
    for (int i = 1; i < dimension; i++)
        for (int j = 0; j < i; j++)
            matrix[i][j] = file.getInt();
    copyLowerToUpper();
}

void LibraryObject::copyLowerToUpper() {
    for (int i = 1; i < dimension; i++)
        for (int j = 0; j < i; j++)
            matrix[j][i] = matrix[i][j];
}

void LibraryObject::copyUpperToLower() {
    for (int i = 0; i < dimension; i++)
        for (int j = i + 1; j < dimension; j++)
            matrix[j][i] = matrix[i][j];
}
