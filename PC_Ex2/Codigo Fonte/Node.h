#pragma once
#include <iostream>
#include <exception>
using namespace std;

//defini��o da classe Node

class Node
{
	private:
		char value; //caracter atribu�do ao n�
		Node* next; //ponteiro para o pr�ximo n�
		Node* prev; //ponteiro para o n� anterior
	public:
		Node(char v = 0, Node* n = nullptr, Node* p = nullptr); //construtor padr�o

		void setValue(char v);  //m�todo para definir o valor do n�
		void setNext(Node* N); //m�todo para definir o ponteiro para o pr�ximo n�
		void setPrev(Node* N); //m�todo para definir o ponteiro para o n� anterior

		char getValue(); //m�todo que retorna o valor do n�
		Node* getNext(); //m�todo que retorna o ponteiro do pr�ximo n�
		Node* getPrev(); //m�todo que retorna o ponteiro do n� anterior

		~Node();//destrutor padr�o
};

