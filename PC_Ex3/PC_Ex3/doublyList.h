#ifndef DBL_LIST_H
#define DBL_LIST_H


#include "Node.h"
#include <cstdio>


//definição da classe doublyList, que representa uma lista ligada dupla

template <typename T>
class doublyList
{
private:

	int size; // quantidade de elementos na lista
	Node<T>* first; //ponteiro para o primeiro nó da lista
	Node<T>* last; //ponteiro para o último nó da lista
public:
	doublyList(); //construtor padrão

	void insertBegin(T element); //método para inserir um elemento no começo da lista
	void insertEnd(T element); //método para inserir um elemento no final da lista
	T removeBegin(); //método para remover o primeiro elemento da lista
	T removeEnd(); //método para remover o último elemento da lista

	void print(); //método para imprimir todos os elementos da lista
	Node<T>* search(T p); //método para buscar por um elemento com value = 'c'
	bool Empty(); //método para verificar se a pilha está vazia

	void setSize(int s); //define o tamanho da lista
	void setFirst(Node<T> *N); //método que define o primeiro nó da lista
	void setLast(Node<T> *N); //método que define o último nó da lista
	int getSize(); //método que retorna o tamanho da lista
	Node<T>* getFirst(); //método que retorna o primeiro nó da lista
	Node<T>* getLast(); //método que retorna o último nó da lista

	
	~doublyList(); //destrutor padrão
};



//construtor que inicializa o Node* last

template <typename T>
doublyList<T>::doublyList()
{
	first = nullptr;
	size = 0;
	last = nullptr;
}


//recebe um element do tipo T que é inserido no começo da lista

template <typename T>
void doublyList<T>::insertBegin(T element)
{

	Node<T> *prevF = first;
	Node<T> *insertedNode = new Node<T>(element, prevF);

	if (prevF != nullptr)
		prevF->setPrev(insertedNode);
	else
		last = insertedNode;

	first = insertedNode;
	size++;

}

//recebe um element do tipo T que é inserido no final da lista

template <typename T>
void doublyList<T>::insertEnd(T element)
{

	Node<T> *insertedNode = new Node<T>(element, nullptr, last);

	if (last != nullptr)
		last->setNextLeft(insertedNode);
	else
		first = insertedNode;

	last = insertedNode;
	size++;


}

//remove e retorna o primeiro elemento da lista
template <typename T>
T doublyList<T>::removeBegin()
{

	Node<T> *deletedNode = first;
	Node<T> *newFirst = deletedNode->getNextLeft();
	first = newFirst;
	if (newFirst != nullptr)
		newFirst->setPrev(nullptr);
	else
		last = nullptr;
	T ret = deletedNode->getData();
	delete deletedNode;
	deletedNode = nullptr;

	size--;
	return ret;

}

//remove e retorna o último elemento da lista

template <typename T>
T doublyList<T>::removeEnd()
{

	Node<T> *deletedNode = last;
	last = deletedNode->getPrev();
	if (last != nullptr)
		last->setNext(nullptr);
	else
		first = nullptr;
	T ret = deletedNode->getData();
	delete deletedNode;
	deletedNode = nullptr;


	size--;
	return ret;

}

//método que imprime todos os elementos da lista
template <typename T>
void doublyList<T>::print()
{
	Node<T> *ptrFront = first;
	while (ptrFront != nullptr) {
		cout << ptrFront->getData() << endl;
		ptrFront = ptrFront->getNextLeft();
	}
}

//método que busca um nó que possui o valor P
// e retorna o nó caso ele esteja na lista ou nulo se ele não estiver
template <typename T>
Node<T> * doublyList<T>::search(T p)
{
	Node<T> *ptrFront = first;
	while (ptrFront != nullptr && ptrFront->getData() != p) {
		ptrFront = ptrFront->getNextLeft();
	}
	return ptrFront;
}


//define o primeiro nó da lista
template <typename T>
void doublyList<T>::setFirst(Node<T> * N)
{
	first = N;
}

//define o tamanho da lista
template <typename T>
void doublyList<T>::setSize(int s)
{
	size = s;
}

//retorna o tamanho da lista
template <typename T>
int doublyList<T>::getSize()
{
	return size;
}

//retorna um booleano que representa se a pilha está vazia ou não
template <typename T>
bool doublyList<T>::Empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

//retorna o primeiro nó da lista
template <typename T>
Node<T> * doublyList<T>::getFirst()
{
	return first;
}



//define o último nó da lista
template <typename T>
void doublyList<T>::setLast(Node <T>* N)
{
	last = N;
}


//retorna o último nó da lista
template <typename T>
Node<T> * doublyList<T>::getLast()
{
	return last;
}

//destrutor para desalocar os nós existentes caso a lista não esteja vazia
template <typename T>
doublyList<T>::~doublyList()
{
	Node<T> *ptrFront = first, *ptrBack = nullptr;
	while (ptrFront != nullptr) {
		ptrBack = ptrFront;
		ptrFront = ptrFront->getNextLeft();
		delete ptrBack;
	}
}

#endif