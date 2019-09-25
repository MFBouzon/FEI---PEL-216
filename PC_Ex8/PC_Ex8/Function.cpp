#include "Function.h"

#include<cmath>
#include<iostream>
using namespace std;

//Função para calcular o fatorial de um inteiro n
int factorial(int n)
{
	if (n == 1 || n == 0)
		return 1;
	else
		return(factorial(n - 1)*n);
}


//construtor que recebe 2 valores double,
// sendo a o valor do intervalo inferior e b o valor do intervalo superior
Function::Function(double a, double b)
{
	this->a = a;
	this->b = b;
}

//define o valor de a
void Function::setA(double a)
{
	this->a = a;
}

//define o valor de b
void Function::setB(double b)
{
	this->b = b;
}

//retorna o valor de a
double Function::getA()
{
	return a;
}

//retorna o valor de b
double Function::getB()
{
	return b;
}

//retorna f(x) = e^-x²
double Function::f(double x)
{
	return exp(-(x*x));
}

//retorna a derivada de f(x) de ordem n
double Function::derivativeNthOrder(double x, int n)
{
	double sum = 0;
	double h = 0.0009;
	for (int i = 0; i <= n; i++) {
		double signal = pow(-1, i + n);
		double fat = (factorial(n) / (factorial(i) * factorial(n - i)));
		double func = f(x + (i * h));
		sum = sum + (signal *(fat * func));
	}
	sum = sum / pow(h, n);

	return sum;
}

//método de integração numérica utilizando regra do ponto médio
double Function::Midpoint(int n, int t)
{
	double h = (b - a) / n;
	double sum = 0;
#pragma omp parallel for reduction(+:sum) num_threads(t)
	for (int i = 0; i < n; i++) {
		double up = a + i * h;
		double low = a + (i + 1)*h;
		sum += (b - a) * f((up + low) / 2);
	}
	return sum / n;
}

//método de integração numérica utilizando regra do trapézio
double Function::Trapezoidal(int n, int t)
{
	double h = (b - a) / n;
	double sum = 0;
#pragma omp parallel for reduction(+:sum) num_threads(t)
	for (int i = 0; i < n; i++) {
		double up = a + i * h;
		double low = a + (i + 1)*h;
		sum += (b - a) *0.5 * (f(up) + f(low));
	}
	return sum / n;
}

//método de integração numérica utilizando regra de Simpson
double Function::Simpson(int n, int t)
{
	double h = (b - a) / n;
	double sum = 0;

#pragma omp parallel for reduction(+:sum) num_threads(t)
	for (int i = 0; i < n; i++) {
		double up = a + i * h;
		double low = a + (i + 1)*h;
		sum += (b - a) / 6.0 * (f(up) + f(low) + 4 * f((up + low) / 2));
	}
	return sum / n;
}

//método para encontrar o erro da regra do ponto médio
double Function::MidpointError(int n)
{
	double h = (b - a) / n;
	return (h*h*h / 24)*derivativeNthOrder(h, 2);
}

//método para encontrar o erro da regra do trapézio
double Function::TrapezoidalError(int n)
{
	double h = (b - a) / n;
	return -(h*h*h / 12) * derivativeNthOrder(h, 2);
}

//método para encontrar o erro da regra de Simpson
double Function::SimpsonError(int n)
{
	double h = (b - a) / n;
	return -(h*h*h*h*h / 90) * derivativeNthOrder(h, 4);
}

//Quadratura adaptativa para encontrar o número de intervalos para melhor aproximar o valor da integral
// pelo método do ponto médio
int Function::adaptiveMidpoint(double E)
{
	int n = 1;
	double error1 = MidpointError(n), error2 = 0;
	while (fabs(error1 - error2) > E) {
		n = n * 2;
		error2 = error1;
		error1 = MidpointError(n);
	}
	return n;
}

//Quadratura adaptativa para encontrar o número de intervalos para melhor aproximar o valor da integral
// pelo método dos trapézios
int Function::adaptiveTrapezoidal(double E)
{
	int n = 1;
	double error1 = TrapezoidalError(n), error2 = 0;
	while (fabs(error1 - error2) > E) {
		n = n * 2;
		error2 = error1;
		error1 = TrapezoidalError(n);
	}
	return n;
}

//Quadratura adaptativa para encontrar o número de intervalos para melhor aproximar o valor da integral
// pelo método de Simpson
int Function::adaptiveSimpson(double E)
{
	int n = 1;
	double error1 = SimpsonError(n), error2 = 0;
	while (fabs(error1 - error2) > E) {
		n = n * 2;
		error2 = error1;
		error1 = SimpsonError(n);
	}
	return n;
}



//destrutor padrão
Function::~Function()
{
}



