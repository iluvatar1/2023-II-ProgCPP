#include <iostream>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

// Harmonic oscillator function
int func (double t, const double y[], double f[], void *params) {
    double k = *(double *)params;
    f[0] = y[1];
    f[1] = -k * y[0];
    return GSL_SUCCESS;
}

int main() {
    double k = 1.2345*1.2345; // Spring constant
    gsl_odeiv2_system sys = {func, NULL, 2, &k};
    
    gsl_odeiv2_driver * d = gsl_odeiv2_driver_alloc_y_new (&sys, gsl_odeiv2_step_rk8pd, 1e-6, 1e-6, 0.0);
    int i;
    double t = 0.1, t1 = 24.3;
    double y[2] = { 1.5, 0.0 }; // Initial conditions

    for (i = 1; i <= 100; i++) {
        double ti = i * t1 / 10.0;
        int status = gsl_odeiv2_driver_apply (d, &t, ti, y);

        if (status != GSL_SUCCESS) {
            std::cout << "Error: status = " << status << std::endl;
            break;
        }

        std::cout << t << " " << y[0] << " " << y[1] << std::endl;
    }

    gsl_odeiv2_driver_free (d);
    return 0;
}
