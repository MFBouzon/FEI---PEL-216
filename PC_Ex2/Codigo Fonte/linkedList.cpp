#include "linkedList.h"


//construtor padrão da classe linkedList
// para inicilizar o size e o Node* first da lista
linkedList::linkedList()
{
	first = nullptr;
	size = 0;
}

//recebe um char element que é inserido no começo da lista
void linkedList::insertBegin(char element)
{
	try {
		Node *insertedNode = new Node(element, first);
		first = insertedNode;
		size++;
	}
	catch (const std::bad_alloc &e) {
		std::cout << "Erro ao inserir no comeco da lista simples. Exception:" << e.what() << std::endl;
	}
}

//recebe um char element que é inserido no final da lista
void linkedList::insertEnd(char element)
{
	try {
		Node* insertedNode = new Node(element);
		Node *ptrFront = first, *ptrBack = nullptr;
		while (ptrFront != nullptr) {
			ptrBack = ptrFront;
			ptrFront = ptrFront->getNext();
		}
		if (ptrBack == nullptr)
			insertBegin(element);
		else {
			ptrBack->setNext(insertedNode);
			insertedNode->setNext(ptrFront);
			size++;
		}
	}
	catch (const std::bad_alloc &e) {
		std::cout << "Erro ao inserir no final da lista simples. Exception:" << e.what() << std::endl;
	}
}


//remove e retorna o primeiro elemento da lista
char linkedList::removeBegin()
{
	try {
		Node *deletedNode = first;
		first = first->getNext();

		char ret = deletedNode->getValue();

		delete deletedNode;
		deletedNode = nullptr;
		size--;

		return ret;
	}
	catch (const std::exception &e) {
		cout << "Erro ao remover o comeco da lista simples. Exception:" << e.what() << endl;
	}
}


//remove e retorna o último elemento da lista
char linkedList::removeEnd()
{
	try {
		Node *ptrFront = first, *ptrBack = nullptr;
		while (ptrFront->getNext() != nullptr) {
			ptrBack = ptrFront;	
			ptrFront = ptrFront->getNext();
		}

		if (ptrBack != nullptr) {
			ptrBack->setNext(nullptr);
			char ret = ptrFront->getValue();
			delete ptrFront;
			ptrFront = nullptr;
			size--;

			return ret;
		}
		else
			return removeBegin();
	}
	catch (const std::exception &e) {
		std::cout << "Erro ao remover o final da lista simples. Exception:" << e.what() << std::endl;
	}

}

void linkedList::print()
{
	printf("Elementos:");
	Node *ptrFront = first;
	while (ptrFront != nullptr) {
		printf(" %c", ptrFront->getValue());
		ptrFront = ptrFront->getNext();
	}
}

Node * linkedList::search(char c)
{
	Node *ptrFront = first;
	while (ptrFront != nullptr && ptrFront->getValue() != c) {
		ptrFront = ptrFront->getNext();
	}
	return ptrFront;
}


//define o primeiro nó da lista
void linkedList::setFirst(Node * N)
{
	first = N;
}

//define o tamanho da lista
void linkedList::setSize(int s)
{
	size = s;
}

//retorna o tamanho da lista
int linkedList::getSize()
{
	return size;
}

//retorna um booleano que representa se a pilha está vazia ou não
bool linkedList::isEmpty()
{
	if (linkedList::getSize() > 0)
		return true;
	else
		return false;
}

//retorna o primeiro nó da lista
Node * linkedList::getFirst()
{
	return first;
}

//destrutor para desalocar os nós que ainda estão na lista
// após o fim do programa
linkedList::~linkedList()
{
	Node *ptrFront = first, *ptrBack = nullptr;
	while (ptrFront != nullptr) {
		ptrBack = ptrFront;
		ptrFront = ptrFront->getNext();
		delete ptrBack;
	}
}
