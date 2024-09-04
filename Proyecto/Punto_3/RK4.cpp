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
double De=8, a=3, Re=5, R, dR=0.001, E=9.,b;

double f(double R){
	b=((J*(J+1))/(pow(R,2))+(De*pow(1-exp(-a*(R-Re)),2)))-E;
return b;
}

int main (){
	
double y[4], g[4];
double k1[2], k2[2], k3[2], k4[2];

y[0]=1., g[0]=0.;

ofstream datos3; 
datos3.open("datosRK4.dat");

datos3<<y[0]<<" "<<g[0]<<" "<<Re<<endl;
for(R=Re; R<=10.; R+=dR){

k1[0]=dR*(y[0]*g[0]);
k1[1]=dR*(f(R)-pow(g[0],2));

//y[1]=(y[0]*g[0]);
//g[1]=(f(R)-pow(g[0],2));

k2[0]=dR*((y[0]+k1[0]*0.5)*(g[0]+k1[1]*0.5));
k2[1]=dR*(f(R+dR*0.5)-pow(g[0]+k1[1]*0.5,2));


//y[2]=(y[1]*g[1]);
//g[2]=(f(R+(dR*0.5))-pow(g[1],2));

k3[0]=dR*((y[0]+k2[0]*0.5)*(g[0]+k2[1]*0.5));
k3[1]=dR*(f(R+dR*0.5)-pow(g[0]+k2[1]*0.5,2));

//y[2]=(y[1]*g[1]);
//g[2]=(f(R+(dR*0.5))-pow(g[1],2));

k4[0]=dR*((y[0]+k3[0])*(g[0]+k3[1]));
k4[1]=dR*(f(R+dR)-pow(g[0]+k3[1],2));

y[0]=y[0]+((k1[0]+(2*k2[0])+(2*k3[0])+k4[0])/6.);
g[0]=g[0]+((k1[1]+(2*k2[1])+(2*k3[1])+k4[1])/6.);

//cout<<k1[0]<<" "<<k2[0]<<" "<<k3[0]<<" "<<k4[0]<<endl;
//cout<<k1[1]<<" "<<k2[1]<<" "<<k3[1]<<" "<<k4[1]<<endl;
datos3<<y[0]<<" "<<g[0]<<" "<<R<<endl;
}

system("gnuplot RK4.plt");
//system("RK4.png");

return 0;
}
