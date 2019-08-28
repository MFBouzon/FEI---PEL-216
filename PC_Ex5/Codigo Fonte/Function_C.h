#ifndef FUNCTION_C_H
#define FUNCTION_C_H

#include "Function.h"
#include <cmath>

//Definição da classe Function_C que herda os atributos e métodos da classe Function
//representando f(x) = e^(-x²)
class Function_C : public Function
{
public:
	Function_C(double, double);

	double f(double);

	~Function_C();
};

#endif