#ifndef FUNCTION_B_H
#define FUNCTION_B_H

#include "Function.h"
#include <cmath>

//Defini��o da classe Function_B que herda os atributos e m�todos da classe Function
//representando f(x) = sqrt(1-x�)
class Function_B : public Function
{
public:
	Function_B(double, double);

	double f(double);

	~Function_B();
};

#endif