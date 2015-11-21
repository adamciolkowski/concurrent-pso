#ifndef CONCURRENT_PSO_SIMPLEOBJECTTIVEFUNCTION_H
#define CONCURRENT_PSO_SIMPLEOBJECTTIVEFUNCTION_H

#include "ObjectiveFunction.h"

class SphereFunction : public ObjectiveFunction {

    int numberOfVariables() const {
        return 2;
    }

    double fitness(const std::vector<double> &x) const {
        return x[0] * x[0] + x[1] * x[1];
    }
};

#endif //CONCURRENT_PSO_SIMPLEOBJECTTIVEFUNCTION_H
