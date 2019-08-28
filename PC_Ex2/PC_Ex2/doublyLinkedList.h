#pragma once
#include "linkedList.h"


//definição da classe doublyLinkedList que herda da classe linkedList
class doublyLinkedList : public linkedList
{
private:
	Node *last; //ponteiro para o último nó da lista
public:
	doublyLinkedList(); //construtor padrão

	void insertBegin(char element); //método para inserir um elemento no começo da lista
	void insertEnd(char element); //método para inserir um elemento no final da lista
	char removeBegin(); //método para remover o primeiro elemento da lista
	char removeEnd(); //método para remover o último elemento da lista

	void setLast(Node *N);
	Node* getLast();

	~doublyLinkedList(); //destrutor padrão
};

