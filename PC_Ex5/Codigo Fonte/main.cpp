/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 14/08/2019
Modificado em: 22/08/2019

Exercício 5 da disciplina PEL 216 - Programação Científica
Projeto: Integração numérica pela regra do ponto médio, dos trapézios e de Simpson

*/




#include <iostream>
#include <iomanip>
#include "Function_A.h"
#include "Function_B.h"
#include "Function_C.h"
using namespace std;

int main() {
	Function_A fA(0, 1.0);
	Function_B fB(0, 1.0);
	Function_C fC(0, 1.0);


	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	cout.precision(10);

	//Numero de intervalos
	int N = 2;

	cout << "Integracao definida de 0 a 1 sem quadratura adaptativa, utilizando quatro intervalos:\n";
	//Integral definida da função A
	cout<<"Integral da fA(x) pelo metodo do ponto medio = " << fA.Midpoint(N) << endl;
	cout << "Integral da fA(x) pelo metodo do trapezio = " << fA.Trapezoidal(N) << endl;
	cout << "Integral da fA(x) pelo metodo de Simpson = " << fA.Simpson(N) << endl;

	//Erro obtido em cada método para a função A
	cout <<"Erro obtido na integral de fA(x) com o metodo do ponto medio = "<< fA.MidpointError(N) << endl;
	cout << "Erro obtido na integral de fA(x) com o metodo do trapezio = " << fA.TrapezoidalError(N) << endl;
	cout << "Erro obtido na integral de fA(x) com o metodo de Simpson = " << fA.SimpsonError(N) << endl;

	cout << endl;

	//Integral definida da função B
	cout << "Integral da fB(x) pelo metodo do ponto medio = " << fB.Midpoint(N) << endl;
	cout << "Integral da fB(x) pelo metodo do trapézio = " << fB.Trapezoidal(N) << endl;
	cout << "Integral da fB(x) pelo metodo de Simpson = " << fB.Simpson(N) << endl;

	//Erro obtido em cada método para a função B
	cout << "Erro obtido na integral de fB(x) com o metodo do ponto medio = " << fB.MidpointError(N) << endl;
	cout << "Erro obtido na integral de fB(x) com o metodo do trapezio = " << fB.TrapezoidalError(N) << endl;
	cout << "Erro obtido na integral de fB(x) com o metodo de Simpson = " << fB.SimpsonError(N) << endl;
	cout << endl;

	//Integral definida da função C
	cout << "Integral da fC(x) pelo metodo do ponto medio = " << fC.Midpoint(N) << endl;
	cout << "Integral da fC(x) pelo metodo do trapézio = " << fC.Trapezoidal(N) << endl;
	cout << "Integral da fC(x) pelo metodo de Simpson = " << fC.Simpson(N) << endl;

	//Erro obtido em cada método para a função C
	cout << "Erro obtido na integral de fC(x) com o metodo do ponto medio = " << fC.MidpointError(N) << endl;
	cout << "Erro obtido na integral de fC(x) com o metodo do trapezio = " << fC.TrapezoidalError(N) << endl;
	cout << "Erro obtido na integral de fC(x) com o metodo de Simpson = " << fC.SimpsonError(N) << endl;
	cout << endl<<endl;


	//Erro tolerado
	double E = 0.000001;

	cout << "Integracao definida de 0 a 1 com quadratura adaptativa, utilizando a tolerancia de erro = "<<fixed<<setprecision(6)<< E<<":\n\n";
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	cout.precision(10);

	//Integral de fA(x) com quadratura adaptativa
	int adaptiveMid_A = fA.adaptiveMidpoint(E);
	cout << "Integral de fA(X) pelo metodo do ponto medio com quadratura adaptativa = " << fA.Midpoint(adaptiveMid_A) << "\nNumero de intervalos = " << adaptiveMid_A;
	cout << "\nErro obtido = " << fA.MidpointError(adaptiveMid_A) << endl<<endl;

	int adaptiveTrap_A = fA.adaptiveTrapezoidal(E);
	cout << "Integral de fA(X) pelo metodo do trapezio com quadratura adaptativa = " << fA.Trapezoidal(adaptiveTrap_A) << "\nNumero de intervalos = " << adaptiveTrap_A;
	cout << "\nErro obtido = " << fA.TrapezoidalError(adaptiveTrap_A) << endl<<endl;

	int adaptiveSimp_A = fA.adaptiveSimpson(E);
	cout << "Integral de fA(X) pelo metodo de Simpson com quadratura adaptativa = " << fA.Simpson(adaptiveSimp_A) << "\nNumero de intervalos = " << adaptiveSimp_A;
	cout << "\nErro obtido = " << fA.SimpsonError(adaptiveSimp_A) << endl<<endl;

	//Integral de fB(x) com quadratura adaptativa
	int adaptiveMid_B = fB.adaptiveMidpoint(E);
	cout << "Integral de fB(X) pelo metodo do ponto medio com quadratura adaptativa = " << fB.Midpoint(adaptiveMid_B) << "\nNumero de intervalos = " << adaptiveMid_B;
	cout << "\nErro obtido = " << fB.MidpointError(adaptiveMid_B) << endl << endl;

	int adaptiveTrap_B = fB.adaptiveTrapezoidal(E);
	cout << "Integral de fB(X) pelo metodo do trapezio com quadratura adaptativa = " << fB.Trapezoidal(adaptiveTrap_B) << "\nNumero de intervalos = " << adaptiveTrap_B;
	cout << "\nErro obtido = " << fB.TrapezoidalError(adaptiveTrap_B) << endl << endl;

	int adaptiveSimp_B = fB.adaptiveSimpson(E);
	cout << "Integral de fB(X) pelo metodo de Simpson com quadratura adaptativa = " << fB.Simpson(adaptiveSimp_B) << "\nNumero de intervalos = " << adaptiveSimp_B;
	cout << "\nErro obtido = " << fB.SimpsonError(adaptiveSimp_B) << endl << endl;

	//Integral de fC(x) com quadratura adaptativa
	int adaptiveMid_C = fC.adaptiveMidpoint(E);
	cout << "Integral de fC(X) pelo metodo do ponto medio com quadratura adaptativa = " << fC.Midpoint(adaptiveMid_C) << "\nNumero de intervalos = " << adaptiveMid_C;
	cout << "\nErro obtido = " << fC.MidpointError(adaptiveMid_C) << endl << endl;

	int adaptiveTrap_C = fC.adaptiveTrapezoidal(E);
	cout << "Integral de fC(X) pelo metodo do trapezio com quadratura adaptativa = " << fC.Trapezoidal(adaptiveTrap_C) << "\nNumero de intervalos = " << adaptiveTrap_C;
	cout << "\nErro obtido = " << fC.TrapezoidalError(adaptiveTrap_C) << endl << endl;

	int adaptiveSimp_C = fC.adaptiveSimpson(E);
	cout << "Integral de fC(X) pelo metodo de Simpson com quadratura adaptativa = " << fC.Simpson(adaptiveSimp_C) << "\nNumero de intervalos = " << adaptiveSimp_C;
	cout << "\nErro obtido = " << fC.SimpsonError(adaptiveSimp_C) << endl << endl;


	system("PAUSE");
}