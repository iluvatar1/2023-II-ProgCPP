import numpy as np # para procesar los datos
import matplotlib.pyplot as plt # dibujar

# leer los datos
x, fx, ef, ec = np.genfromtxt('datos.txt', unpack=True)

# plot data
fig, ax = plt.subplots()
ax.plot(x, ef, label = "Error forward")
ax.plot(x, ec, label = 'Error central')
ax.legend()

# save figure
plt.show()
fig.savefig("fig.pdf")
