#include "Solution.h"

Solution::Solution(const std::vector<double> &position, double fitness) :
        position(position), fitness(fitness) { }

std::ostream &operator<<(std::ostream &out, const Solution &s) {
    out << "[ ";
    for (std::vector<double>::const_iterator i = s.position.begin(); i != s.position.end(); ++i)
        out << *i << ' ';
    out << ']';
    out << " " << s.fitness;
    return out;
}
