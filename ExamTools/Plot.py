import numpy as np
import matplotlib.pyplot as plt

# Carga de datos, ahora incluyendo la columna del error de GaussN
N, trap, etrap, rtrap, ert, simp, esimp, rsimp, ers, gaussN, egaussN, gauss3, egauss3 = np.loadtxt("integration_all.txt", unpack=True)

# Gráfica
fig, ax = plt.subplots()
ax.plot(N, trap, '-o', label='Trapecio')
ax.plot(N, trap, '-s', label='Simpson')
ax.plot(N, trap, '-^', label='Trapecio + Richardson')
ax.plot(N, trap, '-*', label='Simpson + Richardson')
ax.plot(N, egaussN, '-x', label='Gauss-7')  # nueva línea para GaussN

ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('N (número de pasos)')
ax.set_ylabel('Error relativo')
ax.legend()
ax.grid(True)
fig.savefig("integracion_error.pdf")
