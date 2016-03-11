#include<stdio.h>
#include<math.h>
//#define k 1.381*pow(10,-23)


double v(double x){
	double v_1;
	v_1 = 4.0*(pow(x,-12)-pow(x,-6));
	return v_1;
}

double f(double x, double T){
	double f_1;
	f_1 = (exp(-v(x)/T)-1.0)*pow(x,2);
	return f_1;
}

double I(double a, double b, double T, double dx){
	double x, Int=0;	
	for (x=a; x<b; x=x+dx){
		Int=(f(x, T)+f(x+dx, T))/2.0*dx + Int;
	}
	return Int;	
}

double B(double a, double b, double T, double dx){
	return -2*M_PI*I(a, b, T, dx);	
}

double bisezione(double a1, double b1, double precisione, double a, double b, double dx){
	double c=(a1+b1)/2.;
	while( fabs(a1-b1)/(fabs(b1))>precisione ){
		if(B(a, b, c, dx)*B(a, b, a1, dx)>0){
			a1=c;
		} else {
			b1=c;
		}
		c=(a1+b1)/2.;
	}
	return c;
}

int main() {
	double a=0.01, b=100, dx=0.01, a1=3, b1=4, precisione10;
	//double T, T_min=1, T_max=150, dT=0.05;
	//double epsilon=1.41*pow(10, -22), sigma= 256*pow(10, -12);
	//double x, T_reale, x_reale;
/*	FILE *fp;
	fp= fopen("file.dat", "w");
	//printf("T\tB(T)\n")
	for (T=T_min; T<=T_max; T=T+dT){
		//printf("%.4f\t%.4f\n", T, -2*M_PI*I(a, b, T, dx));
		fprintf(fp,"%.4f\t%.4f\n", T, -2*M_PI*I(a, b, T, dx));
	}
	fclose(fp);*/
	printf("B[%f] = %f\n", a1, B(a, b, a1, dx));
	printf("B[%f] = %f\n", b1, B(a, b, b1, dx));
	printf("dammi la precisione: ");
	scanf("%lf", &precisione10);
	double precisione=pow(10,-precisione10);
	printf("Lo zero di B è a T = %f\n", bisezione(a1, b1, precisione, a, b, dx));
	
	return 0;

}
