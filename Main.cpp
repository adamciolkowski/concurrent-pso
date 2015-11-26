#include <iostream>
#include "SwarmParams.h"
#include "PSO.h"
#include "SphereFunction.h"

using namespace std;

int main() {
    ObjectiveFunction *function = new SphereFunction();

    std::vector<double> lower(2, -5);
    std::vector<double> upper(2, 5);
    Bounds bounds(lower, upper);

    OptimizationProblem problem(function, bounds);

    SwarmParams params(0.2, 0.8, 0.8);
    PSO pso(100, 100, params);

    clock_t start = clock();
    Solution *s = pso.optimize(problem);
    double time = (clock() - start) / (double) CLOCKS_PER_SEC;
    std::cout << "time= " << time << " s" << std::endl;
    cout << *s << endl;
    delete function;
}