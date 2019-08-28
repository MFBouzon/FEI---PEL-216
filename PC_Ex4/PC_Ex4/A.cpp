#include "A.h"

//construtor que chama o construtor da classe base
A::A(double x, double B, double E) : Function(x, B, E)
{
}

//retorna resolu��o da fun��o A = x�
double A::Solve()
{
	return getX0() * getX0();
}

//retorna a resolu��o da fun��o derivada A' = 2x
double A::solveDerivative()
{
	return 2 * getX0();
}

//destrutor padr�o
A::~A()
{
}
