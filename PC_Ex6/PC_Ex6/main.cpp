/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 23/08/2019
Modificado em: 01/09/2019

Exerc�cio 6 da disciplina PEL 216 - Programa��o Cient�fica
Projeto: C�lculo do Volume de um Toroide Parcial utilizando o M�todo de Monte Carlo

*/

#include "F1.h"
#include "Toroid.h"
#include <cstdio>
#include <cstdlib>
#include <chrono>

int main(int argc, char* argv[]) {

	//Teste do c�lculo de pi utilizando Monte Carlo
	F1 A;
	printf("%lf\n", A.MonteCarlo(1000));
	system("PAUSE");

	std::chrono::time_point<std::chrono::system_clock> start, end; //vari�veis para calcular o tempo levado para o m�todo de monte carlo


	//C�lculo do volume de um toroide parcial
	Toroid T;
	for (int N = 10; N <= 1000000; N = N * 10) { //varia��o do n�mero de itera��es de 10 a 10^6
		start = std::chrono::system_clock::now();
		
		printf("N = %d - Volume = %.4lf\n", N, T.MonteCarlo(N));
		
		end = std::chrono::system_clock::now();
		double seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

		printf("Tempo = %.4lf segundos.\n", seconds);
	}

	system("PAUSE");
}