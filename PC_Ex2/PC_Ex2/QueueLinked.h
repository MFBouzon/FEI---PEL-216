#pragma once
#include "linkedList.h"

//defini��o da classe queueLinked que herda de linkedList,
//sendo uma fila din�mica implementada a partir de uma lista ligada simples.
class queueLinked : public linkedList
{
	public:
		queueLinked(); //construtor padr�o

		void Enqueue(char element); //m�todo para enfileirar um caracter na fila
		char Dequeue(); //m�todo para desenfileira o primeiro elemento da fila
		Node* Front(); //m�todo que retorna o n� do primeiro elemento da fila

		~queueLinked(); //destrutor padr�o
};

