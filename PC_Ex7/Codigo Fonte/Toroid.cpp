#include "Toroid.h"
#include <cstdio>

//construtor padr�o
Toroid::Toroid()
{
}

//fun��o que define o toroide, sendo f(x) = z� + (sqrt(x�+y�) -3)�
double Toroid::f(double x, double y, double z)
{
	return pow(z, 2) + pow(sqrt((x*x) + (y*y)) - 3, 2);
}

//m�todo de Monte Carlo distribuido para o c�lculo do volume do toroide utilizando n itera��es
int Toroid::MonteCarlo(int N)
{
	int toroidPoints = 0;

	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		double randX = ((double)rand() / RAND_MAX) * (4 - 1) + 1;
		double randY = ((double)rand() / RAND_MAX) * (4 + 3) - 3;
		double randZ = ((double)rand() / RAND_MAX) * (1 + 1) - 1;

		//printf("x: %lf\n y: %lf\n z: %lf\n", randX, randY, randZ);

		double func = f(randX, randY, randZ);
		if (func <= 1 && randX >= 1 && randY >= -3) {
			toroidPoints++;
		}
	}

	return toroidPoints;
}

//destrutor padr�o
Toroid::~Toroid()
{
}
