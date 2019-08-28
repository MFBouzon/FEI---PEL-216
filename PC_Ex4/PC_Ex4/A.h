#ifndef A_H
#define A_H
#include "Function.h"

//definição da classe A que herda os atributos e método da classe Function,
//sendo uma Função A(x)
class A : public Function
{
public:
	A(double = 2.0, double = 1.0, double = 0.001); //construtor padrão
	double Solve(); //método para resolver a função
	double solveDerivative(); //método para resolver a derivada da função
	~A(); //destrutor padrão
};
#endif

