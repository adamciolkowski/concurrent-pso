#include <iostream>
#include "SwarmParams.h"
#include "PSO.h"
#include "SphereFunction.h"

using namespace std;

int main() {
    SphereFunction *function = new SphereFunction();

    std::vector<double> lower(2, -5);
    std::vector<double> upper(2, 5);
    Bounds bounds(lower, upper);

    OptimizationProblem problem(function, bounds);

    SwarmParams params(0.2, 0.8, 0.8);
    PSO pso(100, 100, params);

    Solution *s = pso.optimize(problem);
    cout << *s << endl;
    delete function;
}