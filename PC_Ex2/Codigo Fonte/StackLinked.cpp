#include "StackLinked.h"


//construtor padr�o
stackLinked::stackLinked()
{
}

//recebe um char element que � empilhado na pilha
void stackLinked::Push(char element)
{
	linkedList::insertBegin(element);
}

//desempilha e retorna o elemento no topo da pilha
char stackLinked::Pop()
{
	return linkedList::removeBegin();
}


//retorna o Node* que aponta para o topo da pilha
Node * stackLinked::Top()
{
	return linkedList::getFirst();
}


//destrutor padr�o
stackLinked::~stackLinked()
{
}
