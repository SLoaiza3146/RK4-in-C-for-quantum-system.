set terminal pngcairo transparent enhanced color size 1366,768 font "times new roman,18"
set output "grafica_RK2.png"

set samples 200
unset key

plot "datosRK2.DAT" u 3:1 with lp pt 7 ps 1.3

unset output
