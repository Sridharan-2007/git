import numpy as np
import matplotlib.pyplot as plt
h = 6.62607015e-34  
m = 9.10938356e-31  
eV = 1.602176634e-19  
def energy_level(n, L):
    return (n**2 * h**2) / (8 * m * L**2) / eV  
lengths = np.array([10e-9, 20e-9, 30e-9, 40e-9, 50e-9])  
n_values = np.arange(1, 6)
energy_levels = np.array([[energy_level(n, L) for L in lengths] for n in n_values])
plt.figure(figsize=(10, 6))
for i, n in enumerate(n_values):
    plt.plot(lengths * 1e9, energy_levels[i], marker='o', label=f'n={n}')
plt.title('Energy Levels of a Particle in a 1D Box')
plt.xlabel('Length of the Box (nm)')  
plt.ylabel('Energy (eV)')
plt.legend()
plt.grid()
plt.show()
x = np.linspace(0, 50e-9, 50)  
L = 50e-9
E_vals = np.array([energy_level(n, L) for n in n_values])
delta_E = np.min(np.diff(E_vals))
scale = 0.4 * delta_E   
plt.figure(figsize=(8, 8))
for n in n_values:
    psi =  np.sin(n * np.pi * x / L)
    E = energy_level(n, L)
    plt.plot(x * 1e9, scale * psi + E, marker='o', color='navy')
    plt.axhline(E, linestyle='--', color='gray', linewidth=1)
    plt.text(1, E, f'n={n}', va='center')
plt.title('Wavefunctions ψ with Physical Energy Levels')
plt.xlabel('Position (nm)')
plt.ylabel('Energy (eV)')
plt.xlim(0, L*1e9)
plt.yticks([])
plt.grid(alpha=0.3)
plt.tight_layout()
plt.show()