#ifndef B_H
#define B_H
#include "Function.h"
//defini��o da classe B que herda os atributos e m�todo da classe Function,
//sendo uma Fun��o B(x)
class B : public Function
{
public:
	B(double = 2.0, double = 1.0, double = 0.001); //construtor padr�o
	double Solve(); //m�todo para resolver a fun��o
	double solveDerivative(); //m�todo para resolver a derivada da fun��o
	~B(); //destrutor padr�o
};

#endif