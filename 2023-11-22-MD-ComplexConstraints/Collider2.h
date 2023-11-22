#pragma once
#include <map>
#include <cmath>
#include <iostream>

class Collider {
  std::map<std::string, double> params; // parameters to compute the forces
  public:
    Collider(const std::map<std::string, double> & PARAMS) {
      params = PARAMS;
    }

    template<class particle_array_t>
    void computeForces(particle_array_t & parray) {
      // reset forces
      for (auto & p : parray) {
        p.F = {0,0,0};
      }
      // sum of individual forces
      for (auto & p : parray) {
        // gravity force
        p.F[2] += p.mass*params["G"];
        // force with the floor
        double delta = p.rad - p.R[2];
        if (delta > 0) {
            p.F[2] += params["K"]*delta;
        }
      }
    }

    template<class particle_array_t>
    void apply_constraints(particle_array_t & parray) {
      for (auto & p : parray) {
        // keep inside circle of radius params["RC"] by
        // adding the intersection back to the position
        // and reverse velocity
        double R = std::sqrt(p.R[0]*p.R[0] + p.R[1]*p.R[1] + p.R[2]*p.R[2]);
        double delta = R + p.rad - params["RC"];
        if (delta > 0) {
          // normal vector
          double N[3] = {p.R[0]/R, p.R[1]/R, p.R[2]/R};
          // move back
          double factor = 1.0*delta;
          p.R[0] -= factor*N[0];
          p.R[1] -= factor*N[1];
          p.R[2] -= factor*N[2];
          // reverse velocity in the normal direction
          double Vnormal = p.V[0]*N[0] + p.V[1]*N[1] + p.V[2]*N[2];
          p.V[0] = p.V[0] - 2*Vnormal*N[0];
          p.V[1] = p.V[1] - 2*Vnormal*N[1];
          p.V[2] = p.V[2] - 2*Vnormal*N[2];
        }
      }
    }
};
