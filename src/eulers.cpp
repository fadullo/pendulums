#include <vector>
#include <cmath>

// The constants of our simulation
double g = 9.81;
double L = 1.0;

struct result {
     std::vector<double> t;
     std::vector<double> phi;
     std::vector<double> omega;
     std::vector<double> error;
};

result forward_euler(int n, double tf, double ic[])
     // n: number of steps
     // dt: step size
     // ic: initial conditions, ic[0] is for phi, ic[1] is for omega
{
     std::vector<double> t(n+1);
     std::vector<double> phi(n+1);
     std::vector<double> omega(n+1);
     std::vector<double> error(n+1);

     double dt = tf/n;

     // Setting the initial conditions
     t[0] = 0.0;
     phi[0] = ic[0];
     omega[0] = ic[1];

     double energy0 = 0.5 * L * L * omega[0] * omega[0] + g * L * (1.0 - cos(phi[0]));
     error[0] = 0.0;

     // Using euler's method
     for (int j = 0; j < n; j++)
     {
          phi[j+1] = phi[j] + dt*omega[j];
          omega[j+1] = omega[j] + dt*(-(g/L)*sin(phi[j]));
          t[j+1] = t[j] + dt;

          double energy = 0.5 * L * L * omega[j+1] * omega[j+1] + g * L * (1.0 - cos(phi[j+1]));
          error[j+1] = energy - energy0;
     }
     return {t, phi, omega, error};
}

result backward_euler()
{
     return {};
}
result semi_implicit_euler()
{
     return {};
}
