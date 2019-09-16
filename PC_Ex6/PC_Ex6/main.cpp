/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 23/08/2019
Modificado em: 01/09/2019

Exercício 6 da disciplina PEL 216 - Programação Científica
Projeto: Cálculo do Volume de um Toroide Parcial utilizando o Método de Monte Carlo

*/

#include "F1.h"
#include "Toroid.h"
#include <cstdio>
#include <cstdlib>
#include <chrono>

int main(int argc, char* argv[]) {

	//Teste do cálculo de pi utilizando Monte Carlo
	F1 A;
	printf("%lf\n", A.MonteCarlo(1000));
	system("PAUSE");

	std::chrono::time_point<std::chrono::system_clock> start, end; //variáveis para calcular o tempo levado para o método de monte carlo


	//Cálculo do volume de um toroide parcial
	Toroid T;
	for (int N = 10; N <= 1000000; N = N * 10) { //variação do número de iterações de 10 a 10^6
		start = std::chrono::system_clock::now();
		
		printf("N = %d - Volume = %.4lf\n", N, T.MonteCarlo(N));
		
		end = std::chrono::system_clock::now();
		double seconds = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

		printf("Tempo = %.4lf segundos.\n", seconds);
	}

	system("PAUSE");
}