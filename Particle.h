#ifndef CONCURRENT_PSO_PARTICLE_H
#define CONCURRENT_PSO_PARTICLE_H

#include <vector>
#include "SwarmParams.h"
#include "Bounds.h"
#include "ObjectiveFunction.h"

class Particle {

public:
    Particle(const std::vector<double> &position, const std::vector<double> &velocity);

    void update(const std::vector<double> &bestSwarmPosition, const Bounds &bounds, ObjectiveFunction *function, const SwarmParams &params);

    std::vector<double> getPosition() const {
        return position;
    };
private:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> bestPosition;

    void updateVelocity(const std::vector<double> &bestSwarmPosition, const SwarmParams &params);

    void updatePosition(const Bounds &bounds);

    void updateBestPosition(ObjectiveFunction *objectiveFunction);

#pragma acc routine seq
    static double constrict(double value, double min, double max) {
        if (value < min)
            return min;
        if (value > max)
            return max;
        return value;
    }
};

#endif //CONCURRENT_PSO_PARTICLE_H
