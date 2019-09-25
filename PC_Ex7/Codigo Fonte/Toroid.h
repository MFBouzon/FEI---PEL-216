#ifndef TOROID_H
#define TOROID_H
#include <random>
#include <time.h>
#include <cmath>
#include <mpi.h>

//Defini��o da classe Toroid que representa um toroide parcial
class Toroid
{
public:
	Toroid(); //construtor padr�o

	double f(double, double, double); //f(x) que define o toroide
	int MonteCarlo(int); //m�todo que calcula o volume do toroide utilizando Monte Carlo

	~Toroid(); //destrutor padr�o
};
#endif