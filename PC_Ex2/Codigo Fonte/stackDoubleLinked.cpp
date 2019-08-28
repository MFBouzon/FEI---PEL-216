#include "stackDoubleLinked.h"



//construtor padr�o
stackDoubleLinked::stackDoubleLinked()
{
}

//recebe um char element que � empilhado na pilha
void stackDoubleLinked::Push(char element)
{
	doublyLinkedList::insertBegin(element);
}

//desempilha e retorna o elemento no topo da pilha
char stackDoubleLinked::Pop()
{
	return doublyLinkedList::removeBegin();
}

//retorna o Node* que aponta para o topo da pilha
Node * stackDoubleLinked::Top()
{
	return linkedList::getFirst();
}

//destrutor padr�o
stackDoubleLinked::~stackDoubleLinked()
{
}
