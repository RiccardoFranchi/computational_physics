#include <stdio.h>
#include <math.h>

//#define e 2.7183
double f(double x)
	{
	double f_1;
	f_1=exp(-x*x);
	return f_1;
	}

double I(double a, double b, double dx)
	{
	double x;
	double integr;
	for (x=a; x<b; x=x+dx){
		integr=(f(x)+f(x+dx))*dx/2.0+integr;
	}
	return integr;
	}

int main()
	{
	//double x;
	double a;
	double b;
	double dx;
/*	double x_min;
	double x_max;
	double Dx;*/
/*	printf("x_min=");
	scanf("%lf", &x_min);
	printf("x_max=");
	scanf("%lf", &x_max);
	printf("Dx=");
	scanf("%lf", &Dx);*/
	//double integrale;
	//for (x=x_min; x<x_max; x=x+Dx)
/*	a=x_min;
	b=x_max;
	dx=Dx;*/
	a=-100;
	b=100;
	dx=0.0001;
	//integrale= integrale+I(double x, double a, double b, double dx);	
	printf("l'integrale è %lf\n", I(a, b, dx));
	return 0;
	}

