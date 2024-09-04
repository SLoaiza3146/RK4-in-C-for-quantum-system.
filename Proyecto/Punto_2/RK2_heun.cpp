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
double De=8., a=3., Re=5., R, dR=0.001, E=7.,b;

double f(double R){
	b=((J*(J+1))/(pow(R,2))+(De*pow(1-exp(-a*(R-Re)),2)))-E;
return b;
}

int main (){

double y[2], g[2];
double k1[2], k2[2];

y[0]=1., g[0]=0.;

ofstream datos2; 
datos2.open("datos2RK2.dat");

//datos2<<y[0]<<" "<<g[0]<<" "<<Re<<endl;

for(R=Re; R<=10; R+=dR){

	k1[0]=(y[0]*g[0]);
	k1[1]=(f(R)-pow(g[0],2));
	
	y[1]=y[0]+(k1[0]*dR*0.5);
	g[1]=g[0]+(k1[1]*dR*0.5);
	
	k2[0]=(y[1]*g[1]);
	k2[1]=(f(R+dR*0.5)-pow(g[1],2));
	
	y[0]=y[0]+(k2[0]*dR);
	g[0]=g[0]+(k2[1]*dR);
	
	datos2<<y[0]<<" "<<g[0]<<" "<<R<<endl;
	
}

system("gnuplot RK2_2.plt");
//system("RK2_2.png");

return 0;
}
