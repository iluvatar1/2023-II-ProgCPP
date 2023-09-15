import numpy as np # para procesar los datos
import matplotlib.pyplot as plt # dibujar

# leer los datos
x, fx, ef, ec = np.genfromtxt('datos.txt', unpack=True)

# plot data
fig, ax = plt.subplots()
ax.loglog(x, ef, '-o', label = "Error forward")
ax.loglog(x, ec, '-s', label = 'Error central')
ax.set_xlabel("$x$")
ax.set_ylabel("% diff")
ax.legend()

# save figure
plt.show()
fig.savefig("fig.pdf")
