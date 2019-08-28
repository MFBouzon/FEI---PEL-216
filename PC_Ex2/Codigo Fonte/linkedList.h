#pragma once
#include "Node.h"
#include <iostream>

//definição da classe linkedList

class linkedList
{
	private:
		Node* first; //ponteiro para o primeiro nó da lista
		int size; // quantidade de elementos na lista
	public:
		linkedList(); //construtor padrão

		void insertBegin(char element); //método para inserir um elemento no começo da lista
		void insertEnd(char element); //método para inserir um elemento no final da lista
		char removeBegin(); //método para remover o primeiro elemento da lista
		char removeEnd(); //método para remover o último elemento da lista
		void print(); //método para imprimir todos os elementos da lista
		Node* search(char c); //método para buscar por um elemento com value = 'c'
		bool isEmpty(); //método para verificar se a pilha está vazia

		void setSize(int s); //define o tamanho da lista
		void setFirst(Node *N); //método que define o primeiro nó da lista
		int getSize(); //método que retorna o tamanho da lista
		Node* getFirst(); //método que retorna o primeiro nó da lista
		
		~linkedList(); //destrutor padrão
};

