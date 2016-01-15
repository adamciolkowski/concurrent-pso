#include <iostream>
#include <openacc.h>
#include "SwarmParams.h"
#include "PSO.h"
#include "RosenbrockFunction.h"

using namespace std;

int main(int argc, char *argv[]) {
    //int n = atoi(argv[1]);
    //omp_set_num_threads(n);
    const int dimensions = 10;
    ObjectiveFunction *function = new RosenbrockFunction(dimensions);

    vector<double> lower(dimensions, -5);
    vector<double> upper(dimensions, 5);
    Bounds bounds(lower, upper);

    OptimizationProblem problem(function, bounds);

    SwarmParams params(0.2, 0.8, 0.8);
    PSO pso(12000, 500, params);

    //double startOmp = omp_get_wtime();
    Solution *s = pso.optimize(problem);
    //double time = omp_get_wtime() - startOmp;
    //cout << "time= " << time << " s with " << n << " threads" << endl;
    cout << *s << endl;
    delete function;
}
