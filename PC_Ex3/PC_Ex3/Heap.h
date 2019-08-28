#ifndef HEAP_H
#define HEAP_H

#include "Node.h"
#include <cmath>
#include <cstdio>

//defini��o da classe Heap, representando um Min Heap Bin�rio

template <typename T>
class Heap
{
private:
	Node<Node<T> *> *root; //Ponteiro que aponta para o primeiro n� do heap
	Node<Node<T> *> *last; //Ponteiro que aponta para o �ltimo n� do heap

	int size; //n�mero de elementos inseridos no heap
public:
	Heap(); //construtor padr�o
	Heap(Node<T>*); //sobrecarga do construtor

	int getSize(); //m�todo para retornar o n�mero de elementos do heap
	void Push(Node<T>*); //m�todo para inserir um novo elemento no heap
	void Push(T); //sobrecarga do m�todo para inserir um novo elemento no heap
	Node<T>* Pop(); //m�todo para remover o elemento no topo do heap
	
	bool Empty(); //m�todo para verificar se o heap est� vazio
	void Heapify(Node<Node<T> *>*); //m�todo para construir o heap

	~Heap(); //destrutor padr�o
};

//construtor padr�o
template <typename T>
Heap<T>::Heap()
{
	root = nullptr;
	last = nullptr;
	size = 0;

}

//sobrecarga do construtor que recebe um ponteiro de n� do tipo T
template<typename T>
Heap<T>::Heap(Node<T>* R)
{
	root = R;
	size++;
}


//retorna o n�mero de elementos no heap
template<typename T>
int Heap<T>::getSize()
{
	return size;
}

//m�todo que insere um novo elemento no heap, recebendo um ponteiro para o n� que guarda os dados do elemento
template<typename T>
void Heap<T>::Push(Node<T> *element)
{
	if (size == 0) {
		root = new Node<Node<T> *>(element);
		last = new Node<Node<T> *>(element);
		size++;
	}
	else {
		size++;
		Node<Node<T>* > *ptr;
		if (int(log2(size)) == log2(size)) { //se o n�mero de elementos inseridos for uma pot�ncia de 2, o novo elemento � inserido no n� mais a esquerda
			ptr = root;
			while (ptr->getNextLeft() != nullptr) {
				ptr = ptr->getNextLeft();
			}
			Node<Node<T> *> *inserted = ptr->getNextLeft();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, ptr);
			ptr->setNextLeft(inserted);
			last = inserted;
		}
		else if (size % 2 == 1) { //se o n�mero de elementos inseridos for impar, insere o elemento a direita do pai do ultimo n�
			Node<Node<T> *> *inserted = last->getPrev()->getNextRight();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, last->getPrev());
			last->getPrev()->setNextRight(inserted);
			last = inserted;
		}
		else { // se o n�mero de elementos for par e n�o � uma pot�ncia de 2, o elemento � inserido no filho da esquerda do filho da direita do pai do pai do �ltimo n�
			Node<Node<T> *> *inserted = last->getPrev()->getPrev()->getNextRight()->getNextLeft();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, last->getPrev()->getPrev()->getNextRight());
			last->getPrev()->getPrev()->getNextRight()->setNextLeft(inserted);
			last = inserted;
		}
		ptr = last;

		//enquanto o n� inserido for menor que o n� anterior, � feita uma troca entre eles
		while (ptr->getData() != root->getData()) { 
			Node<Node<T>* > *parent = ptr->getPrev();
			Node<T> *ptrData = ptr->getData();
			Node<T> *parentData = parent->getData();
			if (ptrData->getData() < parentData->getData()) {
				ptr->setData(parentData);
				parent->setData(ptrData);
				ptr = parent;
			}
			else
				return;
		}
	}

}

//sobrecarga do m�todo para inserir um novo elemento, recebendo apenas o dado do tipo T
// e criando um novo n� dentro do m�todo
template<typename T>
void Heap<T>::Push(T data)
{
	Node<T> *element = new Node<T>(data); //cria um novo n� que recebe data do tipo T

	//verifica o n� inserido � a raiz
	if (size == 0) {
		root = new Node<Node<T> *>(element);
		last = new Node<Node<T> *>(element);
		size++;
	}
	else {
		size++;
		Node<Node<T>* > *ptr;
		if (int(log2(size)) == log2(size)) { //se o n�mero de elementos inseridos for uma pot�ncia de 2, o novo elemento � inserido no n� mais a esquerda
			ptr = root;
			while (ptr->getNextLeft() != nullptr) {
				ptr = ptr->getNextLeft();
			}
			Node<Node<T> *> *inserted = ptr->getNextLeft();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, ptr);
			ptr->setNextLeft(inserted);
			last = inserted;
		}
		else if (size % 2 == 1) { //se o n�mero de elementos inseridos for impar, insere o elemento a direita do pai do ultimo n�
			Node<Node<T> *> *inserted = last->getPrev()->getNextRight();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, last->getPrev());
			last->getPrev()->setNextRight(inserted);
			last = inserted;
		}
		else { // se o n�mero de elementos for par e n�o � uma pot�ncia de 2, o elemento � inserido no filho da esquerda do filho da direita do pai do pai do �ltimo n�
			Node<Node<T> *> *inserted = last->getPrev()->getPrev()->getNextRight()->getNextLeft();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, last->getPrev()->getPrev()->getNextRight());
			last->getPrev()->getPrev()->getNextRight()->setNextLeft(inserted);
			last = inserted;
		}
		ptr = last;


		//enquanto o n� inserido for menor que o n� anterior, � feita uma troca entre eles
		while (ptr->getData() != root->getData()) {
			Node<Node<T>* > *parent = ptr->getPrev();
			Node<T> *ptrData = ptr->getData();
			Node<T> *parentData = parent->getData();
			if (ptrData->getData() < parentData->getData()) {
				ptr->setData(parentData);
				parent->setData(ptrData);
				ptr = parent;
			}
			else
				return;
		}
	}

}


//m�todo que retorna um ponteiro para o elemento que foi removido do heap
template<typename T>
Node<T>* Heap<T>::Pop()
{
	//armazena o valor da raiz e troca o valor com o �ltimo n� do heap
	Node<T> *removed = root->getData();
	root->setData(last->getData());
	Node<Node<T>*> *temp = last;

	if (int(log2(size)) == log2(size)) { //se o n�mero de elementos inserido � uma pot�ncia de 2, o �ltimo n� passa a ser o n� mais a direita
		Node<Node<T>*> *ptr = root;
		
		while (ptr->getNextRight() != nullptr) {
			ptr = ptr->getNextRight();
		}

		//verifica se o n� removido � a raiz
		if (last->getPrev() != nullptr) { 
			last->getPrev()->setNextLeft(nullptr);
			last = ptr;
		}

		else {
			root = nullptr;
			last = nullptr;
			size--;
			delete temp;
			return removed;
		}

	}
	else if (size % 2 == 1) { //se o n�mero de elementos � impar, o ultimo n� passa a ser o filho da esquerda do pai do n� que foi removido
		last->getPrev()->setNextRight(nullptr);
		last = last->getPrev()->getNextLeft();
	}
	else { //se o n�mero de elementos � par e n�o � uma pot�ncia de 2, o �ltimo n� passa a ser o filho da direita do filho da esquerda do pai do pai do n� que foi removido
		last->getPrev()->setNextLeft(nullptr);
		last = last->getPrev()->getPrev()->getNextLeft()->getNextRight();
	}
	size--;
	delete temp;
	
	Heapify(root); //ap�s a remo��o, o m�todo Heapify � chamado para atualizar o heap bin�rio

	return removed;
}


//m�todo que retorna se o heap est� vazio
template<typename T>
bool Heap<T>::Empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

//m�todo para arrumar a ordem dos elementos do heap, respeitando a ordem do minHeap.
// Recebe um ponteiro para um n� do heap
template<typename T>
void Heap<T>::Heapify(Node<Node<T> *>* N)
{

	Node<Node<T>*> *smallest;
	Node<Node<T>*> *left = N->getNextLeft();
	Node<Node<T>*> *right = N->getNextRight();
	
	//verifica qual filho possui o menor valor
	if (left == nullptr && right == nullptr)
		return;
	else if (left == nullptr && right != nullptr)
		smallest = right;
	else if (left != nullptr && right == nullptr)
		smallest = left;
	else if (left->getData()->getData() < right->getData()->getData())
		smallest = left;
	else
		smallest = right;

	Node<T> *smallestData = smallest->getData();
	Node<T> *nodeData = N->getData();

	//se o menor filho � menor que o pai, os valores s�o trocados
	if (smallestData->getData() < nodeData->getData())
	{
		smallest->setData(nodeData);
		N->setData(smallestData);

		Heapify(smallest); //o m�todo � chamado recursivamento, recebendo o n� trocado como entrada
	}

}

//destrutor padr�o
//Limpa o heap quando ele � destruido
template <typename T>
Heap<T>::~Heap()
{
	while (size > 0)
		Pop();
}

#endif