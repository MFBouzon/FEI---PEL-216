#include "queueLinked.h"


//construtor padr�o
queueLinked::queueLinked()
{
}


//recebe um char element que � enfileirado na fila
void queueLinked::Enqueue(char element)
{
	linkedList::insertEnd(element);
}

//desenfileira e retorna o primeiro elemento da fila
char queueLinked::Dequeue()
{
	return linkedList::removeBegin();
}

//retorna o Node* que aponta para o primeiro elemento da fila
Node * queueLinked::Front()
{
	return linkedList::getFirst();
}

//destrutor padr�o
queueLinked::~queueLinked()
{
}
