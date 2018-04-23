#include "travellingsalesmanproblem.h"

std::vector<int> TravellingSalesmanProblem::solveUsingDynamicProgramming(DistanceMatrix* distanceMatrix) {
    int n = distanceMatrix->getSize();
    
    std::unique_ptr<
        std::map<std::pair<int, int>, std::pair<int, int>>
    > table(new std::map<std::pair<int, int>, std::pair<int, int>>);      // K(subset (to get currentCity, contains currentCity), currentCity) V(road (through subset to currentCity), previousCity)
        
    for (int i = 1; i < n; i++) {
        std::pair<int, int> key(1 << i, i);                                 // K(subset, currentCity)
        std::pair<int, int> value(distanceMatrix->getDistance(0, i), 0);    // V(road, previousCity)
        
        table->insert(std::make_pair(key, value));
    }    
    
    for (int subsetSize = 2; subsetSize < n; subsetSize++) {
        Combination combination(n - 1, subsetSize);
        
        for (std::vector<int> subset = combination.next(); !subset.empty(); subset = combination.next()) {
            int subsetMask = Convert::toBitMask(subset);
            
            for (int currentCity : subset) {
                int cSubsetMask = subsetMask & ~(1 << currentCity); // subset to get previousCity
                
                std::pair<int, int> value(std::numeric_limits<int>::max(), 0);
                for (int previousCity : subset) {
                    if (previousCity == 0 || previousCity == currentCity) {
                        continue;
                    }
                    auto oldValue = table->find(std::make_pair(cSubsetMask, previousCity))->second;
                    
                    int oldRoad = oldValue.first;  // droga dotarcia do previousCity
                    
                    std::pair<int, int> candidateValue(oldRoad + distanceMatrix->getDistance(previousCity, currentCity), previousCity);
                    
                    if (candidateValue.first < value.first) {
                        value = candidateValue;
                    }
                }
                
                std::pair<int, int> key(subsetMask, currentCity);
                
                table->insert(std::make_pair(key, value));
            }
        }
    }
    
    int lastSubset = std::pow(2, n) - 2;
    
    std::pair<int, int> value(std::numeric_limits<int>::max() / 2, 0);
    for (int i = 1; i < n; i++) {
        auto oldValue = table->find(std::make_pair(lastSubset, i))->second;
        
        int oldRoad = oldValue.first;
        
        std::pair<int, int> candidateValue(oldRoad + distanceMatrix->getDistance(i, 0), i);
        
        if (candidateValue.first < value.first) {
            value = candidateValue;
        }
    }

    int road = value.first;
    int parent = value.second;

    std::vector<int> result;
    result.push_back(road);
    result.push_back(0);
    for (int i = 0; i < n - 1; i++) {
        result.push_back(parent);

        int subset = lastSubset & ~(1 << parent);
        auto previousValue = table->find(std::make_pair(lastSubset, parent))->second;
        parent = previousValue.second;
        lastSubset = subset;
    }
    result.push_back(0);

    return result;
}
