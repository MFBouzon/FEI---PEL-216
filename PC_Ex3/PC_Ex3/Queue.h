#ifndef QUEUE_H
#define QUEUE_H

#include "doublyList.h"

//defini��o da classe Queue que herda de doublyList,
//sendo uma fila din�mica implementada a partir de uma lista ligada dupla.

template <typename T>
class Queue : public doublyList<T>
{
public:
	Queue(); //construtor padr�o
	void Enqueue(T element); //m�todo para enfileirar um caracter na fila
	T Dequeue(); //m�todo para desenfileira o primeiro elemento da fila
	Node<T>* Front(); //m�todo que retorna o n� do primeiro elemento da fila
	~Queue(); //destrutor padr�o
};



//construtor padr�o
template <typename T>
Queue<T>::Queue()
{
}


//recebe um element do tipo T que � enfileirado na fila
template <typename T>
void Queue<T>::Enqueue(T element)
{
	doublyList<T>::insertEnd(element);
}

//desenfileira e retorna o elemento no come�o da fila
template <typename T>
T Queue<T>::Dequeue()
{
	return doublyList<T>::removeBegin();
}

//retorna o Node* que aponta para o come�o da fila
template <typename T>
Node<T> * Queue<T>::Front()
{
	return doublyList<T>::getFirst();
}

//destrutor padr�o
template <typename T>
Queue<T>::~Queue()
{
}

#endif