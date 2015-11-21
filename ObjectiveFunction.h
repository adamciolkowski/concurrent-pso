#ifndef CONCURRENT_PSO_OBJECTIVEFUNCTION_H
#define CONCURRENT_PSO_OBJECTIVEFUNCTION_H

#include <vector>

class ObjectiveFunction {

public:
    virtual int numberOfVariables() const = 0;
    virtual double fitness(const std::vector<double> &position) const = 0;
};

#endif //CONCURRENT_PSO_OBJECTIVEFUNCTION_H
