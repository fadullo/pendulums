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
               << data.phi[i] << "\t"
               << data.omega[i] << "\t"
               << data.error[i] << "\n";
     }
}

int main()
{
     // The time step dt is acquired by using "n" and "tf" (double dt = tf/n), which makes it very sensitive
     // based on what you input for those variables, a given "n" and "tf" could make
     // dt small, or big, which can change the dataset you are trying to achieve

     int n = 1750;
     double tf = 35.0;
     double ic[2] = {1.0, 0.0};

     result data = forward_euler(n, tf, ic);

     dataset("../data/forward_euler.dat",data);

     return 0;
}

