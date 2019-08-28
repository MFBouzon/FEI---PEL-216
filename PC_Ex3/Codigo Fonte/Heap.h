#ifndef HEAP_H
#define HEAP_H

#include "Node.h"
#include <cmath>
#include <cstdio>

//definição da classe Heap, representando um Min Heap Binário

template <typename T>
class Heap
{
private:
	Node<Node<T> *> *root; //Ponteiro que aponta para o primeiro nó do heap
	Node<Node<T> *> *last; //Ponteiro que aponta para o último nó do heap

	int size; //número de elementos inseridos no heap
public:
	Heap(); //construtor padrão
	Heap(Node<T>*); //sobrecarga do construtor

	int getSize(); //método para retornar o número de elementos do heap
	void Push(Node<T>*); //método para inserir um novo elemento no heap
	void Push(T); //sobrecarga do método para inserir um novo elemento no heap
	Node<T>* Pop(); //método para remover o elemento no topo do heap
	
	bool Empty(); //método para verificar se o heap está vazio
	void Heapify(Node<Node<T> *>*); //método para construir o heap

	~Heap(); //destrutor padrão
};

//construtor padrão
template <typename T>
Heap<T>::Heap()
{
	root = nullptr;
	last = nullptr;
	size = 0;

}

//sobrecarga do construtor que recebe um ponteiro de nó do tipo T
template<typename T>
Heap<T>::Heap(Node<T>* R)
{
	root = R;
	size++;
}


//retorna o número de elementos no heap
template<typename T>
int Heap<T>::getSize()
{
	return size;
}

//método que insere um novo elemento no heap, recebendo um ponteiro para o nó que guarda os dados do elemento
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
		if (int(log2(size)) == log2(size)) { //se o número de elementos inseridos for uma potência de 2, o novo elemento é inserido no nó mais a esquerda
			ptr = root;
			while (ptr->getNextLeft() != nullptr) {
				ptr = ptr->getNextLeft();
			}
			Node<Node<T> *> *inserted = ptr->getNextLeft();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, ptr);
			ptr->setNextLeft(inserted);
			last = inserted;
		}
		else if (size % 2 == 1) { //se o número de elementos inseridos for impar, insere o elemento a direita do pai do ultimo nó
			Node<Node<T> *> *inserted = last->getPrev()->getNextRight();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, last->getPrev());
			last->getPrev()->setNextRight(inserted);
			last = inserted;
		}
		else { // se o número de elementos for par e não é uma potência de 2, o elemento é inserido no filho da esquerda do filho da direita do pai do pai do último nó
			Node<Node<T> *> *inserted = last->getPrev()->getPrev()->getNextRight()->getNextLeft();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, last->getPrev()->getPrev()->getNextRight());
			last->getPrev()->getPrev()->getNextRight()->setNextLeft(inserted);
			last = inserted;
		}
		ptr = last;

		//enquanto o nó inserido for menor que o nó anterior, é feita uma troca entre eles
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

//sobrecarga do método para inserir um novo elemento, recebendo apenas o dado do tipo T
// e criando um novo nó dentro do método
template<typename T>
void Heap<T>::Push(T data)
{
	Node<T> *element = new Node<T>(data); //cria um novo nó que recebe data do tipo T

	//verifica o nó inserido é a raiz
	if (size == 0) {
		root = new Node<Node<T> *>(element);
		last = new Node<Node<T> *>(element);
		size++;
	}
	else {
		size++;
		Node<Node<T>* > *ptr;
		if (int(log2(size)) == log2(size)) { //se o número de elementos inseridos for uma potência de 2, o novo elemento é inserido no nó mais a esquerda
			ptr = root;
			while (ptr->getNextLeft() != nullptr) {
				ptr = ptr->getNextLeft();
			}
			Node<Node<T> *> *inserted = ptr->getNextLeft();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, ptr);
			ptr->setNextLeft(inserted);
			last = inserted;
		}
		else if (size % 2 == 1) { //se o número de elementos inseridos for impar, insere o elemento a direita do pai do ultimo nó
			Node<Node<T> *> *inserted = last->getPrev()->getNextRight();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, last->getPrev());
			last->getPrev()->setNextRight(inserted);
			last = inserted;
		}
		else { // se o número de elementos for par e não é uma potência de 2, o elemento é inserido no filho da esquerda do filho da direita do pai do pai do último nó
			Node<Node<T> *> *inserted = last->getPrev()->getPrev()->getNextRight()->getNextLeft();
			inserted = new Node<Node<T> *>(element, nullptr, nullptr, last->getPrev()->getPrev()->getNextRight());
			last->getPrev()->getPrev()->getNextRight()->setNextLeft(inserted);
			last = inserted;
		}
		ptr = last;


		//enquanto o nó inserido for menor que o nó anterior, é feita uma troca entre eles
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


//método que retorna um ponteiro para o elemento que foi removido do heap
template<typename T>
Node<T>* Heap<T>::Pop()
{
	//armazena o valor da raiz e troca o valor com o último nó do heap
	Node<T> *removed = root->getData();
	root->setData(last->getData());
	Node<Node<T>*> *temp = last;

	if (int(log2(size)) == log2(size)) { //se o número de elementos inserido é uma potência de 2, o último nó passa a ser o nó mais a direita
		Node<Node<T>*> *ptr = root;
		
		while (ptr->getNextRight() != nullptr) {
			ptr = ptr->getNextRight();
		}

		//verifica se o nó removido é a raiz
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
	else if (size % 2 == 1) { //se o número de elementos é impar, o ultimo nó passa a ser o filho da esquerda do pai do nó que foi removido
		last->getPrev()->setNextRight(nullptr);
		last = last->getPrev()->getNextLeft();
	}
	else { //se o número de elementos é par e não é uma potência de 2, o último nó passa a ser o filho da direita do filho da esquerda do pai do pai do nó que foi removido
		last->getPrev()->setNextLeft(nullptr);
		last = last->getPrev()->getPrev()->getNextLeft()->getNextRight();
	}
	size--;
	delete temp;
	
	Heapify(root); //após a remoção, o método Heapify é chamado para atualizar o heap binário

	return removed;
}


//método que retorna se o heap está vazio
template<typename T>
bool Heap<T>::Empty()
{
	if (size == 0)
		return true;
	else
		return false;
}

//método para arrumar a ordem dos elementos do heap, respeitando a ordem do minHeap.
// Recebe um ponteiro para um nó do heap
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

	//se o menor filho é menor que o pai, os valores são trocados
	if (smallestData->getData() < nodeData->getData())
	{
		smallest->setData(nodeData);
		N->setData(smallestData);

		Heapify(smallest); //o método é chamado recursivamento, recebendo o nó trocado como entrada
	}

}

//destrutor padrão
//Limpa o heap quando ele é destruido
template <typename T>
Heap<T>::~Heap()
{
	while (size > 0)
		Pop();
}

#endif