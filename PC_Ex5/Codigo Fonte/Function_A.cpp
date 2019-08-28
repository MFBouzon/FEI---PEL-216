#include "Function_A.h"



Function_A::Function_A(double a, double b) : Function(a, b)
{
}

//f(x) = e^x
double Function_A::f(double x)
{
	return exp(x);
}



Function_A::~Function_A()
{
}
