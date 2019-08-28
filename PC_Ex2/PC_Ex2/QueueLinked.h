#pragma once
#include "linkedList.h"

//definição da classe queueLinked que herda de linkedList,
//sendo uma fila dinâmica implementada a partir de uma lista ligada simples.
class queueLinked : public linkedList
{
	public:
		queueLinked(); //construtor padrão

		void Enqueue(char element); //método para enfileirar um caracter na fila
		char Dequeue(); //método para desenfileira o primeiro elemento da fila
		Node* Front(); //método que retorna o nó do primeiro elemento da fila

		~queueLinked(); //destrutor padrão
};

