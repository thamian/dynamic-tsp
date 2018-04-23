#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <chrono>
#include <random>

#include "console.h"
#include "file.h"
#include "libraryobject.h"
#include "travellingsalesmanproblem.h"

class Controller {
    File file;

    bool loadFile(std::string filename);
    void travellingSalesmanProblem();
    
public:
    void start();
    void test();
};

#endif //CONTROLLER_H
