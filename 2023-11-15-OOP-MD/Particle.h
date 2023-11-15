#pragma once
#include <iostream>
#include <vector>

struct Particle {
    std::vector<double> R{0,0,0}, V{0,0,0}, F{0,0,0};
    double mass{0}, rad{0};
    void print(void);
    // overload the cout operator: friend declared to acces possible private data
    // see: https://www.learncpp.com/cpp-tutorial/overloading-the-io-operators/
    friend std::ostream& operator<< (std::ostream& out, const Particle & p) {
        return out << p.mass << "\t" << p.rad << "\t"
                   << p.R[0] << "\t" << p.R[1] << "\t" << p.R[2] << "\t"
                   << p.V[0] << "\t" << p.V[1] << "\t" << p.V[2] << "\t"
                   << p.F[0] << "\t" << p.F[1] << "\t" << p.F[2] << "\t";
    }
};
