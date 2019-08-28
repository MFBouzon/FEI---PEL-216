#include "doublyLinkedList.h"


//construtor que inicializa o Node* last
doublyLinkedList::doublyLinkedList() : linkedList()
{
	last = nullptr;
}


//recebe um char element que é inserido no começo da lista
void doublyLinkedList::insertBegin(char element)
{
	try {
		Node *prevF = linkedList::getFirst();
		Node *insertedNode = new Node(element, prevF);

		if (prevF != nullptr)
			prevF->setPrev(insertedNode);
		else
			last = insertedNode;

		linkedList::setFirst(insertedNode);
		linkedList::setSize(linkedList::getSize() + 1);
	}
	catch (const std::bad_alloc &e) {
		std::cout << "Erro ao inserir no comeco da lista dupla. Exception:" << e.what() << std::endl;
	}
}

//recebe um char element que é inserido no final da lista
void doublyLinkedList::insertEnd(char element)
{
	try {
		Node *insertedNode = new Node(element, nullptr, last);

		if (last != nullptr)
			last->setNext(insertedNode);
		else
			linkedList::setFirst(insertedNode);

		last = insertedNode;
		linkedList::setSize(linkedList::getSize() + 1);

	}
	catch (const std::bad_alloc &e) {
		std::cout << "Erro ao inserir no final da lista dupla. Exception:" << e.what() << std::endl;
	}
}

//remove e retorna o primeiro elemento da lista
char doublyLinkedList::removeBegin()
{
	try {
		Node *deletedNode = linkedList::getFirst();
		Node *newFirst = deletedNode->getNext();
		linkedList::setFirst(newFirst);
		newFirst->setPrev(nullptr);

		char ret = deletedNode->getValue();
		delete deletedNode;
		deletedNode = nullptr;

		linkedList::setSize(linkedList::getSize() - 1);
		return ret;
	}
	catch (const std::exception &e) {
		std::cout << "Erro ao remover o comeco da lista dupla. Exception:" << e.what() << std::endl;
	}
}

//remove e retorna o último elemento da lista
char doublyLinkedList::removeEnd()
{
	try {
		Node *deletedNode = last;
		last = deletedNode->getPrev();

		char ret = deletedNode->getValue();
		delete deletedNode;
		deletedNode = nullptr;


		linkedList::setSize(linkedList::getSize() - 1);
		return ret;
	}
	catch (const std::exception &e) {
		std::cout << "Erro ao remover o final da lista dupla. Exception:" << e.what() << std::endl;
	}
}

//define o último nó da lista
void doublyLinkedList::setLast(Node * N)
{
	last = N;
}


//retorna o último nó da lista
Node * doublyLinkedList::getLast()
{
	return last;
}

//destrutor para desalocar os nós existentes caso a fila não esteja vazia
doublyLinkedList::~doublyLinkedList()
{
	if (linkedList::getSize() == 0)
		linkedList::setFirst(nullptr);
}
