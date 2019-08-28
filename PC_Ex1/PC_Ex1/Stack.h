#pragma once
#define SSize 10

//Classe que define uma pilha de caracteres
class Stack
{
private:
	int top; //�ndice do elemento que est� no topo da pilha
	char S[SSize]; //vetor que guarda os elementos da pilha
public:
	Stack(); //construtor padr�o
	bool Push(char x); //m�todo para empilhar um valor x na pilha
	char Pop(); //m�todo para desempilhar o elemento no topo da filha
	bool Empty(); //m�todo para verificar se a pilha est� vazia
	char Top(); //m�todo que retorna o elemento no topo da pilha
	~Stack(); //destrutor padr�o
};

