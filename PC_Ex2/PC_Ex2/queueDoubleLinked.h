#pragma once
#include "doublyLinkedList.h"

//defini��o da classe queueDoubleLinked que herda de doublyLinkedList,
//sendo uma fila din�mica implementada a partir de uma lista ligada dupla.
class queueDoubleLinked : doublyLinkedList
{
	public:
		queueDoubleLinked(); //construtor padr�o
		void Enqueue(char element); //m�todo para enfileirar um caracter na fila
		char Dequeue(); //m�todo para desenfileira o primeiro elemento da fila
		Node* Front(); //m�todo que retorna o n� do primeiro elemento da fila
		~queueDoubleLinked(); //destrutor padr�o
};
