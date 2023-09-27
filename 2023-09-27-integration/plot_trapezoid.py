import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
sns.set_context('paper')

x, erf, error = np.genfromtxt('erf_data.txt', unpack=True)
fig, ax = plt.subplots(1, 2)
ax[0].plot(x, erf, '-o', label="err function")
ax[0].legend()
ax[1].plot(x, error, '-s', label="relative error")
ax[1].legend()
ax[1].loglog()
fig.savefig("trapezoid_erf.pdf")
plt.show()
