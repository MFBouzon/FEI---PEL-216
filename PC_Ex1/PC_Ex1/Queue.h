#pragma once
#define QSize 5

//Esta classe define uma fila de caracteres
class Queue
{
private:
	int head; //posi��o do come�o da fila
	int tail; //posi��o do final da fila
	int length; // n�mero de elementos na fila
	char Q[QSize]; // vetor que guarda os elementos da fila
public:
	Queue(); // construtor padr�o
	bool Enqueue(char x); // m�todo para enfileirar um valor x na fila
	char Dequeue(); //m�todo para desenfileirar o primeiro item da fila
	char Front(); //m�todo que retorna o primeiro item da fila
	~Queue(); //destrutor padr�o
};

	