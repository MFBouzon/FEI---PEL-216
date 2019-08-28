#include "Function_B.h"



Function_B::Function_B(double a, double b) : Function(a, b)
{
}


//f(x) = sqrt(1-x²)
double Function_B::f(double x)
{
	if (1 - x < 0)
		return 1;
	return sqrt(1-(x*x));
}

Function_B::~Function_B()
{
}
