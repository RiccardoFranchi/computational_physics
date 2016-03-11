#include<stdio.h>
#include<math.h>

double fabs(double x){
	if(x<0){
		x=-x;	
	}
	return x;
}


double mysqrt(double alfa, double precisione){
	double x,xo=1;
	//x=1/2.*(xo+alfa/xo);
	while( fabs(pow(x,2)-alfa)/(fabs(alfa))>precisione ){
		x=1/2.*(xo+alfa/xo);
		xo=x;
	}	
	return x;		
}

int main() {
	double alfa, precisione10;
	printf("dammi alfa: ");
	scanf("%lf", &alfa);
	printf("\ndammi la precisione: ");
	scanf("%lf", &precisione10);
	double precisione=pow(10,-precisione10);
	printf("\nla radice di %f = %f\t %f\n", alfa, mysqrt(alfa, precisione), sqrt(alfa));
	return 0;
}
