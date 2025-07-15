import matplotlib.pyplot as plt
import numpy as np

# Cargar archivos
euler = np.loadtxt("output-euler.txt")
heun  = np.loadtxt("output-heun.txt")

# Extraer columnas
x_euler, v_euler = euler[:,0], euler[:,1]
x_heun,  v_heun  = heun[:,0], heun[:,1]

# Crear la figura
plt.figure(figsize=(8, 6))
plt.plot(x_euler, v_euler, label='Euler', color='red')
plt.plot(x_heun,  v_heun,  label='Heun', color='blue')

plt.xlabel('x (posición)')
plt.ylabel('v (velocidad)')
plt.title('Velocidad vs Posición - Euler y Heun')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig('solucion_heun_euler.pdf')

