/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 29/08/2019
Modificado em: 10/09/2019

Exercício 7 da disciplina PEL 216 - Programação Científica
Projeto: Implementação do Método de Monte Carlo Distribuído utilizando MPI

*/

#include "mpi.h"
#include <stdlib.h>
#include <stdio.h>
#include "Toroid.h"

int main(int argc, char* argv[]) {
	int totalPoints = 0;
	int N = 1000000; //numero de iterações

	//Inicialização do MPI
	MPI_Init(&argc, &argv);

	int rank, procs;
	MPI_Comm_size(MPI_COMM_WORLD, &procs); // retorna o número de processos
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); // retorna o rank do processo que executar essa linha
	
	Toroid T;
	double start = MPI_Wtime();

	int localPoints = T.MonteCarlo(N/procs); // Calcula o número de pontos dentro do espaço de integração

	MPI_Reduce(&localPoints, &totalPoints, 1, MPI_LONG, MPI_SUM, 0, MPI_COMM_WORLD); // retorna a soma dos pontos dentro do espaço de integração para cada processo

	double finish = MPI_Wtime();
	double localTime = finish - start;

	if (rank == 0) { // se o id do processo for 0, imprime o volume e o tempo levado

		double Volume = 42.0 * totalPoints / N;
		printf("Volume = %lf\n", Volume);
		printf("Time elapsed = %lf seconds\n", localTime);
	}

	MPI_Finalize(); // finaliza o MPI
	
}