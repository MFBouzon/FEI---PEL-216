#ifndef B_H
#define B_H
#include "Function.h"
//definição da classe B que herda os atributos e método da classe Function,
//sendo uma Função B(x)
class B : public Function
{
public:
	B(double = 2.0, double = 1.0, double = 0.001); //construtor padrão
	double Solve(); //método para resolver a função
	double solveDerivative(); //método para resolver a derivada da função
	~B(); //destrutor padrão
};

#endif