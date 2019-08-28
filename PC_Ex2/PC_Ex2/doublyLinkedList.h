#pragma once
#include "linkedList.h"


//defini��o da classe doublyLinkedList que herda da classe linkedList
class doublyLinkedList : public linkedList
{
private:
	Node *last; //ponteiro para o �ltimo n� da lista
public:
	doublyLinkedList(); //construtor padr�o

	void insertBegin(char element); //m�todo para inserir um elemento no come�o da lista
	void insertEnd(char element); //m�todo para inserir um elemento no final da lista
	char removeBegin(); //m�todo para remover o primeiro elemento da lista
	char removeEnd(); //m�todo para remover o �ltimo elemento da lista

	void setLast(Node *N);
	Node* getLast();

	~doublyLinkedList(); //destrutor padr�o
};

