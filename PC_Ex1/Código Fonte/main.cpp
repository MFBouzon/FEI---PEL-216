/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 11/06/2019
Modificado em: 17/06/2019

Exercício 1 da disciplina PEL 216 - Programação Científica
Projeto: Implementação de Fila e Pilha utilizando programação orientada a objetos

*/


#include "Queue.h"
#include "Stack.h"
#include <cstdio>
#include <cstdlib>


// Recebe um objeto Queue F
// e um vetor V para ser enfileirado e desenfileirado de F.
void testeFila(Queue F, char V[]) {
	printf("Teste Fila...\n");

	for (int i = 0; i < 5; i++) {
		F.Enqueue(V[i]);
		printf("Valor %c enfileirado\n", V[i]);
	}

	if (F.Enqueue(15) == true)
		printf("Enfileirado.\n");
	else
		printf("Fila cheia.\n");

	while (F.Front() != 0)
		printf("Valor %c desenfileirado\n", F.Dequeue());

	if (F.Dequeue() == 0)
		printf("Fila vazia.\n");

}


//Recebe um objeto Stack P e um vetor V,
// empilhando e desempilhando todos os valores de V em P.
void testePilha(Stack P, char V[]) {

	printf("Teste Pilha...\n");

	for (int i = 0; i < 10; i++) {
		P.Push(V[i]);
		printf("Valor %c empilhado\n");
	}

	if (P.Push(15) == false)
		printf("Pilha cheia.\n");

	while (P.Top() != 0) {
		printf("Valor %c desempilhado\n", P.Pop());
	}

	if (P.Empty())
		printf("Pilha vazia.\n");

}


int main() {
	Queue F;
	char A[] = { 'a', 't', '5', '2', 'Y' };
	testeFila(F, A);
	getchar();
	system("cls");
	

	Stack S;
	char B[] = { 'A', 'D', 'x', '-', '.', 'g', '@', 'R', 'T', 'z' };
	testePilha(S, B);
	getchar();

	return 0;
}