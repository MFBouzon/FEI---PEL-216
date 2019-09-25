/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 16/09/2019
Modificado em: 22/09/2019

Exerc�cio 8 da disciplina PEL 216 - Programa��o Cient�fica
Projeto: Uma Abordagem Paralela para o C�lculo da Integral Utilizando as Regras de Newton-Cotes

*/




#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <chrono>
#include <fstream>
#include "Function.h"
#include <chrono>

using namespace std;

int main(int argc, char* argv[]) {
	double   d;
	Function F(0, 1);

	
	double seconds;
	double start, end;
	//teste para o c�lculo da integral de forma paralela variando n
	
		for (int i = 1; i <= 32; i = i * 2) { // n�mero de threads � variado de 1 a 32

			for (int n = 10; n <= 10000000; n = n * 10) { //valor de n � variado de 10 a 10^7
			
			//calcula a �rea pela regra do ponto m�dio de forma paralela
			start = omp_get_wtime(); 
			d = F.Simpson(n, i);
			end = omp_get_wtime();
			seconds = end - start;
			printf("For %d steps, area = %.15f, %lf milliseconds\n", n, d, seconds*1000);

			//calcula a �rea pela regra dos trap�zios de forma paralela
			start = omp_get_wtime();
			d = F.Trapezoidal(n, i);
			end = omp_get_wtime();
			seconds = end - start;

			printf("For %d steps, area = %.15f, %lf milliseconds\n", n, d, seconds*1000);

			//calcula a �rea pela regra de Simpson de forma paralela
			start = omp_get_wtime();
			d = F.Simpson(n, i);
			end = omp_get_wtime();
			seconds = end - start;

			printf("For %d steps, area = %.15f, %lf milliseconds\n\n", n, d, seconds*1000);
			
		}
	}
	system("PAUSE");
}
