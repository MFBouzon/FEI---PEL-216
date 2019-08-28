#ifndef STACK_H
#define STACK_H

#include "doublyList.h"

//definição da classe Stack que herda de doublyList,
//representando uma pilha dinâmica implementada a partir de uma lista ligada dupla.
template <typename T>
class Stack : public doublyList<T>
{
public:
	Stack(); //construtor padrão

	void Push(T element); //método que empilha um elemento na pilha
	T Pop(); //método para desempilhar o elemento no topo da pilha
	Node<T>* Top(); //método que retorna o nó do elemento no topo da pilha

	~Stack(); //destrutor padrão
};


//construtor padrão
template <typename T>
Stack<T>::Stack()
{
}

//recebe um element do tipo T que é empilhado na pilha
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

//destrutor padrão
template <typename T>
Stack<T>::~Stack()
{
}

#endif