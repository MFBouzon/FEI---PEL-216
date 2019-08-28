#include "Function.h"

#include<cmath>
#include<iostream>
using namespace std;

//construtor que recebe 3 valores double,
// sendo x o valor de x inicial, B a taxa de aprendizado e E a taxa de erro
Function::Function(double x, double B, double E)
{
	x0 = x;
	beta = B;
	epsilon = E;

}


//define o valor de X
void Function::setX0(double x)
{
	x0 = x;
}

//define a taxa de aprendizado
void Function::setBeta(double B)
{
	beta = B;
}

//define a taxa de erro
void Function::setEpsilon(double E)
{
	epsilon = E;
}

//retorna o valor de X atual
double Function::getX0()
{
	return x0;
}

//retorna a taxa de aprendizado
double Function::getBeta()
{
	return beta;
}


//retorna a taxa de erro aceit�vel
double Function::getEpsilon(double)
{
	return epsilon;
}

//m�todo abstrato para resolver a fun��o
double Function::Solve()
{
	return 0;
}

//m�todo abstrato para resolver a derivada da fun��o
double Function::solveDerivative()
{
	return 0;
}

//implementa��o do m�todo Newton-Raphson que retorna a raiz da fun��o
double Function::Newton_Raphson()
{
	double f = Solve();
	while (abs(f) >= epsilon) {
		double s = solveDerivative();
		
		setX0(x0 + (beta * (-f / s)));
		
		f = Solve();
		//cout << f << endl;
	}

	return x0;
}

//implementa��o do m�todo Descida de Gradiente que retorna o m�nimo da fun��o
double Function::GradientDescent()
{
	double s = solveDerivative();
	while (abs(s) >= epsilon) {
		
		setX0(x0 - (beta * s));

		s = solveDerivative();
		
		//cout << s << endl;
	}

	return x0;
}

//destrutor padr�o
Function::~Function()
{
}

