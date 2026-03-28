#calculate the energy level (in eV) of particle in a 1D box from n = 1 to 5 and l = 10nm  to l=50nm and plotting wavefunction for n = 1 to 5 x axis is length of the box and y axis is energy shift
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
    plt.plot(lengths * 1e9, energy_levels[i], label=f'n={n}')
plt.title('Energy Levels of a Particle in a 1D Box')
plt.xlabel('Length of the Box (nm)')    
plt.ylabel('Energy Level (eV)')
plt.legend()
plt.grid()
plt.show()
x = np.linspace(0, 50e-9, 1000)  
plt.figure(figsize=(10, 6))
for n in n_values:
    L = 50e-9  
    psi = np.sqrt(2 / L) * np.sin(n * np.pi * x / L)  
    plt.plot(x * 1e9, psi * energy_level(n, L), label=f'n={n}')  
plt.title('Wavefunctions of a Particle in a 1D Box')
plt.xlabel('Position (nm)')
plt.ylabel('Energy Shift (eV)')
plt.legend()
plt.grid()
plt.show()