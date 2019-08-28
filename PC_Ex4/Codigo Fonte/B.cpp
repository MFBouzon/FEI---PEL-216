#include "B.h"


//construtor que chama o construtor da classe base
B::B(double x, double B, double E) : Function(x, B, E)
{
}

//retorna resolução da função B = x³ - 2x² + 2
double B::Solve()
{
	return (getX0()*getX0()*getX0()) - (2 * getX0()*getX0()) + 2;
}

//retorna a resolução da função derivada B' = 3x² - 4x
double B::solveDerivative()
{
	return (3 * getX0()*getX0()) - (4 * getX0());
}

//destrutor padrão
B::~B()
{
}
