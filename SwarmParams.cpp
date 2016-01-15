#include "SwarmParams.h"

SwarmParams::SwarmParams(double inertiaFactor, double personalWeight, double globalWeight) :
        inertiaFactor(inertiaFactor), personalWeight(personalWeight), globalWeight(globalWeight) {
}

#pragma acc routine seq
double SwarmParams::getInertiaFactor() const {
    return inertiaFactor;
}

#pragma acc routine seq
double SwarmParams::getPersonalWeight() const {
    return personalWeight;
}

#pragma acc routine seq
double SwarmParams::getGlobalWeight() const {
    return globalWeight;
}
