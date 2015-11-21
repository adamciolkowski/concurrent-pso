#ifndef CONCURRENT_PSO_PARTICLE_H
#define CONCURRENT_PSO_PARTICLE_H

#include <vector>
#include "SwarmParams.h"
#include "Bounds.h"
#include "ObjectiveFunction.h"

class Particle {

public:
    Particle(const std::vector<double> &position, const std::vector<double> &velocity);

private:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> bestPosition;

    void update(std::vector<double> bestSwarmPosition, const Bounds &bounds, const ObjectiveFunction &function, const SwarmParams &params);

    void updateVelocity(const std::vector<double> &bestSwarmPosition, const SwarmParams &params);

    void updatePosition(const Bounds &bounds);

    void updateBestPosition(const ObjectiveFunction &objectiveFunction) {
        if(objectiveFunction.fitness(position) < objectiveFunction.fitness(bestPosition)) {
            bestPosition = position;
        }
    }

    static double constrict(double value, double min, double max) {
        if (value < min)
            return min;
        if (value > max)
            return max;
        return value;
    }
};

#endif //CONCURRENT_PSO_PARTICLE_H
