#pragma once
#include "Node.h"
#include <iostream>

//defini��o da classe linkedList

class linkedList
{
	private:
		Node* first; //ponteiro para o primeiro n� da lista
		int size; // quantidade de elementos na lista
	public:
		linkedList(); //construtor padr�o

		void insertBegin(char element); //m�todo para inserir um elemento no come�o da lista
		void insertEnd(char element); //m�todo para inserir um elemento no final da lista
		char removeBegin(); //m�todo para remover o primeiro elemento da lista
		char removeEnd(); //m�todo para remover o �ltimo elemento da lista
		void print(); //m�todo para imprimir todos os elementos da lista
		Node* search(char c); //m�todo para buscar por um elemento com value = 'c'
		bool isEmpty(); //m�todo para verificar se a pilha est� vazia

		void setSize(int s); //define o tamanho da lista
		void setFirst(Node *N); //m�todo que define o primeiro n� da lista
		int getSize(); //m�todo que retorna o tamanho da lista
		Node* getFirst(); //m�todo que retorna o primeiro n� da lista
		
		~linkedList(); //destrutor padr�o
};

