set xlabel "x (posición)"
set ylabel "v (velocidad)"
plot "output-euler.txt" using 1:2 with lines title "Euler", \
     "output-heun.txt" using 1:2 with lines title "Heun"