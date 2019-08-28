#include "solverBFS.h"


//construtor que recebe um node de puzzle e inicializa o n� inicial
solverBFS::solverBFS(Node<Puzzle> P) : puzzleSolver(P)
{
}

//construtor que recebe um Puzzle e inicializa o n� inicial
solverBFS::solverBFS(Puzzle P) : puzzleSolver(P)
{

}


//m�todo que resolve o puzzle utilizando a abordagem BFS (Breadth-First Search)
bool solverBFS::Solve()
{
	//se o puzzle n�o tiver solu��o, retorna falso
	if (!start.getData().getSolvable())
		return false;

	//enfileira o n� inicial
	Q.Enqueue(&start);
	seen.insertBegin(start.getData());

	//enquanto a fila n�o estiver vazia, desenfileira o n� da fila e verifica se ele � solu��o
	////se a solu��o n�o foi encontrada, movimenta as pe�as do puzzle armazenado pelo n� visitado
	while (!Q.Empty()) { 
		Node<Puzzle> *u = Q.Dequeue();
		if (u->getData().isSolved()) { //se o n� atual � a solu��o, armazena o resultado e retorna true
			result = u;
			return true;
		}
		
		movePieces(u);
	}

	//se a fila estiver fazia, o puzzle n�o tem solu��o
	return false;
}


//m�todo para movimentar as pe�as e enfileirar os movimentos poss�veis na fila de n�s que ser�o visitados
//Recebe um ponteiro para o n� que armazena o puzzle que ser� movimentado
void solverBFS::movePieces(Node<Puzzle> *P)
{
	//se for poss�vel movimentar a pe�a abaixo do espa�o vazio e esse estado ainda n�o foi encontrado, ele � enfileirado
	Puzzle D = P->getData();
	if (D.moveDown() && seen.search(D) == nullptr) {
		seen.insertEnd(D);
		Node<Puzzle> *newNode = new Node<Puzzle>(D, nullptr, nullptr, P);
		Q.Enqueue(newNode);
	}

	//se for poss�vel movimentar a pe�a acima do espa�o vazio e esse estado ainda n�o foi encontrado, ele � enfileirado
	Puzzle U = P->getData();
	if (U.moveUp() && seen.search(U) == nullptr) {
		seen.insertEnd(U);
		Node<Puzzle> *newNode = new Node<Puzzle>(U, nullptr, nullptr, P);
		Q.Enqueue(newNode);
	}

	//se for poss�vel movimentar a pe�a a esquerda do espa�o vazio e esse estado ainda n�o tenha foi encontrado, ele � enfileirado
	Puzzle L = P->getData();
	if (L.moveLeft() && seen.search(L) == nullptr) {
		seen.insertEnd(L);
		Node<Puzzle> *newNode = new Node<Puzzle>(L, nullptr, nullptr, P);
		Q.Enqueue(newNode);
	}

	//se for poss�vel movimentar a pe�a a direita do espa�o vazio e esse estado ainda n�o tenha foi encontrado, ele � enfileirado
	Puzzle R = P->getData();
	if (R.moveRight() && seen.search(R) == nullptr) {
		seen.insertEnd(R);
		Node<Puzzle> *newNode = new Node<Puzzle>(R, nullptr, nullptr, P);
		Q.Enqueue(newNode);
	}
}


//destrutor padr�o
solverBFS::~solverBFS()
{
}
