#ifndef NODE_H
#define NODE_H

//defini��o da classe Node

template <typename T>
class Node
{
private:
	T data; //conteudo atribu�do ao n�
	Node<T>* nextLeft; //ponteiro para o pr�ximo n� da esquerda
	Node<T>* nextRight; //ponteiro para o pr�ximo n� da direita
	Node<T>* prev; //ponteiro para o n� anterior
public:
	
	Node<T>(); //construtor padr�o
	Node<T>(T P, Node<T>* l = nullptr, Node<T>* r = nullptr, Node<T>* p = nullptr); //sobrecarga do construtor

	void setData(T P); //m�todo para definir os dados do n�
	void setNextLeft(Node<T>* N); //m�todo para definir o ponteiro para o pr�ximo n�
	void setNextRight(Node<T>* N); //m�todo para definir o ponteiro para o pr�ximo n�
	void setPrev(Node<T>* N); //m�todo para definir o ponteiro para o n� anterior

	T getData(); //m�todo que retorna os dados armazenados no n�
	Node<T>* getNextLeft(); //m�todo que retorna o ponteiro do pr�ximo n�
	Node<T>* getNextRight(); //m�todo que retorna o ponteiro do pr�ximo n�
	Node<T>* getPrev(); //m�todo que retorna o ponteiro do n� anterior


	~Node();//destrutor padr�o
};


//defini��o dos m�todos da classe Node

//construtor padr�o
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


//Recebe um dado do tipo T e atribui ao n�
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

//retona os dados do n�
template <typename T>
T Node<T>::getData()
{
	return data;
}

//retorna o proximo n� a esquerda

template <typename T>
Node<T>* Node<T>::getNextLeft()
{
	return nextLeft;
}

//retorna o proximo n� a direita
template <typename T>
Node<T>* Node<T>::getNextRight()
{
	return nextRight;
}

//retorna o n� anterior

template <typename T>
Node<T> * Node<T>::getPrev()
{
	return prev;
}

//destrutor padr�o
template <typename T>
Node<T>::~Node()
{
}


#endif