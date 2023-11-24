#pragma once
#include <map>
#include <cmath>

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

      // sum of pairwise forces N^2 complexity
      const int N = parray.size();
      for(int ii = 0; ii < N; ++ii) {
        for(int jj = ii+1; jj < N; ++jj) { // N(N-1)/2
          double Rij[3] = {0,0,0}; // goes from j to i
          Rij[0] = parray[ii].R[0] - parray[jj].R[0];
          Rij[1] = parray[ii].R[1] - parray[jj].R[1];
          Rij[2] = parray[ii].R[2] - parray[jj].R[2];
          double Rijnorm = std::sqrt(Rij[0]*Rij[0] + Rij[1]*Rij[1] + Rij[2]*Rij[2]);
          double deltaij = parray[ii].rad + parray[jj].rad - Rijnorm;
          if (deltaij > 0) {
            parray[ii].F[0] += params["K"]*deltaij*Rij[0]/Rijnorm;
            parray[ii].F[1] += params["K"]*deltaij*Rij[1]/Rijnorm;
            parray[ii].F[2] += params["K"]*deltaij*Rij[2]/Rijnorm;
            parray[jj].F[0] += -params["K"]*deltaij*Rij[0]/Rijnorm;
            parray[jj].F[1] += -params["K"]*deltaij*Rij[1]/Rijnorm;
            parray[jj].F[2] += -params["K"]*deltaij*Rij[2]/Rijnorm;
          }
        }
      }

    }

    template<class particle_array_t>
    void applyConstraint(particle_array_t & parray) {
      // // rectangular box
      // for (auto & p : parray) {
      //   // floor constraint
      //   double deltaz = p.rad - p.R[2];
      //   if (deltaz > 0 and p.V[2] <= 0){
      //     p.R[2] += 2*deltaz; // TODO : check
      //     p.V[2] = -params["E"]*p.V[2];
      //   }
      //   // left wall constraint
      //   double deltal = p.rad - p.R[0];
      //   if (deltal > 0 and p.V[0] <= 0){
      //     p.R[0] += 2*deltal; // TODO : check
      //     p.V[0] = -params["E"]*p.V[0];
      //   }
      //   // right wall constraint
      //   double deltar = p.rad + p.R[0] - params["LX"];
      //   if (deltar > 0 and p.V[0] >= 0){
      //     p.R[0] -= 2*deltar; // TODO : check
      //     p.V[0] = -params["E"]*p.V[0];
      //   }
      //   // top wall constraint
      //   double deltat = p.rad + p.R[2] - params["LZ"];
      //   if (deltat > 0 and p.V[2] >= 0){
      //     p.R[2] -= 2*deltat; // TODO : check
      //     p.V[2] = -params["E"]*p.V[2];
      //   }
      // }
      // spherical box
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
          p.V[0] = p.V[0] - (1 + params["E"])*Vnormal*N[0];
          p.V[1] = p.V[1] - (1 + params["E"])*Vnormal*N[1];
          p.V[2] = p.V[2] - (1 + params["E"])*Vnormal*N[2];
        }
      }
    }

};
