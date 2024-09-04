set terminal pngcairo transparent enhanced color size 1366,767 font "times new roman, 18"
set output "RK2_2.png"

set samples 200
unset key

plot "datos2RK2.dat" index 0 using 3:1 with lp pt 5 ps 0.5 lc 2

unset output

