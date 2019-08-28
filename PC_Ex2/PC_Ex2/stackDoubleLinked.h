#pragma once
#include "doublyLinkedList.h"

//defini��o da classe stackDoubleLinked que herda de doublyLinkedList,
//representando uma pilha din�mica implementada a partir de uma lista ligada dupla.
class stackDoubleLinked : public doublyLinkedList
{
	public:
		stackDoubleLinked(); //consrtutor padr�o

		void Push(char element); //m�todo que empilha um elemento na pilha
		char Pop(); //m�todo para desempilhar o elemento no topo da pilha
		Node* Top(); //m�todo que retorna o n� do elemento no topo da pilha

		~stackDoubleLinked(); //destrutor padr�o
};

