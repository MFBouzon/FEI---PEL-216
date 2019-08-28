#ifndef A_H
#define A_H
#include "Function.h"

//defini��o da classe A que herda os atributos e m�todo da classe Function,
//sendo uma Fun��o A(x)
class A : public Function
{
public:
	A(double = 2.0, double = 1.0, double = 0.001); //construtor padr�o
	double Solve(); //m�todo para resolver a fun��o
	double solveDerivative(); //m�todo para resolver a derivada da fun��o
	~A(); //destrutor padr�o
};
#endif

