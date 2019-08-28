#pragma once
#include <iostream>
#include <exception>
using namespace std;

//definição da classe Node

class Node
{
	private:
		char value; //caracter atribuído ao nó
		Node* next; //ponteiro para o próximo nó
		Node* prev; //ponteiro para o nó anterior
	public:
		Node(char v = 0, Node* n = nullptr, Node* p = nullptr); //construtor padrão

		void setValue(char v);  //método para definir o valor do nó
		void setNext(Node* N); //método para definir o ponteiro para o próximo nó
		void setPrev(Node* N); //método para definir o ponteiro para o nó anterior

		char getValue(); //método que retorna o valor do nó
		Node* getNext(); //método que retorna o ponteiro do próximo nó
		Node* getPrev(); //método que retorna o ponteiro do nó anterior

		~Node();//destrutor padrão
};

