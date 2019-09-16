#ifndef TOROID_H
#define TOROID_H
#include <random>
#include <time.h>
#include <cmath>
#include <mpi.h>

//Definição da classe Toroid que representa um toroide parcial
class Toroid
{
public:
	Toroid(); //construtor padrão

	double f(double, double, double); //f(x) que define o toroide
	int MonteCarlo(int); //método que calcula o volume do toroide utilizando Monte Carlo

	~Toroid(); //destrutor padrão
};
#endif