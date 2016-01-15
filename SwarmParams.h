#ifndef CONCURRENT_PSO_SWARMPARAMS_H
#define CONCURRENT_PSO_SWARMPARAMS_H

class SwarmParams {

public:
    SwarmParams(double inertiaFactor, double personalWeight, double globalWeight);

    double getInertiaFactor() const;
    double getPersonalWeight() const;
#pragma acc routine seq
    double getGlobalWeight() const;
private:
    double inertiaFactor;
    double personalWeight;
    double globalWeight;
};


#endif //CONCURRENT_PSO_SWARMPARAMS_H
