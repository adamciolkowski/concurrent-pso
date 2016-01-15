#include "SwarmParams.h"

SwarmParams::SwarmParams(double inertiaFactor, double personalWeight, double globalWeight) :
        inertiaFactor(inertiaFactor), personalWeight(personalWeight), globalWeight(globalWeight) {
}

double SwarmParams::getInertiaFactor() const {
    return inertiaFactor;
}

double SwarmParams::getPersonalWeight() const {
    return personalWeight;
}

double SwarmParams::getGlobalWeight() const {
    return globalWeight;
}
