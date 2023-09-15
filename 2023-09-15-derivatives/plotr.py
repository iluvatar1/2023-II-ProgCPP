import numpy as np # para procesar los datos
import matplotlib.pyplot as plt # dibujar
#import seaborn as sns
#sns.set_context("article")

# leer los datos
x, fx, ef, ec, erf, erc = np.genfromtxt('datos-r.txt', unpack=True)

# plot data
fig, ax = plt.subplots()
ax.loglog(x, ef, '-o', label = "Error forward")
ax.loglog(x, ec, '-s', label = 'Error central')
ax.loglog(x, erf, '-^', label = "Error richardson forward")
ax.loglog(x, erc, '-*', label = 'Error richardson central')
ax.set_xlabel("$h$")
ax.set_ylabel("% diff")
ax.legend()
plt.grid(True)

# save figure
plt.show()
fig.savefig("figr.pdf")
