#include<stdio.h>
#include<math.h>
#define epsilon 8.8542*pow(10,-12)


double fabs(double x){
	if(x<0){
		x=-x;	
	}
	return x;
}

double r_t(double t){
	return t/(1.0-t);
}

double r_z(double z){
	return 1./z;
}

double rho(double r, double alfa){
	return (alfa*exp(-pow(r,2)/2.0));
}

double rho_sferico(double r, double alfa){
	return (rho(r, alfa)*4*M_PI*pow(r,2));
}


double calc_Q(double r, double alfa, double dr){
	double integq=0, rr=0;
	if(dr>r/100){
		dr = r/100;
	}
	for(rr=0; rr<r; rr+=dr){
		integq=integq+(rho_sferico(rr, alfa)+rho_sferico(rr+dr, alfa))*dr/2;
	}
	return integq;
}

double calc_E(double r, double dr, double ke, double alfa){
	double EE;
	if(r!=0){
		EE=ke*calc_Q(r, alfa, dr)/(pow(r,2));
	} else {
		EE=0;
	}
	return EE;
}

double calc_E_t(double t, double dr, double ke, double alfa){
	return calc_E(r_t(t), dr, ke, alfa)/pow((1-t),2);
}

double calc_E_z(double z, double dr, double ke, double alfa){
	return calc_E(r_z(z), dr, ke, alfa)/pow(z,2);
}

double calc_V(double r, double dr, double ke, double alfa){
	double integV=0, rr=r;
	double temp=0;
	int i=0;
	dr=0.001;
	while(i<1000 || fabs(integV-temp)/fabs(integV)/dr>0.0005){
		temp=integV;
		integV=integV+( calc_E(rr, dr, ke, alfa) + calc_E(rr+dr, dr, ke, alfa) )*dr/2;
		i+=1;
		rr+=dr;
//		if (rr>30){
//			dr =0.01;
//		}
	}
	printf("r_infinito = %f\ni = %d\nabs(integV-temp)/abs(integV)/dr = %f\n", rr, i, (fabs(integV-temp)/fabs(integV)/dr));
	return integV;
}




double calc_V_2(double r, double dr, double dz, double ke, double alfa){
	double integV=0, z;
	for(z=dz/2; z<1/r; z+=dz){
		integV=integV+( calc_E_z(z, dr, ke, alfa) + calc_E_z(z+dz, dr, ke, alfa) )*dz/2;
	}
	return integV;
}


double calc_V_3(double r, double dr, double dz, double ke, double alfa){
	double integV=0, z;
	for(z=0; z<=1/r-dz; z+=dz){
		integV=integV+( calc_E_z(z+dz/3., dr, ke, alfa) + calc_E_z(z+dz*2./3., dr, ke, alfa) )*dz/2.;
	}
	return integV;
}

double calc_V_4(double r, double dr, double dz, double ke, double alfa){
	double integV=0, z;
	for(z=0; z<=1/r-dz; z+=dz){
		integV=integV+( calc_E_z(z+dz/2., dr, ke, alfa) )*dz;
	}
	return integV;
}

int main() {
	double alfa=2, r=5, dr=0.001, dz=0.0001;
	double ke=1;
	

	//int n, i;
	//printf("dammi alfa: ");
	//scanf("%lf", &alfa);

	printf("dammi r: ");
	scanf("%lf", &r);


	//n=r/dr;
	//double Q, E;
/*	double *pQ, *pE;
	pQ=&Q[0];
	pE=&E[0];*/

	printf("Q[%f] = %f\n", r, calc_Q(r, alfa, dr));
	printf("E[%f] = %f\n", r, calc_E(r, dr, ke, alfa));

//	printf("V[%f] = %f\n", r, calc_V(r, dr, ke, alfa));

/*	double t, V_0=0, dt=0.0001;
	for(t=0; t<1-2*dt; t+=dt){
		V_0=V_0+( calc_E_t(t, dr, ke, alfa) + calc_E_t((t+dt), dr, ke, alfa) )*dt/2;
		printf("t = %f\nV[0] = %f\n", t, V_0);
	}
	printf("V[0] = %f\n", V_0);*/

	printf("V[%f] = %f\n", r, calc_V_4(r, dr, dz, ke, alfa));
	printf("V[%f] = %f\n", r, calc_V_2(r, dr, dz, ke, alfa));
	printf("V[%f] = %f\n", r, calc_V_3(r, dr, dz, ke, alfa));


// Salvataggio di E(r) quando r tende a 0
/*	double drr=0.00000001, rr, E_0;
	dr=0.000000001;
	for(rr=0.00005; rr>0.00000001; rr-=drr){
		E_0=calc_E(rr, dr, ke, alfa);
		//printf("E[%.10f] = %.10f\n", rr, E_0);
		printf("%.10f\t%.10f\n", rr, E_0);
	}
*/


// E(r)
/*	double drr=0.01, rr, E_0;
	dr=0.001;
	for(rr=0; rr<=50; rr+=drr){
		E_r=calc_E(rr, dr, ke, alfa);
		//printf("E[%.10f] = %.10f\n", rr, E_0);
		printf("%.10f\t%.10f\n", rr, E_r);
	}
*/











/*	for(i=0; i<n; i++){
		printf("%d\t%f\n", i, E[i]);
	}
	printf("E[%f] = %f\n", r, E[n-1]);*/

/*	for(i=0; i<n; i++){
		printf("%d\t%f\n", i, Q[i]);
	}
	printf("Q[%f] = %f\n", r, Q[n-1]);*/

	return 0;
}
