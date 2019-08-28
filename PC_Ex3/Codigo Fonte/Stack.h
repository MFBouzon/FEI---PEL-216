#ifndef STACK_H
#define STACK_H

#include "doublyList.h"

//defini��o da classe Stack que herda de doublyList,
//representando uma pilha din�mica implementada a partir de uma lista ligada dupla.
template <typename T>
class Stack : public doublyList<T>
{
public:
	Stack(); //construtor padr�o

	void Push(T element); //m�todo que empilha um elemento na pilha
	T Pop(); //m�todo para desempilhar o elemento no topo da pilha
	Node<T>* Top(); //m�todo que retorna o n� do elemento no topo da pilha

	~Stack(); //destrutor padr�o
};


//construtor padr�o
template <typename T>
Stack<T>::Stack()
{
}

//recebe um element do tipo T que � empilhado na pilha
template <typename T>
void Stack<T>::Push(T element)
{
	doublyList<T>::insertBegin(element);
}



//desempilha e retorna o elemento no topo da pilha
template <typename T>
T Stack<T>::Pop()
{
	return doublyList<T>::removeBegin();
}

//retorna o Node* que aponta para o topo da pilha
template <typename T>
Node<T> * Stack<T>::Top()
{
	return doublyList<T>::getFirst();
}

//destrutor padr�o
template <typename T>
Stack<T>::~Stack()
{
}

#endif