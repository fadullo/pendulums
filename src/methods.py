import numpy as np
import matplotlib.pyplot as plt
from dataclasses import dataclass

@dataclass
class state:
    x: float
    v: float
    t: float

class simulation:
    def __init__(self, g, l):
        self.g = g
        self.l = l

    def force(self, x: float, v: float):
        dxdt = v
        dvdt = -(self.g/self.l)*np.sin(x)
        return dxdt, dvdt

    def euler_while(self, iS: state, dt: float, tmax: float):
        t = np.array([iS.t])
        x = np.array([iS.x])
        v = np.array([iS.v])

        cS = iS

        while cS.t < tmax:
            dxdt, dvdt = self.force(cS.x, cS.v)

            cS = state(
                x = cS.x + dt * dxdt,
                v = cS.v + dt * dvdt,
                t = cS.t + dt
            )
            t = np.append(t, cS.t)
            x = np.append(x, cS.x)
            v = np.append(v, cS.v)

        return t, x, v

sim = simulation(g=9.81, l=1.0)
initial_state = state(x=1.0, v=0.0, t=0.0)

t, x, v = sim.euler_while(initial_state, dt=0.001, tmax=50.0)

plt.figure(figsize=(10, 4))
plt.plot(t, x, label="Forward Euler (While Loop)")
plt.xlabel("Time (s)")
plt.ylabel("Angle (rad)")
plt.grid(True)
plt.legend()
plt.show()
