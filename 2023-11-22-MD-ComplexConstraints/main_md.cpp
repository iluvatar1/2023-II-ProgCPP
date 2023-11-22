#include "Particle.h"
#include "Integrator.h"
#include "Collider.h"
#include <vector>

int main(int argc, char **argv) {
  std::vector<Particle> bodies;
  bodies.resize(1);

  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 200.8767;
  //p["DT"] = 0.1;
  p["DT"] = 0.01;
  p["G"] = 0.0; //-9.81;
  p["K"] = 220.987; // N/m
  p["B"] = 1.47; // 1/s
  p["E"] = 0.90; // coefficient of restitution
  p["LX"] = 5.7; // Position of right wall
  p["LZ"] = 7.7; // Position of top wall
  p["RC"] = 6.578; // Position of top wall

  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // initial conditions and properties
  bodies[0].R[0] = 2.987;
  bodies[0].R[2] = 0.987;
  bodies[0].V[0] = 2.654; //-8.987;
  bodies[0].V[2] = 3.0; //+3.987;
  bodies[0].rad  = 0.503;
  bodies[0].mass = 0.337;

  // bodies[1].R[0] = 3.987;
  // bodies[1].R[2] = 0.987;
  // bodies[1].V[0] = +8.987;
  // bodies[1].V[2] = +3.987;
  // bodies[1].rad  = 0.503;
  // bodies[1].mass = 0.337;

  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  collider.applyConstraint(bodies);
  //std::cout << p["T0"] << "\t" << bodies[0] << "\t" << bodies[1] << "\n";
  std::cout << p["T0"] << "\t" << bodies[0] << "\n";

  // Time iteration
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter; ++ii) {
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
	collider.applyConstraint(bodies);
    double time = p["T0"] + ii*p["DT"];
    //std::cout << time << "\t" << bodies[0] << "\t" << bodies[1] << "\n";
    std::cout << time << "\t" << bodies[0] << "\n";
  }

  return 0;
}
