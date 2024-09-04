set terminal pngcairo transparent enhanced color size 1360,768 
set output "E1.png"

set samples 100000
set xlabel "Distancia Internuclear(R)"
set ylabel "{/Symbol y}(R)"

plot "datosp.dat" index 0 using 3:1 t "RK2"with lp pt 5 ps 0.5 lc 2 , "datosp2.dat" index 0 using 3:1 t "RK4" with lp pt 5 ps 0.5 lc 7 

unset output

