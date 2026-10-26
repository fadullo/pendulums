import numpy as np
import matplotlib.pyplot as plt

args = {"delimiter": "\t", "skiprows": 0}

ufT, ufPx, ufPy, ufPz, ufVx, ufVy, ufVz = np.loadtxt("data/pendulum_forward_undamped.dat", **args).T
usT, usPx, usPy, usPz, usVx, usVy, usVz = np.loadtxt("data/pendulum_semi_implicit_undamped.dat", **args).T


plt.figure(figsize=(14, 6))
plt.plot(ufT, ufPx, label="Undamped forward-euler")
plt.plot(usT, usPx, label="Undamped semi-implicit-euler")
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()

plt.figure(figsize=(8, 8))
plt.plot(ufPx, ufVx, label="Undamped forward-euler (Phase)", alpha=0.7)
plt.plot(usPx, usVx, label="Undamped semi-implicit-euler (Phase)", alpha=0.7)
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
