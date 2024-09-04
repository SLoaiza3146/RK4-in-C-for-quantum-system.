#include<iostream> 
#include<fstream> 
#include<cmath> 
#include<string>
#include<cstdlib>
#include<cstdio>
#include<windows.h>
#include<iomanip>

using namespace std;

int main (){

	double De=8, a=3, Re=5, R, result, dR=0.01;

	ofstream datos;
	datos.open("datafile.dat");
	int J,i;
	for (J=11,i=0; J<=21; J++,i++){
		ofstream gnuplot; 
		gnuplot.open("grafica.plt");

		for(R=0; R<=100; R+=dR){

			result=(J*(J+1))/(pow(R,2))+(De*pow(1-exp(-a*(R-Re)),2));
			datos<<R<<" "<<result<<endl;
		}

		datos<<endl<<endl;
		gnuplot<<"set terminal pngcairo transparent enhanced color size 1366,768 font 'times new roman, 22'"<<endl;
		gnuplot<<"set output 'C:/Users/usuario/Desktop/Proyecto/Punto_1/Imagenes/"<<setw(3)<<i<<"grafica.png"<<endl;
		gnuplot<<endl;
		gnuplot<<"set samples 2000"<<endl;
		gnuplot<<"set multiplot layout 1,2"<<endl;
		gnuplot<<endl;
		gnuplot<<"set key top right"<<endl;
		gnuplot<<"set xrange[3:15]"<<endl;
		gnuplot<<"set yrange[4:20]"<<endl;
		gnuplot<<"set xlabel 'Distancia internuclear R'"<<endl;
		gnuplot<<"set ylabel 'Energia'"<<endl;
		gnuplot<<endl;
		gnuplot<<"plot 'datafile.dat' index "<<i<<" using 1:2 with lp pt 7 lt 4 lw 5 ps 0 t 'J="<<J<<"'"<<endl<<endl;
		gnuplot<<"reset"<<endl;
		gnuplot<<endl;
		gnuplot<<"set key top right"<<endl;
		gnuplot<<"set xrange[5:8]"<<endl;
		gnuplot<<"set yrange[8:22]"<<endl;
		gnuplot<<"set xlabel 'Distancia internuclear R'"<<endl;
		gnuplot<<"set ylabel 'Energia'"<<endl;
		gnuplot<<endl;
		gnuplot<<"plot 'datafile.dat' index "<<i<<" using 1:2 with lp pt 7 lt 4 lw 5 ps 0 t 'J="<<J<<"'"<<endl<<endl;
		gnuplot<<"unset multiplot"<<endl;
		gnuplot<<"unset output"<<endl;
	
		system("gnuplot grafica.plt");
		gnuplot.close();
		remove("grafica.plt");
		}

	datos.close();
	system("magick convert -delay 28 -loop 0 -dispose previous C:/Users/usuario/Desktop/Proyecto/Punto_1/Imagenes/*grafica.png Animacion.gif");
	
return 0;
}
