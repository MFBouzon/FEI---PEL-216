#ifndef QUEUE_H
#define QUEUE_H

#include "doublyList.h"

//definição da classe Queue que herda de doublyList,
//sendo uma fila dinâmica implementada a partir de uma lista ligada dupla.

template <typename T>
class Queue : public doublyList<T>
{
public:
	Queue(); //construtor padrão
	void Enqueue(T element); //método para enfileirar um caracter na fila
	T Dequeue(); //método para desenfileira o primeiro elemento da fila
	Node<T>* Front(); //método que retorna o nó do primeiro elemento da fila
	~Queue(); //destrutor padrão
};



//construtor padrão
template <typename T>
Queue<T>::Queue()
{
}


//recebe um element do tipo T que é enfileirado na fila
template <typename T>
void Queue<T>::Enqueue(T element)
{
	doublyList<T>::insertEnd(element);
}

//desenfileira e retorna o elemento no começo da fila
template <typename T>
T Queue<T>::Dequeue()
{
	return doublyList<T>::removeBegin();
}

//retorna o Node* que aponta para o começo da fila
template <typename T>
Node<T> * Queue<T>::Front()
{
	return doublyList<T>::getFirst();
}

//destrutor padrão
template <typename T>
Queue<T>::~Queue()
{
}

#endif