#include "Toroid.h"
#include <cstdio>

//construtor padrão
Toroid::Toroid()
{
}

//função que define o toroide, sendo f(x) = z² + (sqrt(x²+y²) -3)²
double Toroid::f(double x, double y, double z)
{
	return pow(z,2) + pow(sqrt((x*x)+(y*y)) - 3, 2);
}

//método de Monte Carlo para o cálculo do volume do toroide utilizando n iterações
double Toroid::MonteCarlo(int n)
{
	double V = 42;
	int toroidPoints = 0;
	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		double randX = ((double)rand() / RAND_MAX) * (4-1) + 1;
		double randY = ((double)rand() / RAND_MAX) * (4+3) - 3;
		double randZ = ((double)rand() / RAND_MAX) * (1+1) - 1;

		//printf("x: %lf\n y: %lf\n z: %lf\n", randX, randY, randZ);

		double func = f(randX, randY, randZ);
		if (func <= 1 && randX >= 1 && randY >= -3) {
			toroidPoints++;
		}
	}		

	return V * toroidPoints/ n;
}


//destrutor padrão
Toroid::~Toroid()
{
}
