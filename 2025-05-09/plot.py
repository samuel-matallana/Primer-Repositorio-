import numpy as np
import matplotlib.pyplot as plt

# Carga de datos
N, h, fe, ce, rfe, rce = np.loadtxt("errores.txt", unpack=True)

# Gráfica
fig, ax = plt.subplots()
ax.plot(N, fe, '-o', label='Trapecio')
ax.plot(N, ce, '-s', label='Simpson')
ax.plot(N, rfe, '-^', label='Trapecio + Richardson')
ax.plot(N, rce, '-*', label='Simpson + Richardson')

ax.set_xscale('log')
ax.set_yscale('log')
ax.set_xlabel('N (número de pasos)')
ax.set_ylabel('Error relativo')
ax.legend()
ax.grid(True)
fig.savefig("integracion_error.pdf")