#include "A.h"

//construtor que chama o construtor da classe base
A::A(double x, double B, double E) : Function(x, B, E)
{
}

//retorna resolução da função A = x²
double A::Solve()
{
	return getX0() * getX0();
}

//retorna a resolução da função derivada A' = 2x
double A::solveDerivative()
{
	return 2 * getX0();
}

//destrutor padrão
A::~A()
{
}
