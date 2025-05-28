set terminal pdfcairo enhanced font "Arial,10"
set output 'ajuste.pdf'

set title 'Ajuste lineal del experimento de Millikan'
set xlabel 'Frecuencia (Hz)'
set ylabel 'Voltaje (V)'
set grid

# Valores desde el programa C++
h = 1.067e-34
phi = 0.5309

# Agregar tabla con los valores
set label 1 sprintf("h = %.3e J·s", h) at graph 0.05, 0.9
set label 2 sprintf("φ = %.4f V", phi) at graph 0.05, 0.85

plot 'ajuste.dat' using 1:2 with points pt 7 lc rgb 'blue' title 'Datos', \
     '' using 1:3 with lines lw 2 lc rgb 'red' title 'Ajuste lineal'
