#include <iostream>
#include <sundials/sundials_types.h>
#include <sundials/sundials_math.h>
#include <sundials/sundials_nvector.h>
#include <sunmatrix/sunmatrix_dense.h> // access to dense SUNMatrix
#include <sunlinsol/sunlinsol_dense.h> // access to dense SUNLinearSolver
#include <cvode/cvode.h>
#include <nvector/nvector_serial.h>
#include <cvode/cvode_direct.h>

// Function to compute the right-hand side of the harmonic oscillator equation
int harmonicOscillator(realtype t, N_Vector y, N_Vector ydot, void *user_data) {
    realtype k = 1.0; // Spring constant
    NV_Ith_S(ydot, 0) = NV_Ith_S(y, 1); // y' = ydot
    NV_Ith_S(ydot, 1) = -k * NV_Ith_S(y, 0); // y'' = -k * y
    return 0;
}

int main() {
  int flag;
  const int N = 2;
  // Create the NVECTOR object
  N_Vector y = N_VNew_Serial(N); // 2 state variables

  // Set the initial conditions
  NV_Ith_S(y, 0) = 1.0; // Initial displacement
  NV_Ith_S(y, 1) = 0.0; // Initial velocity

  // Create the CVODE solver
  void *cvode_mem = CVodeCreate(CV_BDF);

  // Initialize the CVODE solver
  flag = CVodeInit(cvode_mem, harmonicOscillator, 0.0, y);
  std::clog << flag << "\n";
  
  // Set the integration parameters
  CVodeSStolerances(cvode_mem, 1e-6, 1e-8);
  CVodeSetMaxNumSteps(cvode_mem, 10000);

  // ---------------------------------------------------------------------------
  // Need to create a dense matrix for the dense solver.
  SUNMatrix A = SUNDenseMatrix(N, N);
  // ---------------------------------------------------------------------------

  // 9. Create Linear Solver Object.
  // ---------------------------------------------------------------------------
  // Dense linear solver object instead of the iterative one in the original
  // simple example.
  SUNLinearSolver LS = SUNDenseLinearSolver(y, A) ;
  // ---------------------------------------------------------------------------
  // ---------------------------------------------------------------------------
  // Call CVDlsSetLinearSolver to attach the matrix and linear solver this
  // function is different for direct solvers.
  flag = CVDlsSetLinearSolver(cvode_mem, LS, A);

  
  // Perform the integration
  realtype t_end = 10.0; // End time
  realtype t_out = 0.0;
  realtype t = 0.0;
  realtype dt = 0.1;
  for (t_out = dt; t_out <= t_end; t_out += dt) {
    CVode(cvode_mem, t_out, y, &t, CV_NORMAL);
    // Print the solution
    std::cout << t << "\t" << NV_Ith_S(y, 0) << "\t" << NV_Ith_S(y, 1) << std::endl;
  }
  // Free memory
  N_VDestroy(y);
  CVodeFree(&cvode_mem);

  return 0;
}
