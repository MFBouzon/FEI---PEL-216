#include "Stack.h"


//construtor que inicializa a pilha.
Stack::Stack()
{
	top = -1;
}


//recebe um caracter x e retorna um booleano que
//representa se foi possível empilhar o novo elemento.
bool Stack::Push(char x)
{
	if (top == SSize-1)
		return false;
	top++;
	S[top] = x;

	return true;
}

//desempilha e retorna o primeiro elemento da pilha.
char Stack::Pop()
{
	if (Empty())
		return 0;
	top--;
	return S[top+1];
}

//retorna um valor true se a pilha estiver vazia
// e false se a pilha estiver cheia.
bool Stack::Empty()
{
	if (top == -1)
		return true;

	return false;
}

//retorna o elemento no topo da fila
char Stack::Top()
{
	if (Empty())
		return 0;
	return S[top];
}


//destrutor padrão
Stack::~Stack()
{
}
