#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cmath>

#define SWARM_SIZE 1000
#define ITERATIONS 10000
#define DIMENSIONS 10

#define INERTIA_FACTOR 0.3
#define GLOBAL_WEIGHT 0.8
#define LOCAL_WEIGHT 0.8

#define MAX_BOUND 5
#define MIN_BOUND -5

using namespace std;

struct Particle {
    double position[DIMENSIONS];
    double velocity[DIMENSIONS];
    double bestPosition[DIMENSIONS];
};

double randomInRange(double min, double max) {
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

void printArray(const double array[], int length) {
    cout << "[";
    for (int i = 0; i < length - 1; ++i) {
        cout << array[i] << ", ";
    }
    cout << array[length - 1] << "]" << endl;
}

static double constrict(double value, double min, double max) {
    if (value < min)
        return min;
    if (value > max)
        return max;
    return value;
}

double fitness(const double x[]) {
    double f = 0;
    for (int i = 0; i < DIMENSIONS - 1; i++) {
        f += 100 * pow(x[i + 1] - pow(x[i], 2), 2) + pow(x[i]-1, 2);
    }
    return f;
}

int main(int argc, char *argv[]) {
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);

    clock_t start = clock();

    Particle particles[SWARM_SIZE];
    for (int i = 0; i < SWARM_SIZE; ++i) {
        struct Particle p;
        for (int j = 0; j < DIMENSIONS; ++j) {
            p.position[j] = randomInRange(MIN_BOUND, MAX_BOUND);
        }
        for (int j = 0; j < DIMENSIONS; ++j) {
            p.velocity[j] = 0.0;
        }
        for (int j = 0; j < DIMENSIONS; ++j) {
            memcpy(p.bestPosition, p.position, sizeof(double) * DIMENSIONS);
        }
        particles[i] = p;
    }
    double bestSwarmPosition[DIMENSIONS];
    double bestFitness;
    for (int i = 0; i < SWARM_SIZE; ++i) {
        double f = fitness(particles[i].position);
        if(i == 0 || f < bestFitness) {
            memcpy(bestSwarmPosition, particles[i].position, sizeof(double) * DIMENSIONS);
            bestFitness = f;
        }
    }

    for (int i = 0; i < ITERATIONS; ++i) {
        for (int j = 0; j < SWARM_SIZE; ++j) {
            Particle &p = particles[j];
            for (int k = 0; k < DIMENSIONS; ++k) {
                double newPos = INERTIA_FACTOR * p.velocity[k] +
                                (p.bestPosition[k] - p.position[k]) * LOCAL_WEIGHT +
                                (bestSwarmPosition[k] - p.position[k]) * GLOBAL_WEIGHT;
                p.velocity[k] = constrict(newPos, MIN_BOUND, MAX_BOUND);
            }
            for (int k = 0; k < DIMENSIONS; ++k) {
                p.position[k] = p.position[k] * p.velocity[k];
            }
            double f = fitness(particles[j].position);
            if(f < fitness(particles[j].bestPosition)) {
                memcpy(particles[j].bestPosition, particles[j].position, sizeof(double) * DIMENSIONS);
                bestFitness = f;
            }
        }

        for (int j = 0; j < SWARM_SIZE; ++j) {
            double f = fitness(particles[j].position);
            if(f < bestFitness) {
                memcpy(bestSwarmPosition, particles[j].position, sizeof(double) * DIMENSIONS);
                bestFitness = f;
            }
        }
    }
    double time = (clock() - start) / (double) CLOCKS_PER_SEC;

    printArray(bestSwarmPosition, DIMENSIONS);
    cout << "fitness = " << bestFitness << endl;
    cout << "time    = " << time << " s" << endl;
}
