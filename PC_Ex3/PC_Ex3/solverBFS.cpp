#include "solverBFS.h"


//construtor que recebe um node de puzzle e inicializa o nó inicial
solverBFS::solverBFS(Node<Puzzle> P) : puzzleSolver(P)
{
}

//construtor que recebe um Puzzle e inicializa o nó inicial
solverBFS::solverBFS(Puzzle P) : puzzleSolver(P)
{

}


//método que resolve o puzzle utilizando a abordagem BFS (Breadth-First Search)
bool solverBFS::Solve()
{
	//se o puzzle não tiver solução, retorna falso
	if (!start.getData().getSolvable())
		return false;

	//enfileira o nó inicial
	Q.Enqueue(&start);
	seen.insertBegin(start.getData());

	//enquanto a fila não estiver vazia, desenfileira o nó da fila e verifica se ele é solução
	////se a solução não foi encontrada, movimenta as peças do puzzle armazenado pelo nó visitado
	while (!Q.Empty()) { 
		Node<Puzzle> *u = Q.Dequeue();
		if (u->getData().isSolved()) { //se o nó atual é a solução, armazena o resultado e retorna true
			result = u;
			return true;
		}
		
		movePieces(u);
	}

	//se a fila estiver fazia, o puzzle não tem solução
	return false;
}


//método para movimentar as peças e enfileirar os movimentos possíveis na fila de nós que serão visitados
//Recebe um ponteiro para o nó que armazena o puzzle que será movimentado
void solverBFS::movePieces(Node<Puzzle> *P)
{
	//se for possível movimentar a peça abaixo do espaço vazio e esse estado ainda não foi encontrado, ele é enfileirado
	Puzzle D = P->getData();
	if (D.moveDown() && seen.search(D) == nullptr) {
		seen.insertEnd(D);
		Node<Puzzle> *newNode = new Node<Puzzle>(D, nullptr, nullptr, P);
		Q.Enqueue(newNode);
	}

	//se for possível movimentar a peça acima do espaço vazio e esse estado ainda não foi encontrado, ele é enfileirado
	Puzzle U = P->getData();
	if (U.moveUp() && seen.search(U) == nullptr) {
		seen.insertEnd(U);
		Node<Puzzle> *newNode = new Node<Puzzle>(U, nullptr, nullptr, P);
		Q.Enqueue(newNode);
	}

	//se for possível movimentar a peça a esquerda do espaço vazio e esse estado ainda não tenha foi encontrado, ele é enfileirado
	Puzzle L = P->getData();
	if (L.moveLeft() && seen.search(L) == nullptr) {
		seen.insertEnd(L);
		Node<Puzzle> *newNode = new Node<Puzzle>(L, nullptr, nullptr, P);
		Q.Enqueue(newNode);
	}

	//se for possível movimentar a peça a direita do espaço vazio e esse estado ainda não tenha foi encontrado, ele é enfileirado
	Puzzle R = P->getData();
	if (R.moveRight() && seen.search(R) == nullptr) {
		seen.insertEnd(R);
		Node<Puzzle> *newNode = new Node<Puzzle>(R, nullptr, nullptr, P);
		Q.Enqueue(newNode);
	}
}


//destrutor padrão
solverBFS::~solverBFS()
{
}
