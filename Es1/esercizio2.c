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

int main() {
	double a=0.01, b=100, T, dx=0.01, T_min=1, T_max=150, dT=0.05;
	//double epsilon=1.41*pow(10, -22), sigma= 256*pow(10, -12);
	//double x, T_reale, x_reale;
	FILE *fp;
	fp= fopen("file.dat", "w");
	//printf("T\tB(T)\n")
	for (T=T_min; T<=T_max; T=T+dT){
		//printf("%.4f\t%.4f\n", T, -2*M_PI*I(a, b, T, dx));
		fprintf(fp,"%.4f\t%.4f\n", T, -2*M_PI*I(a, b, T, dx));
	}
	fclose(fp);
	
	
	return 0;

}
