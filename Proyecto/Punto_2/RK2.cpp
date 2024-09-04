#include<iostream> 
#include<fstream> 
#include<cmath> 
#include<string>
#include<cstdlib>
#include<cstdio>
#include<windows.h>
#include<iomanip>

using namespace std;
int J=11;
long double De=8, a=3, Re=5, R, dR=0.001, E=8.831;
//long double De=7.392*pow(10,-19), a=1.812*pow(10,10), Re=1.275*pow(10,-8), R, dR=0.001, E=0.0001;

double f(double R){
	long double b;
	b=((J*(J+1))/(pow(R,2))+(De*pow(1-exp(-a*(R-Re)),2)))-E;
return b;
}

int main (){

long double y[2], g[2];
long double k1[2], k2[2];

y[0]=1, g[0]=0.;

ofstream datos; 
datos.open("datosRK2.dat");

datos<<y[0]<<" "<<g[0]<<" "<<Re<<endl;
for(R=Re; R<=100; R+=dR){

k1[0]=dR*(y[0]*g[0]);
k1[1]=dR*(f(R)-pow(g[0],2));

k2[0]=dR*((y[0]+k1[0])*(g[0]+k1[1]));
k2[1]=dR*(f(R+dR)-pow(g[0]+k1[1],2));

y[0]=y[0]+((k1[0]+k2[0])/2.);
g[0]=g[0]+((k1[1]+k2[1])/2.);

datos<<y[0]<<" "<<g[0]<<" "<<R<<endl;
}

system("gnuplot grafica_RK2.plt");
//system("grafica_RK2.png");

return 0;
}
