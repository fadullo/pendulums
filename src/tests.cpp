#include <iostream>
#include <fstream>
#include <iomanip>

#include "eulers.cpp"

// Creates datasets using tabs as the delimiter
void dataset(const std::string& filename, const result& data)
{
     std::ofstream outfile(filename);

     if (!outfile.is_open())
     {
          return;
     }

     outfile << std::fixed << std::setprecision(6);

     for (size_t i = 0; i < data.t.size(); i++)
     {
          outfile << data.t[i] << "\t"
               << data.p[i].x << "\t" << data.p[i].y << "\t" << data.p[i].z << "\t"
               << data.v[i].x << "\t" << data.v[i].y << "\t" << data.v[i].z << "\n";
     }
}

int main()
{
     double tf = 20.0;
     double dt = 0.1;

     // States take the input (initialPosition, iniitialVelocity, startTime, force)
     // An object thrown straight up

     state initial{{0.0, 0.0, 0.0}, {0.0, 10.0, 0.0}, 0.0, gravity};

     result forward_data = euler("forward", initial, dt, tf);
     dataset("data/forward_euler.dat", forward_data);
     result semi_data = euler("semi-implicit", initial, dt, tf);
     dataset("data/semi_implicit.dat", semi_data);
     std::cout << "Datasets successfully generated in 'data/' folder.\n";

     state pInitial{{1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, 0.0, pendulum(1.5)};

     result p_forward = euler("forward", pInitial, dt, tf);
     dataset("data/pendulum_forward.dat", p_forward);

     result p_semi = euler("semi-implicit", pInitial, dt, tf);
     dataset("data/pendulum_semi_implicit.dat", p_semi);
     return 0;
}
