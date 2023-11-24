#include "Particle.h"
#include "Integrator.h"
#include "Collider.h"
#include <vector>
#include <fstream>

void print_csv(int iter, const std::vector<Particle> & bodies);

int main(int argc, char **argv) {
  std::vector<Particle> bodies;
  bodies.resize(2);

  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 200.8767;
  //p["DT"] = 0.1;
  p["DT"] = 0.01;
  p["G"] = 0.0; //-9.81;
  p["K"] = 420.987; // N/m
  p["B"] = 1.47; // 1/s
  p["E"] = 1.00; // coefficient of restitution
  p["LX"] = 5.7; // Position of right wall
  p["LZ"] = 7.7; // Position of top wall
  p["RC"] = 6.578; // Position of top wall

  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // initial conditions and properties
  bodies[0].R[0] = -2.987;
  bodies[0].R[2] = 0.987;
  bodies[0].V[0] = 2.654; //-8.987;
  bodies[0].V[2] = 3.0; //+3.987;
  bodies[0].rad  = 1.503;
  bodies[0].mass = 0.337;

  bodies[1].R[0] = 3.987;
  bodies[1].R[2] = 0.987;
  bodies[1].V[0] = 0.0; // +8.987;
  bodies[1].V[2] = 0.0; // +3.987;
  bodies[1].rad  = 0.503;
  bodies[1].mass = 0.337;
  bodies[1].active = false;

  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  collider.applyConstraint(bodies);
  //std::cout << p["T0"] << "\t" << bodies[0] << "\t" << bodies[1] << "\n";
  //std::cout << p["T0"] << "\t" << bodies[0] << "\n";
  print_csv(0, bodies);

  // Time iteration
  const int NPRINT = 10;
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter; ++ii) {
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
	collider.applyConstraint(bodies);
    double time = p["T0"] + ii*p["DT"];
    //std::cout << time << "\t" << bodies[0] << "\t" << bodies[1] << "\n";
    //std::cout << time << "\t" << bodies[0] << "\n";
	if(ii%NPRINT==0) print_csv(ii, bodies);
  }

  return 0;
}

void print_csv(int iter, const std::vector<Particle> & bodies)
{
	// create filnema including iter in the name
	std::string filename = "DATA/data-" + std::to_string(iter) + ".csv";
	std::ofstream fout(filename);
	fout << "x,y,z,vx,vy,vz,rad\n";
	for (const auto & body : bodies) {
		fout << body.R[0] << "," << body.R[1] << "," << body.R[2] << ","
			<< body.V[0] << "," << body.V[1] << "," << body.V[2] << ","
			<< body.rad << "\n";
	}
	fout.close();
}
