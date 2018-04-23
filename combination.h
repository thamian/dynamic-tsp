#ifndef COMBINATION_H
#define COMBINATION_H

#include <algorithm>
#include <vector>

class Combination {
    bool wasLastPermutation;
    int n;
    int subsetSize;

    std::vector<bool> values;
    
public:
    Combination(int n, int subsetSize);
    std::vector<int> next();
};

#endif // COMBINATION_H
