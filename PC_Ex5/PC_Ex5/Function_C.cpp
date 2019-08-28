#include "Function_C.h"



Function_C::Function_C(double a, double b) : Function(a, b)
{
}

//f(x) = e^-x²
double Function_C::f(double x)
{
	return exp(-(x*x));
}

Function_C::~Function_C()
{
}
