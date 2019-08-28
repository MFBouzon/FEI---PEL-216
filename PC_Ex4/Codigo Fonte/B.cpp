#include "B.h"


//construtor que chama o construtor da classe base
B::B(double x, double B, double E) : Function(x, B, E)
{
}

//retorna resolu��o da fun��o B = x� - 2x� + 2
double B::Solve()
{
	return (getX0()*getX0()*getX0()) - (2 * getX0()*getX0()) + 2;
}

//retorna a resolu��o da fun��o derivada B' = 3x� - 4x
double B::solveDerivative()
{
	return (3 * getX0()*getX0()) - (4 * getX0());
}

//destrutor padr�o
B::~B()
{
}
