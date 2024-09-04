set terminal pngcairo transparent enhanced color size 800,600 font "Times-New-Roman, 14"
set output "RK4_2.png"
set multiplot layout 2,1
set xlabel "x"
set ylabel "y(x)"
unset key

plot "datosRK4_2.dat" index 0 using 3:2 with lp pt 5 ps 0.5 lc 2

reset

set xlabel "x"
set ylabel "y(x)"
unset key

plot "datosRK4_2.dat" index 0 using 3:1 with lp pt 5 ps 0.5 lc 3

unset multiplot
unset output
#lt line type
