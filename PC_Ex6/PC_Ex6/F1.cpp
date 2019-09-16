#include "F1.h"

//construtor padr�o que recebe duas vari�veis do tipo double
F1::F1(double a, double b)
{
	this->a = a;
	this->b = b;
}

//m�todo que retorna f(x), sendo f(x) = 4/(1+x�)
double F1::f(double x)
{
	return 4/(1+(x*x));
}


//m�todo para calcular pi utilizando Monte Carlo com n itera��es
double F1::MonteCarlo(int n)
{
	double sum = 0;
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		double rand1 = ((double)rand() / RAND_MAX);
		//printf("x: %lf\n", rand1);
		sum += f(rand1);
	}

	return sum/n;
}

//destrutor padr�o
F1::~F1()
{
}
