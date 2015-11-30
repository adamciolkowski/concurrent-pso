g++ -std=c++11 -fopenmp Main.cpp SwarmParams.cpp PSO.cpp Particle.cpp Solution.cpp -o app
./app 1
g++ -ftree-vectorize -std=c++11 -fopenmp Main.cpp SwarmParams.cpp PSO.cpp Particle.cpp Solution.cpp -o app
./app 2
./app 4
./app 8
./app 16
./app 32
./app 64

