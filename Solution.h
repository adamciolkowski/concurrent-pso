#ifndef CONCURRENT_PSO_SOLUTION_H
#define CONCURRENT_PSO_SOLUTION_H

#include <vector>
#include <iostream>

class Solution {
    friend std::ostream &operator<<(std::ostream &out, const Solution &s);

public:
    Solution(const std::vector<double> &position, double fitness);

private:
    std::vector<double> position;
    double fitness;
};

std::ostream &operator<<(std::ostream &out, const Solution &s);

#endif //CONCURRENT_PSO_SOLUTION_H
