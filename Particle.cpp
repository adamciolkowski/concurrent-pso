#include <iostream>
#include "Particle.h"

#pragma acc routine seq
void Particle::update(const std::vector<double> &bestSwarmPosition, const Bounds &bounds, ObjectiveFunction *function, const SwarmParams &params) {
    updateVelocity(bestSwarmPosition, params);
    updatePosition(bounds);
    updateBestPosition(function);
}

Particle::Particle(const std::vector<double> &position, const std::vector<double> &velocity) :
        position(position), velocity(velocity), bestPosition(position) {
}

#pragma acc routine seq
void Particle::updateVelocity(const std::vector<double> &bestSwarmPosition, const SwarmParams &params) {
    for (int d = 0; d < velocity.size(); d++) {
        velocity[d] = params.getInertiaFactor() * velocity[d] +
                      params.getPersonalWeight() * (bestPosition[d] - position[d]) +
                      params.getGlobalWeight() * (bestSwarmPosition[d] - position[d]);
    }
}

#pragma acc routine seq
void Particle::updatePosition(const Bounds &bounds) {
    for (int d = 0; d < position.size(); d++) {
        double sum = position[d] + velocity[d];
        position[d] = constrict(sum, bounds.lowerBound(d), bounds.upperBound(d));
    }
}

#pragma acc routine seq
void Particle::updateBestPosition(ObjectiveFunction *objectiveFunction) {
    if(objectiveFunction->fitness(position) < objectiveFunction->fitness(bestPosition)) {
        bestPosition = position;
    }
}
