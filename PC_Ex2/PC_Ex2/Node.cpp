#include "Node.h"



//construtor padrão que recebe um char v,
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

// retorna o valor do nó
char Node::getValue()
{
	return value;
}

//retorna o proximo nó
Node * Node::getNext()
{
	return next;
}

//retorna o nó anterior
Node * Node::getPrev()
{
	return prev;
}

//destrutor padrão
Node::~Node()
{
}
