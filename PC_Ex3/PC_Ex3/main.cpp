/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 14/07/2019
Modificado em: 07/08/2019

Exercício 3 da disciplina PEL 216 - Programação Científica
Projeto: Resolução do problema 8-Puzzle Utilizando Algoritmos De Busca Cega e Busca Informada

*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "solverBFS.h"
#include "solverDFS.h"
#include "solverHillClimb.h"
#include "solverAStar.h"
#include <chrono>

using namespace std;

/*	
Caso de teste passado em sala

	4 1 6
	3 2 8
	7 0 5

*/
int main() {

	std::chrono::time_point<std::chrono::system_clock> start, end;

	int A[3][3] =
	{
		{ 4, 1, 6 },
		{ 3, 2, 8 },
		{ 7, 0, 5 }
	};

	Puzzle P1(A);

	//Medição do tempo para resolver o puzzle do método AStar
	start = std::chrono::system_clock::now();
	puzzleSolver *PS = new solverAStar(P1);
	PS->printResult();
	end = std::chrono::system_clock::now();
	double seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
	printf("Tempo para resolver o puzzle utilizando o metodo A*: %lf segundos\n", seconds);
	delete PS;
	system("PAUSE");
	

	//Medição do tempo para resolver o puzzle do método Hill Climbing
	start = std::chrono::system_clock::now();
	PS = new solverHillClimb(P1);
	PS->printResult();
	end = std::chrono::system_clock::now();
	seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
	printf("Tempo para resolver o puzzle utilizando o metodo Hill Climbing: %lf segundos\n", seconds);
	delete PS;
	system("PAUSE");

	//Medição do tempo para resolver o puzzle do método BFS
	start = std::chrono::system_clock::now();
	PS = new solverBFS(P1);
	PS->printResult();
	end = std::chrono::system_clock::now();
	seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
	printf("Tempo para resolver o puzzle utilizando o metodo BFS: %lf segundos\n", seconds);
	delete PS;
	system("PAUSE");

	//Medição do tempo para resolver o puzzle do método DFS
	start = std::chrono::system_clock::now();
	PS = new solverDFS(P1);
	PS->printResult();
	end = std::chrono::system_clock::now();
	seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
	printf("Tempo para resolver o puzzle utilizando o metodo DFS: %lf segundos\n", seconds);
	delete PS;
	system("PAUSE");

}