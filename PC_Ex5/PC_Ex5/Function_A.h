#ifndef FUNCTION_A_H
#define FUNCTION_A_H

#include "Function.h"
#include <cmath>


//Defini��o da classe Function_A que herda os atributos e m�todos da classe Function
//representando f(x) = e^x
class Function_A : public Function
{
public:
	Function_A(double, double);

	double f(double);

	~Function_A();
};

#endif