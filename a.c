#include <stdio.h>

void comp1(double a,double *v, double *s);
double vol(double a, double *v);
double sarea(double a,double *s);

int main(){
	double a;
	double v,s;
	scanf("%lf",&a);

	comp1(a,&v,&s);
	printf("%f ,%f\n",v,s);
	v=vol(a,&v);
	printf("%f ,%f\n",v,s);
	s=sarea(a,&s);
	printf("%f ,%f\n",v,s);

	return 0;
}

void comp1(double a, double *v, double *s){
	*v=a*a*a;
	*s=a*a*6;
}

double vol(double a, double *v){
	
	*v = a*a*a;
	return a*a*a;
}
double sarea(double a,double *s){
	*s=6*a*a;
	return a*a*6;
}
