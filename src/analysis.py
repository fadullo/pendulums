import numpy as np
import matplotlib.pyplot as plt

args = {"delimiter":"\t", "skiprows":0}
t, phi, omega, error = np.loadtxt("../data/forward_euler.dat", **args).T

plt.figure(figsize=(14, 6))

plt.subplot(1, 2, 1)
plt.plot(t, phi)
plt.grid(True)

plt.subplot(1, 2, 2)
plt.plot(t, error)
plt.grid(True)

plt.tight_layout()
plt.show()
