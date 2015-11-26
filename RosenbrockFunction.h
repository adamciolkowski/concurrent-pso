#ifndef CONCURRENT_PSO_SIMPLEOBJECTTIVEFUNCTION_H
#define CONCURRENT_PSO_SIMPLEOBJECTTIVEFUNCTION_H

#include "ObjectiveFunction.h"

class RosenbrockFunction : public ObjectiveFunction {

private:
    int dimensions;
public:
    RosenbrockFunction(int dimensions) :
            dimensions(dimensions) { }

    int numberOfVariables() const {
        return dimensions;
    }

    double fitness(const std::vector<double> &x) const {
        double f = 0;
        for (int i = 0; i < x.size() - 1; i++) {
            f += 100 * pow(x[i + 1] - pow(x[i], 2), 2) + pow(x[i] - 1, 2);
        }
        return f;
    }
};

#endif //CONCURRENT_PSO_SIMPLEOBJECTTIVEFUNCTION_H
