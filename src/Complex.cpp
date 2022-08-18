#include "Complex.h"

Complex c_add(Complex *c1, Complex *c2){
	Complex result;
	result.re=c1->re + c2->re;
	result.im=c1->im + c2->im;
	return result;
}

Complex c_substract(Complex *c1, Complex *c2){
	Complex result;
	result.re=c1->re - c2->re;
	result.im=c1->im - c2->im;
	return result;
}


Complex c_multiply(Complex *c1, Complex *c2){
	Complex result;
	result.re=c1->re * c2->re  - c1->im * c2->im;
	result.im=c1->re * c2->im + c1->im * c2->re;
	return result;
}

Complex c_divide(Complex *c1, Complex *c2){
	Complex result;
	double d = c2->re*c2->re + c2->im * c2->im;
	if(d==0){
		cout << "Complex::c_divide(Complex *c1, Complex *c2): c2 must not be null.\n";
		exit(1); 
	}
	result.re=(c1->re*c2->re + c1->im * c2->im) / d;
	result.im=(c1->im*c2->re + c1->re * c2->im) / d;
	return result;
}

void print_complex(Complex *c){
	cout << c->re << "+ i * " << c->im << endl;

}
