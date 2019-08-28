#pragma once
#include "doublyLinkedList.h"

//definição da classe queueDoubleLinked que herda de doublyLinkedList,
//sendo uma fila dinâmica implementada a partir de uma lista ligada dupla.
class queueDoubleLinked : doublyLinkedList
{
	public:
		queueDoubleLinked(); //construtor padrão
		void Enqueue(char element); //método para enfileirar um caracter na fila
		char Dequeue(); //método para desenfileira o primeiro elemento da fila
		Node* Front(); //método que retorna o nó do primeiro elemento da fila
		~queueDoubleLinked(); //destrutor padrão
};
