#ifndef TRAVELLINGSALESMANPROBLEM_H
#define TRAVELLINGSALESMANPROBLEM_H

#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <string>
#include <utility>

#include "combination.h"
#include "convert.h"
#include "distancematrix.h"
#include "file.h"

class TravellingSalesmanProblem {

public:
    static std::vector<int> solveUsingDynamicProgramming(DistanceMatrix* distanceMatrix);
};

#endif //TRAVELLINGSALESMANPROBLEM_H
