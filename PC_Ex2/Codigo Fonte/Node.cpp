#include "Node.h"



//construtor padr�o que recebe um char v,
//um Node* n, e um Node* p
Node::Node(char v, Node * n, Node * p)
{
	value = v;
	next = n;
	prev = p;
}

//recebe um char v e o atribui para o value de Node
void Node::setValue(char v)
{
	value = v;
}

//recebe um Node* N e o atribui para o Node* next
void Node::setNext(Node * N)
{
	next = N;
}

//recebe um Node* N e o atribui para o Node* prev
void Node::setPrev(Node * N)
{
	prev = N;
}

// retorna o valor do n�
char Node::getValue()
{
	return value;
}

//retorna o proximo n�
Node * Node::getNext()
{
	return next;
}

//retorna o n� anterior
Node * Node::getPrev()
{
	return prev;
}

//destrutor padr�o
Node::~Node()
{
}
