#ifndef CONCURRENT_PSO_OBJECTIVEFUNCTION_H
#define CONCURRENT_PSO_OBJECTIVEFUNCTION_H

#include <vector>

class ObjectiveFunction {

public:
    virtual int fitness(const std::vector<double> &position) const = 0;
};

#endif //CONCURRENT_PSO_OBJECTIVEFUNCTION_H
