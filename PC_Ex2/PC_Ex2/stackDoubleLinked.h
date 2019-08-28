#pragma once
#include "doublyLinkedList.h"

//definição da classe stackDoubleLinked que herda de doublyLinkedList,
//representando uma pilha dinâmica implementada a partir de uma lista ligada dupla.
class stackDoubleLinked : public doublyLinkedList
{
	public:
		stackDoubleLinked(); //consrtutor padrão

		void Push(char element); //método que empilha um elemento na pilha
		char Pop(); //método para desempilhar o elemento no topo da pilha
		Node* Top(); //método que retorna o nó do elemento no topo da pilha

		~stackDoubleLinked(); //destrutor padrão
};

