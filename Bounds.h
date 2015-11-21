#ifndef CONCURRENT_PSO_BOUNDS_H
#define CONCURRENT_PSO_BOUNDS_H

#include <vector>

class Bounds {

public:
    Bounds(std::vector<double> lower, std::vector<double> upper) :
            lower(lower), upper(upper) { }

    double lowerBound(int d) const {
        return lower[d];
    }

    double upperBound(int d) const {
        return upper[d];
    }

private:
    std::vector<double> lower;
    std::vector<double> upper;
};


#endif //CONCURRENT_PSO_BOUNDS_H
