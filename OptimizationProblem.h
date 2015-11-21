#ifndef CONCURRENT_PSO_OPTIMIZATIONPROBLEM_H
#define CONCURRENT_PSO_OPTIMIZATIONPROBLEM_H

#include "Bounds.h"
#include "ObjectiveFunction.h"

class OptimizationProblem {

public:
    OptimizationProblem(ObjectiveFunction *objectiveFunction, const Bounds &bounds) :
            objectiveFunction(objectiveFunction), bounds(bounds) { }

    ObjectiveFunction *getObjectiveFunction() const {
        return objectiveFunction;
    };

    Bounds getBounds() const {
        return bounds;
    };
private:
    ObjectiveFunction *objectiveFunction;
    Bounds bounds;
};

#endif //CONCURRENT_PSO_OPTIMIZATIONPROBLEM_H
