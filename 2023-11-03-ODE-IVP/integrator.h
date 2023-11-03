#pragma once

template <class deriv_t, class system_t, class printer_t>
void integrate_euler(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer)
{
  // initial setup
  system_t dydt; // to store the derivatives
  const int N = y.size();
  dydt.resize(N);
  double time = tinit;
  int nsteps = (tend - tinit)/dt;
  writer(y, time); // write initial conditions
    
  // time evolution
  for(int ii = 1; ii < nsteps; ++ii) {
    time = tinit + ii*dt;
    deriv(y, dydt, time); // compute the new derivatives
    // y = y + dt*dydt; // coefficient wise (assumption)
    for (int ii = 0; ii < N; ++ii) { // for each component of the state vector
      y[ii] = y[ii] + dt*dydt[ii]; // euler algorithm
    }
    writer(y, time); // write the state for this new time
  }
}
