#include "queueLinked.h"


//construtor padrão
queueLinked::queueLinked()
{
}


//recebe um char element que é enfileirado na fila
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

//destrutor padrão
queueLinked::~queueLinked()
{
}
