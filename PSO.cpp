#include "PSO.h"

Solution *PSO::optimize(const OptimizationProblem &problem) {
    objectiveFunction = problem.getObjectiveFunction();
    std::vector<Particle> particles = initializeSwarm(problem.getBounds());
    updateBest(particles);
    for (int i = 0; i < numberOfIterations; i++) {
        updateSwarm(particles, problem.getBounds());
        updateBest(particles);
    }
    return new Solution(bestPosition, bestFitness);
}

std::vector<Particle> PSO::initializeSwarm(Bounds bounds) {
    std::vector<Particle> particles;
    for (int i = 0; i < swarmSize; i++) {
        Particle p = randomParticle(objectiveFunction->numberOfVariables(), bounds);
        particles.push_back(p);
    }
    return particles;
}

Particle PSO::randomParticle(int dimensions, const Bounds &bounds) {
    std::vector<double> position((unsigned long) dimensions);
    for (int d = 0; d < position.size(); d++) {
        position[d] = randomInRange(bounds.lowerBound(d), bounds.upperBound(d));
    }
    std::vector<double> velocity((unsigned long) dimensions);
    return Particle(position, velocity);
}

void PSO::updateBest(const std::vector<Particle> &particles) {
    // TODO: use reduction?
    for (std::vector<Particle>::const_iterator it = particles.begin(); it != particles.end(); ++it) {
        if (isBestInSwarm(*it)) {
            bestPosition = it->getPosition();
            bestFitness = objectiveFunction->fitness(it->getPosition());
        }
    }
}

bool PSO::isBestInSwarm(const Particle &particle) const {
    return objectiveFunction->fitness(particle.getPosition()) < bestFitness;
}

void PSO::updateSwarm(std::vector<Particle> &particles, Bounds bounds) {
#pragma omp parallel for
    for (int i = 0; i < particles.size(); ++i) {
        particles[i].update(bestPosition, bounds, objectiveFunction, swarmParams);
    }
}