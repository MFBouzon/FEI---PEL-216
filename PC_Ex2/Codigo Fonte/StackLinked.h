#pragma once
#include "linkedList.h"

//defini��o da classe stackLinked que herda de linkedList,
//representando uma pilha din�mica implementada a partir de uma lista ligada simples.
class stackLinked : public linkedList
{
	public:
		stackLinked(); //construtor padr�o 

		void Push(char element); //m�todo que empilha um elemento na pilha
		char Pop(); //m�todo para desempilhar o elemento no topo da pilha
 		Node* Top(); //m�todo que retorna o n� do elemento no topo da pilha
		
		~stackLinked(); //destrutor padr�o
};

