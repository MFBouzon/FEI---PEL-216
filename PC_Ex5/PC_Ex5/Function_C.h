#ifndef FUNCTION_C_H
#define FUNCTION_C_H

#include "Function.h"
#include <cmath>

//Defini��o da classe Function_C que herda os atributos e m�todos da classe Function
//representando f(x) = e^(-x�)
class Function_C : public Function
{
public:
	Function_C(double, double);

	double f(double);

	~Function_C();
};

#endif