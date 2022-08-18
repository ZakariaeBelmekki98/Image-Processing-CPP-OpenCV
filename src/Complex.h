#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct { double re, im; } Complex;

Complex c_add(Complex *c1, Complex *c2);
Complex c_substract(Complex *c1, Complex *c2);
Complex c_multiply(Complex *c1, Complex *c2);
Complex c_divide(Complex *c1, Complex *c2);
void print_complex(Complex *c);
