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
double De=8, a=3, Re=5, R, dR=0.001, E=7.;
double v, b, c;
long double y[4], g[4];


double f(double R){
	v=((J*(J+1))/(pow(R,2))+(De*pow(1-exp(-a*(R-Re)),2)))-E;
return v;
}
double fg(double R, int n){

	b=(f(R)-pow(g[n],2));
	
return b;
}
double fy(int n){
	c=(y[n]*g[n]);
return c;
}

int main (){
	
double f0[2], f1[2], f2[2], f3[2];
double R1,R2,R3;

y[0]=1., g[0]=0;

ofstream datos4; 
datos4.open("datosRK4_2.dat");

datos4<<y[0]<<" "<<g[0]<<" "<<Re<<endl;	
for(R=Re; R<=10.; R+=dR){
	f0[0]=fy(0);
	f0[1]=fg(R,0);

	R1=R+dR*0.5;
	y[1]=y[0]+dR*f0[0]*0.5;
	g[1]=g[0]+dR*f0[1]*0.5;
	
	f1[0]=fy(1);
	f1[1]=fg(R1,1);
	
	R2=R+dR*0.5;
	y[2]=y[0]+dR*f1[0]*0.5;
	g[2]=g[0]+dR*f1[1]*0.5;
	
	f2[0]=fy(2);
	f2[1]=fg(R2,2);
	
	R3=R+dR;
	y[3]=y[0]+dR*f2[0];
	g[3]=g[0]+dR*f2[1];
	
	f3[0]=fy(3);
	f3[1]=fg(R3,3);
	
	y[0]=y[0]+dR*(f0[0]+2.0*f1[0]+2.0*f2[0]+f3[0])/6.;
	g[0]=g[0]+dR*(f0[1]+2.0*f1[1]+2.0*f2[1]+f3[1])/6.;
	
	datos4<<y[0]<<" "<<g[0]<<" "<<R<<endl;
}

system("gnuplot RK4_2.plt");
//system("RK4_2.png");
return 0;
}
