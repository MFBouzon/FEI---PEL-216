#ifndef F1_H
#define F1_H
#include <random>
#include <time.h>

//Definição da classe F1
class F1
{
private:
	double a; //intervalo inferior
	double b; //intervalo superior

public:
	F1(double = 0.0, double = 1.0); //construto padrão

	double f(double); //método para calcular f(x)

	double MonteCarlo(int); //método que calcula o valor de pi utilizando Monte Carlo

	~F1(); //destrutor padrão
};

#endif