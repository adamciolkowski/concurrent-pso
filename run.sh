mpic++ -std=c++11 Main.cpp SwarmParams.cpp PSO.cpp Particle.cpp Solution.cpp -o app
mpirun -n 4 ./app
