#pragma once

#include <cassert>

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

template <class deriv_t, class system_t, class printer_t>
void integrate_rk4(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer)
{
    // init method
    system_t k1, k2, k3, k4, aux;
    const int N = y.size();
    k1.resize(N);
    k2.resize(N);
    k3.resize(N);
    k4.resize(N);
    aux.resize(N);
    // time evolution
    double time = tinit;
    int nsteps = (tend - tinit)/dt;
    writer(y, time); // write initial conditions
    for(int ii = 1; ii < nsteps; ++ii) {
        time = tinit + ii*dt;
        // k1 -> (t, y)
        deriv(y, k1, time);
        // k2 -> t+h/2, y+h*k1/2
        for (int ii = 0; ii < N; ++ii)
            aux[ii] = y[ii] + k1[ii]*dt/2;
        deriv(aux, k2, time + dt/2);
        // k3 -> t+h/2, y+h*k2/2
        for (int ii = 0; ii < N; ++ii)
            aux[ii] = y[ii] + k2[ii]*dt/2;
        deriv(aux, k3, time + dt/2);
        // k4 -> t+h, y+h*k3
        for (int ii = 0; ii < N; ++ii)
            aux[ii] = y[ii] + k3[ii]*dt;
        deriv(aux, k4, time + dt);
        // use all k
        for (int ii = 0; ii < N; ++ii)
            y[ii] = y[ii] + dt*(k1[ii] + 2*k2[ii] + 2*k3[ii] + k4[ii])/6.0;
        // call writer
        writer(y, time);
    }
}


template <class deriv_t, class system_t, class printer_t>
void integrate_leapfrog(deriv_t deriv, system_t & y, double tinit, double tend, double dt, printer_t writer)
{
  // initial setup
  system_t dydt; // to store the derivatives
  const int N = y.size();
  assert(N == 2);
  dydt.resize(N);
  double time = tinit;
  int nsteps = (tend - tinit)/dt;
  writer(y, time); // write initial conditions

  // start leapfrog
  deriv(y, dydt, time); // compute the new derivatives
  y[1] = y[1] - dt*dydt[1]/2;
  
  // time evolution
  for(int ii = 1; ii < nsteps; ++ii) {
    time = tinit + ii*dt;
    deriv(y, dydt, time); // compute the new derivatives
    y[1] = y[1] + dt*dydt[1]; 
    y[0] = y[0] + dt*y[1]; 
    writer(y, time); // write the state for this new time
  }
}
