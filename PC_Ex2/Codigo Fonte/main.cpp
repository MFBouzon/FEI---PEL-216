/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 19/06/2019
Modificado em: 24/06/2019

Exercício 2 da disciplina PEL 216 - Programação Científica
Projeto: Implementação de Fila e Pilha utilizando lista ligada dinâmica e lista duplamente ligada dinâmica

*/

#include "StackLinked.h"
#include "QueueLinked.h"
#include "stackDoubleLinked.h"
#include "queueDoubleLinked.h"
#include <cstdio>
#include <cstdlib>
#include <chrono>

int main() {
	stackLinked S;
	stackDoubleLinked S2;
	queueLinked Q;
	queueDoubleLinked Q2;

	std::chrono::time_point<std::chrono::system_clock> start, end;
	
	for (int i = 10; i <= 100000; i = i * 10) {
		start = std::chrono::system_clock::now();
		for (int j = 0; j < i; j++) {
			S.Push((i % 26) + 65);
		}
		end = std::chrono::system_clock::now();
		double seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
		printf("Tempo para empilhar %d valores na pilha com lista simples: %lf segundos\n", i, seconds);
		start = std::chrono::system_clock::now();
		for (int j = 0; j < i; j++) {
			S2.Push((i % 26) + 65);
		}
		end = std::chrono::system_clock::now();
		seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
		printf("Tempo para empilhar %d valores na pilha com lista dupla: %lf segundos\n", i, seconds);
		start = std::chrono::system_clock::now();
		for (int j = 0; j < i; j++) {
			Q.Enqueue((i % 26) + 65);
		}
		end = std::chrono::system_clock::now();
		seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
		printf("Tempo para enfileirar %d valores na fila com lista simples: %lf segundos\n", i, seconds);
		start = std::chrono::system_clock::now();
		for (int j = 0; j < i; j++) {
			Q2.Enqueue((i % 26) + 65);
		}
		end = std::chrono::system_clock::now();
		seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
		printf("Tempo para enfileirar %d valores na fila com lista dupla: %lf segundos\n", i, seconds);
		start = std::chrono::system_clock::now();
		//getchar();
		printf("\n");
	}

	for (int i = 10; i <= 100000; i = i * 10) {
		start = std::chrono::system_clock::now();
		for (int j = 0; j < i; j++) {
			S.Pop();
		}
		end = std::chrono::system_clock::now();
		double seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
		printf("Tempo para desempilhar %d valores na pilha com lista simples: %lf segundos\n", i, seconds);
		start = std::chrono::system_clock::now();
		for (int j = 0; j < i; j++) {
			S2.Pop();
		}
		end = std::chrono::system_clock::now();
		seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
		printf("Tempo para desempilhar %d valores na pilha com lista dupla: %lf segundos\n", i, seconds);
		start = std::chrono::system_clock::now();
		for (int j = 0; j < i; j++) {
			Q.Dequeue();
		}
		end = std::chrono::system_clock::now();
		seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
		printf("Tempo para desenfileirar %d valores na fila com lista simples: %lf segundos\n", i, seconds);
		start = std::chrono::system_clock::now();
		for (int j = 0; j < i; j++) {
			Q2.Dequeue();
		}
		end = std::chrono::system_clock::now();
		seconds = chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0;
		printf("Tempo para desenfileirar %d valores na fila com lista dupla: %lf segundos\n", i, seconds);
		start = std::chrono::system_clock::now();
		//getchar();

		printf("\n");
	}
	
	getchar();

	return 0;
}