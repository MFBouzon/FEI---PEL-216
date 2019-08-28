#pragma once
#define SSize 10

//Classe que define uma pilha de caracteres
class Stack
{
private:
	int top; //índice do elemento que está no topo da pilha
	char S[SSize]; //vetor que guarda os elementos da pilha
public:
	Stack(); //construtor padrão
	bool Push(char x); //método para empilhar um valor x na pilha
	char Pop(); //método para desempilhar o elemento no topo da filha
	bool Empty(); //método para verificar se a pilha está vazia
	char Top(); //método que retorna o elemento no topo da pilha
	~Stack(); //destrutor padrão
};

