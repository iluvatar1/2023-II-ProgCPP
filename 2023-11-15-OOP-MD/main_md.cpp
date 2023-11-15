#include "Particle.h"
#include "Integrator.h"
#include "Collider.h"
#include <vector>

int main(int argc, char **argv) {
  std::vector<Particle> bodies;
  bodies.resize(1); // only one particle for now

  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 10.8767;
  //p["DT"] = 0.1;
  p["DT"] = 0.01;
  p["G"] = -9.81;
  p["K"] = 220.987; // N/m

  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // initial conditions and properties
  bodies[0].R[2] = 0.987;
  bodies[0].rad  = 0.103;
  bodies[0].mass = 0.337;
  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  std::cout << p["T0"] << "\t" << bodies[0] << "\n";

  // Time iteration
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter; ++ii) {
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
    double time = p["T0"] + ii*p["DT"];
    std::cout << time << "\t" << bodies[0] << "\n";
  }

  return 0;
}
