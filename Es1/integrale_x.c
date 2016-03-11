#include <stdio.h>
#include <math.h>

//#define e 2.7183
double f(double x)
	{
	double f_1;
	f_1=exp(-x*x);
	return f_1;
	}

double I(double a, double x, double dx)
	{
	double xx;
	double integr=0;
	if (x>a) {
		for (xx=a; xx<x; xx=xx+dx){
			integr=(f(xx)+f(xx+dx))*dx/2.0+integr;
		}
	} else {
		integr=0;
		for (xx=a; xx>x; xx=xx-dx){
			integr=-(f(xx)+f(xx-dx))*dx/2.0+integr;
		}
	}


	return integr;
	}

int main()
	{
	FILE *fp;
	fp = fopen("integrale__.dat", "w");
	double a;
	double x;
	double dx;
	a=-4.;
	dx=0.000001;
	double Dx=0.05;
	for (x=-4; x<=4; x=x+Dx){
		fprintf(fp,"%f\t%f\t%f\n", x, I(a, x, dx), f(x));
		printf("%f\t%f\t%f\n", x, I(a, x, dx), f(x));
	}
	fclose(fp);
	return 0;
}

/*
gnuplot> plot './integrale_
./integrale_x      ./integrale_x.c    ./integrale_x.c~   ./integrale__.dat  
gnuplot> plot './integrale__.dat' w l 
gnuplot> plot './integrale__.dat' w l
gnuplot> plot './integrale__.dat' u 1:2 w l, './integrale__.dat' u 1:3 w l
gnuplot> plot './integrale__.dat' u 1:2 w l, './integrale__.dat' u 1:3 w l
gnuplot> plot './integrale__.dat' u 1:2 w l ti 'I(x)', './integrale__.dat' u 1:3 w l ti 'f(x)'
gnuplot> set key top left
gnuplot> plot './integrale__.dat' u 1:2 w l ti 'I(x)', './integrale__.dat' u 1:3 w l ti 'f(x)'
gnuplot> plot './integrale__.dat' u 1:2 w l ti 'I(x)', './integrale__.dat' u 1:3 w l ti 'f(x)'
gnuplot> 
*/



