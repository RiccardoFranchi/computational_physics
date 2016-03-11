#include<stdio.h>
#include<math.h>


double v(double x){
	return 4.0*(pow(x,-12)-pow(x,-6));
}

double radiciona(double x, double E){
	double var;
	var = E-v(x);
	if ( var < 0 ){
		var = 0;	
	}
	return sqrt(2*var)/M_PI;
}

double I(double E, double dx){
	double x, Int=0;
	//dx=sqrt(E*2.)/1000.;
	//printf("\ndx = %f\n", dx);
	//dx=0.0001;
	if (sqrt(1+E)<1) {// è sbegnlo non può essere mai vero!!!
		double z1=(1+sqrt(1+E))/2., z2=(1-sqrt(1+E))/2.;
		for (x=pow(1/z1,1/6.); x<=pow(1/z2,1/6.); x=x+dx){
			Int=Int + (radiciona(x, E)+radiciona(x+dx, E))/2.0*dx;
		}
	} else if (sqrt(1+E)==1) {
		double z1=(1+sqrt(1+E))/2., temp = 0;
		int i=0;
		Int = 0;
		x=pow(1/z1,1/6.);
		while (i<1000 || fabs(Int-temp)/fabs(Int)/dx>0.0005) {
			temp=Int;
			Int=Int + (radiciona(x, E)+radiciona(x+dx, E))/2.0*dx;
			i+=1;
			x+=dx;
		}
	} else {
		printf("\ncon E=%f il potenziale Lennard-Jones non presenta alcuno stato legato\n", E);
		Int = -1;
	}
//	printf("Int: %f, %f\n", Int, dx);
	return Int;	
}

double f(double n, double E, double dx){
	return ((n+1/2.)-I(E, dx));
}


void trova_zeri(double n, double dx, double *a1, double *b1, double de){
	double e1=0;
	*a1=0;
	*b1=0;
	while(*a1==0){
		if(f(n, e1, dx)*f(n, e1+de, dx)<=0){
			*a1=e1;
			*b1=e1+de;
		}
		printf("\na1: %f\tf(%f, %.0f) = %f\t%f\n", *a1, e1, n, f(n, e1, dx), f(n, e1, dx)*f(n, e1+de, dx));
		e1+=de;
	}
	//printf("\na1 = %f\tb1 = %f\n", *a1, *b1);
}


double bisezione(double a1, double b1, double precisione, double n, double dx, double de){
	trova_zeri(n, dx, &a1, &b1, de);
	double c=(a1+b1)/2.;
	while( fabs(a1-b1)/(fabs(b1))>precisione ){
		if(f(n, c, dx)*f(n, a1, dx)>0){
			a1=c;
		} else {
			b1=c;
		}
		c=(a1+b1)/2.;
		//printf("\nc: %f\n", c);
	}
	return c;
}

int main() {
	double n, dx=0.0001, de=0.01, precisione10, a1=0, b1=9;
	printf("dammi la precisione: ");
	scanf("%lf", &precisione10);
	double precisione=pow(10,-precisione10);
	n=0;
	//printf("n = %f\tr = %f\n", n, radiciona(5, 0.5));
	//printf("n = %f\tI = %f\n", n, I(0.5, dx));
	for(n=0; n<=3; n++){
		//printf("n = %f\tf = %f\n", n, f(n, 0.5, dx));
		printf("n = %f\tEn = %f\n", n, bisezione(a1, b1, precisione, n, dx, de));
	}


	return 0;

}
