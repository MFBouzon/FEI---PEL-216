#ifndef NODE_H
#define NODE_H

//definição da classe Node

template <typename T>
class Node
{
private:
	T data; //conteudo atribuído ao nó
	Node<T>* nextLeft; //ponteiro para o próximo nó da esquerda
	Node<T>* nextRight; //ponteiro para o próximo nó da direita
	Node<T>* prev; //ponteiro para o nó anterior
public:
	
	Node<T>(); //construtor padrão
	Node<T>(T P, Node<T>* l = nullptr, Node<T>* r = nullptr, Node<T>* p = nullptr); //sobrecarga do construtor

	void setData(T P); //método para definir os dados do nó
	void setNextLeft(Node<T>* N); //método para definir o ponteiro para o próximo nó
	void setNextRight(Node<T>* N); //método para definir o ponteiro para o próximo nó
	void setPrev(Node<T>* N); //método para definir o ponteiro para o nó anterior

	T getData(); //método que retorna os dados armazenados no nó
	Node<T>* getNextLeft(); //método que retorna o ponteiro do próximo nó
	Node<T>* getNextRight(); //método que retorna o ponteiro do próximo nó
	Node<T>* getPrev(); //método que retorna o ponteiro do nó anterior


	~Node();//destrutor padrão
};


//definição dos métodos da classe Node

//construtor padrão
template<typename T>
Node<T>::Node()
{
}

//construtor que recebe um valor do tipo T,
//um Node* l, um Node* r e um Node* p
template <typename T>
Node<T>::Node(T P, Node<T> * l, Node<T>* r, Node<T> * p)
{
	data = P;
	nextLeft = l;
	nextRight = r;
	prev = p;
}


//Recebe um dado do tipo T e atribui ao nó
template <typename T>
void Node<T>::setData(T P)
{
	data = P;
}

//recebe um Node* N e o atribui para o Node* next

template <typename T>
void Node<T>::setNextLeft(Node<T> * N)
{
	nextLeft = N;
}

//recebe um Node* N e o atribui para o Node* next

template <typename T>
void Node<T>::setNextRight(Node<T> * N)
{
	nextRight = N;
}

//recebe um Node* N e o atribui para o Node* prev

template <typename T>
void Node<T>::setPrev(Node<T> * N)
{
	prev = N;
}

//retona os dados do nó
template <typename T>
T Node<T>::getData()
{
	return data;
}

//retorna o proximo nó a esquerda

template <typename T>
Node<T>* Node<T>::getNextLeft()
{
	return nextLeft;
}

//retorna o proximo nó a direita
template <typename T>
Node<T>* Node<T>::getNextRight()
{
	return nextRight;
}

//retorna o nó anterior

template <typename T>
Node<T> * Node<T>::getPrev()
{
	return prev;
}

//destrutor padrão
template <typename T>
Node<T>::~Node()
{
}


#endif