#include "queueDoubleLinked.h"



queueDoubleLinked::queueDoubleLinked()
{
}

void queueDoubleLinked::Enqueue(char element)
{
	doublyLinkedList::insertEnd(element);
}

char queueDoubleLinked::Dequeue()
{
	return doublyLinkedList::removeBegin();
}

Node * queueDoubleLinked::Front()
{
	return linkedList::getFirst();
}


queueDoubleLinked::~queueDoubleLinked()
{
}
