#pragma once
#include "linkedList.h"

//definição da classe stackLinked que herda de linkedList,
//representando uma pilha dinâmica implementada a partir de uma lista ligada simples.
class stackLinked : public linkedList
{
	public:
		stackLinked(); //construtor padrão 

		void Push(char element); //método que empilha um elemento na pilha
		char Pop(); //método para desempilhar o elemento no topo da pilha
 		Node* Top(); //método que retorna o nó do elemento no topo da pilha
		
		~stackLinked(); //destrutor padrão
};

