#include "F1.h"

//construtor padrão que recebe duas variáveis do tipo double
F1::F1(double a, double b)
{
	this->a = a;
	this->b = b;
}

//método que retorna f(x), sendo f(x) = 4/(1+x²)
double F1::f(double x)
{
	return 4/(1+(x*x));
}


//método para calcular pi utilizando Monte Carlo com n iterações
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

//destrutor padrão
F1::~F1()
{
}
