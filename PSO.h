#ifndef CONCURRENT_PSO_PSO_H
#define CONCURRENT_PSO_PSO_H

#include "SwarmParams.h"
#include "Particle.h"
#include "Solution.h"
#include "OptimizationProblem.h"

#include <random>

class PSO {

public:
    PSO(int swarmSize, int numberOfIterations, SwarmParams swarmParams) :
            swarmSize(swarmSize), numberOfIterations(numberOfIterations), swarmParams(swarmParams) { }

    Solution *optimize(const OptimizationProblem &problem);

private:
    int swarmSize;
    int numberOfIterations;
    SwarmParams swarmParams;

    ObjectiveFunction *objectiveFunction;

    std::vector<double> bestPosition;
    double bestFitness = INFINITY;

    std::vector<Particle> initializeSwarm(Bounds bounds);

    Particle randomParticle(int dimensions, const Bounds &bounds);

    static double randomInRange(double min, double max) {
        std::uniform_real_distribution<double> unif(min, max);
        std::random_device rd;
        std::default_random_engine re(rd());
        return unif(re);
    }

    void updateBest(const std::vector<Particle> &particles);

    bool isBestInSwarm(const Particle &particle) const;

    void updateSwarm(std::vector<Particle> &particles, Bounds bounds);
};

#endif //CONCURRENT_PSO_PSO_H
