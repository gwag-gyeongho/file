#include <stdio.h>

typedef struct complex {
	double real;
	double imag;
}Complex;

Complex add(Complex c1, Complex c2);
Complex add2(Complex *c1, Complex *c2);
Complex *add3(Complex *c1, Complex *c2);

Complex sub(Complex c1, Complex c2);

Complex mul(Complex c1, Complex c2);

Complex div(Complex c1, Complex c2);

Complex get_complex(char *s);
void print_complex(Complex c1);

int main(void) {
	Complex c1,c2,c3,c4,c5,c6;
	
    c1=get_complex("c1");
	c2=get_complex("c2");



	c3= *add3(&c1,&c2);
	c4= sub(c1,c2);
	c5= mul(c1,c2);
	c6= div(c1,c2);
	printf("º¹¼Ò¼öÀÇ µ¡¼À : ");
    print_complex(c3);
	printf("º¹¼Ò¼öÀÇ »¬¼À : ");
    print_complex(c4);
    printf("º¹¼Ò¼öÀÇ °ö¼À : ");
    print_complex(c5);
	printf("º¹¼Ò¼öÀÇ ³ª´°¼À : ");
    print_complex(c6);

	return 0;

}

Complex add(Complex c1, Complex c2) {
	Complex result;
	result.real = c1.real+c2.real;
	result.imag = c1.imag+c2.imag;
	return result;

}

Complex add2(Complex *c1, Complex *c2){
	Complex result;
	result.real=c1->real + c2->real;
	result.imag=c1->imag + c2->imag;
	return result;
}

Complex *add3(Complex *c1, Complex *c2){
	static result;
	result.real=c1->real + c2->real;
	result.imag=c1->imag + c2->imag;
	return result;
}

Complex sub(Complex c1, Complex c2) {
	Complex result;
	result.real = c1.real-c2.real;
	result.imag = c1.imag-c2.imag;
	return result;

}

Complex mul(Complex c1, Complex c2) {
	Complex result;
	result.real = c1.real*c2.real-c1.imag*c2.imag;
	result.imag = c1.real*c2.imag+c1.imag*c2.real;
	return result;

}

Complex div(Complex c1, Complex c2){
	Complex result;
	result.real = (c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag);
	result.imag = (-c1.real*c2.imag+c1.imag*c2.real)/(c2.real*c2.real+c2.imag*c2.imag);
	return result;
}

Complex get_complex(char *s){
    Complex result;
    printf("º¹¼Ò¼ö ÀÔ·Â (a+biÇüÅÂ) :");
	scanf("%lf %lf",&result.real,&result.imag);

    return result;
}

void print_complex(Complex c1){
    printf("%f+%fi\n",c1.real,c1.imag);
}