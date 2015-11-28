#include <iostream>
#include <omp.h>
#include "SwarmParams.h"
#include "PSO.h"
#include "RosenbrockFunction.h"

using namespace std;

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    omp_set_num_threads(n);
    ObjectiveFunction *function = new RosenbrockFunction(10);

    vector<double> lower(2, -5);
    vector<double> upper(2, 5);
    Bounds bounds(lower, upper);

    OptimizationProblem problem(function, bounds);

    SwarmParams params(0.2, 0.8, 0.8);
    PSO pso(12000, 100, params);

    double startOmp = omp_get_wtime();
    Solution *s = pso.optimize(problem);
    double time = omp_get_wtime() - startOmp;
    cout << "time= " << time << " s with " << n << " threads" << endl;
    delete function;
}