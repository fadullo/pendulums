import numpy as np
import matplotlib.pyplot as plt

args = {"delimiter":"\t", "skiprows":0}

# time, angle, angularVelocity
t, px, py, pz, vx, vy, vz = np.loadtxt("data/pendulum_forward.dat", **args).T

print(t, px, vx)

plt.figure(figsize=(14, 6))
plt.plot(t, px)
plt.grid(True)
plt.tight_layout()
plt.show()
