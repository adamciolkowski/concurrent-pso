cmake_minimum_required(VERSION 3.3)
project(concurrent_pso)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")

set(SOURCE_FILES
        Main.cpp
        Particle.cpp
        Particle.h
        PSO.cpp
        PSO.h
        SwarmParams.cpp
        SwarmParams.h
        Bounds.h
        ObjectiveFunction.h
        Solution.cpp
        Solution.h
        OptimizationProblem.h
        SphereFunction.h
        RosenbrockFunction.h)
add_executable(concurrent_pso ${SOURCE_FILES})
