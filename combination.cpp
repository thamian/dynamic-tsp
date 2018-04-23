#include "combination.h"

Combination::Combination(int n, int subsetSize) {
    wasLastPermutation = false;
    this->n = n;
    this->subsetSize = subsetSize;
    
    for (int i = 0; i < n; i ++) {
        values.push_back(false);
    }
    std::fill(values.end() - subsetSize, values.end(), true);
}

std::vector<int> Combination::next() {
    std::vector<int> subset;
    
    if (wasLastPermutation)
        return subset;
    
    subset.reserve(subsetSize);
    
    for (int i = 0; i < n; ++i) {
        if (values[i])
            subset.push_back(i + 1);
    }    
    wasLastPermutation = !std::next_permutation(values.begin(), values.end());
    return subset;
}
