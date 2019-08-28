#pragma once
#define QSize 5

//Esta classe define uma fila de caracteres
class Queue
{
private:
	int head; //posição do começo da fila
	int tail; //posição do final da fila
	int length; // número de elementos na fila
	char Q[QSize]; // vetor que guarda os elementos da fila
public:
	Queue(); // construtor padrão
	bool Enqueue(char x); // método para enfileirar um valor x na fila
	char Dequeue(); //método para desenfileirar o primeiro item da fila
	char Front(); //método que retorna o primeiro item da fila
	~Queue(); //destrutor padrão
};

	