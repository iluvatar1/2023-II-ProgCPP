#pragma once
#include <map>

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
        // double delta = p.rad - p.R[2];
        // if (delta > 0) {
        //     p.F[2] += params["K"]*delta;
        //     p.F[2] -= params["B"]*p.mass*p.V[2]; // -b m v
        // }
      }
    }

    template<class particle_array_t>
    void applyConstraint(particle_array_t & parray) {
      for (auto & p : parray) {
        // floor constraint
        double deltaz = p.rad - p.R[2];
        if (deltaz > 0 and p.V[2] <= 0){
          p.R[2] += 2*deltaz; // TODO : check
          p.V[2] = -params["E"]*p.V[2];
        }
        // left wall constraint
        double deltal = p.rad - p.R[0];
        if (deltal > 0 and p.V[0] <= 0){
          p.R[0] += 2*deltal; // TODO : check
          p.V[0] = -params["E"]*p.V[0];
        }
        // right wall constraint
        double deltar = p.rad + p.R[0] - params["LX"];
        if (deltar > 0 and p.V[0] >= 0){
          p.R[0] -= 2*deltar; // TODO : check
          p.V[0] = -params["E"]*p.V[0];
        }
        // top wall constraint
        double deltat = p.rad + p.R[2] - params["LZ"];
        if (deltat > 0 and p.V[2] >= 0){
          p.R[2] -= 2*deltat; // TODO : check
          p.V[2] = -params["E"]*p.V[2];
        }
      }
    }

};
