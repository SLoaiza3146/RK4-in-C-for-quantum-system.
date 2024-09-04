#TAREA 7
set terminal pngcairo transparent enhanced color size 1360,768 font "Times-New-Roman, 20"
set output "conjunto.png"

set key bottom right
set xlabel "Distancia internuclear"
set ylabel "Energía potencial"
set y2label "Función de probabilidad"
set xrange[4:10]
set yrange[4:20]
set x2range[4:10]
set y2range[0:1]
set y2tics 0, 0.1
set ytics nomirror

plot "datosp2.dat" index 0 using 3:(1-$1) with lp pt 7 ps 0 lc 6 lw 5 axes x2y2 t '{/Symbol y}(R)', 'datafile.dat' index 2 using 1:2 with lp pt 7 lt 4 lw 5 ps 0 t 'V(R)'

unset output
#lt line type
