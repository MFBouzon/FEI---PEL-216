#include "Queue.h"


// construtor que inicializa a fila
Queue::Queue()
{
	head = 0;
	tail = 0;
	length = 0;
}

// recebe um caracter x e devolve um valor booleano 
// que mostra se foi possível enfileirar x
bool Queue::Enqueue(char x)
{
	if(length == QSize)
		return false;

	Q[tail] = x;
	tail = (tail + 1) % QSize;
	length++;
	return true;
}

// desenfileira e retorna o primeiro item da fila
char Queue::Dequeue()
{
	if(length == 0)
		return 0;
	char x = Q[head];
	head = (head + 1) % QSize;
	length--;
	return x;
}

// retorna o primeiro item da fila
char Queue::Front()
{
	if (length == 0)
		return 0;
	return Q[head];
}

//destrutor padrão
Queue::~Queue()
{

}
