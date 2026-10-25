#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <functional>

// List of constants
double g = 9.81;

struct vector
{
     double x, y, z;
     vector operator+(const vector& other) const
     {
          return {x + other.x, y + other.y, z + other.z};
     }
     vector operator*(double scalar) const
     {
          return {x * scalar, y * scalar, z * scalar};
     }
     vector operator-()
     {
          return {-x, -y, -z};
     };
     vector operator+=(const vector& other)
     {
          x += other.x;
          y += other.y;
          z += other.z;
          return *this;
     }
     void print() const {
          std::cout << "(" << x << ", " << y << ", " << z << ")";
     }
};

struct state
{
     vector position;
     vector velocity;
     double t;
     std::function<std::pair<vector, vector>(vector, vector)> force;
};

struct result
{
     std::vector<double> t;
     std::vector<vector> p;
     std::vector<vector> v;
};

result euler(std::string method, state iState, double dt, double tmax)
{
     std::vector<double> t = {iState.t};
     std::vector<vector> p = {iState.position};
     std::vector<vector> v = {iState.velocity};

     state cState = iState;

     while (cState.t < tmax)
     {
          auto [dpdt, dvdt] = cState.force(cState.position, cState.velocity);

          if (method == "forward")
          {
               cState.position += dpdt * dt;
               cState.velocity += dvdt * dt;
          }
          else if (method == "semi-implicit")
          {
               cState.velocity += dvdt * dt;
               cState.position += cState.velocity * dt;
          }

          cState.t += dt;

          t.push_back(cState.t);
          p.push_back(cState.position);
          v.push_back(cState.velocity);
     }

     return {t, p, v};
}

std::pair<vector, vector> gravity(vector position, vector velocity)
{
     vector dpdt = velocity;
     vector dvdt = {0.0, -9.81, 0.0};
     return {dpdt, dvdt};
}

// std::function< ReturnType (Input 1, Input 2) >

std::function<std::pair<vector, vector>(vector, vector)> pendulum(double l) {

     // [capture] ( Parameters ) -> ReturnType {}

    return [l](vector position, vector velocity) -> std::pair<vector, vector> {
        vector dpdt = velocity;
        double accel = -(g / l) * std::sin(position.x);
        vector dvdt = {accel, 0.0, 0.0};
        return {dpdt, dvdt};
    };
}
