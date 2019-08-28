#include "solverHillClimb.h"




//construtor que recebe um node de puzzle e inicializa o n� inicial
solverHillClimb::solverHillClimb(Node<Puzzle> P) : puzzleSolver(P)
{
}

//construtor que recebe um Puzzle e inicializa o n� inicial
solverHillClimb::solverHillClimb(Puzzle P) : puzzleSolver(P)
{
}

//m�todo que resolve o puzzle utilizando a abordagem Subida na encosta (Hill Climbing)
bool solverHillClimb::Solve()
{
	//se o puzzle n�o tiver solu��o, retorna falso
	if (!start.getData().getSolvable())
		return false;

	//enfileira o n� inicial
	Node<Puzzle> *u = &start;
	seen.insertBegin(start.getData());

	//enquanto a fila n�o estiver vazia, desenfileira o n� da fila e verifica se ele � solu��o
	////se a solu��o n�o foi encontrada, movimenta as pe�as do puzzle armazenado pelo n� visitado
	while (u != nullptr) {
		if (u->getData().isSolved()) { //se o n� atual � a solu��o, armazena o resultado e retorna true
			result = u;
			return true;
		}

		u = movePieces(u);
	}

	//se a fila estiver fazia, o puzzle n�o tem solu��o
	return false;
}



//m�todo para movimentar as pe�as e enfileirar o primeiro movimento que possuir um custo menor que o n� sendo visitado
//Recebe um ponteiro para o n� que armazena o puzzle que ser� movimentado
Node<Puzzle>* solverHillClimb::movePieces(Node<Puzzle>* P)
{
	//se for poss�vel movimentar a pe�a abaixo do espa�o vazio, esse estado ainda n�o foi encontrado e possuir um custo total
	//menor que o n� atual, o estado � enfileirado e mais nenhum outro movimento � verificado
	Puzzle D = P->getData();
	if (D.moveDown() && seen.search(D) == nullptr && D.getHeuristic() < P->getData().getHeuristic()) {
		D.setDist(0);
		seen.insertEnd(D);
		Node<Puzzle> *newNode = new Node<Puzzle>(D, nullptr, nullptr, P);
		return newNode;
	}

	//se for poss�vel movimentar a pe�a acima do espa�o vazio, esse estado ainda n�o foi encontrado e possuir um custo total
	//menor que o n� atual, o estado � enfileirado e mais nenhum outro movimento � verificado
	Puzzle U = P->getData();
	if (U.moveUp() && seen.search(U) == nullptr && U.getHeuristic() < P->getData().getHeuristic()) {
		U.setDist(0);
		seen.insertEnd(U);
		Node<Puzzle> *newNode = new Node<Puzzle>(U, nullptr, nullptr, P);
		return newNode;
	}

	//se for poss�vel movimentar a pe�a a esquerda do espa�o vazio, esse estado ainda n�o foi encontrado e possuir um custo total
	//menor que o n� atual, o estado � enfileirado e mais nenhum outro movimento � verificado
	Puzzle L = P->getData();
	if (L.moveLeft() && seen.search(L) == nullptr && L.getHeuristic() < P->getData().getHeuristic()) {
		L.setDist(0);
		seen.insertEnd(L);
		Node<Puzzle> *newNode = new Node<Puzzle>(L, nullptr, nullptr, P);
		return newNode;
	}

	//se for poss�vel movimentar a pe�a a direita do espa�o vazio, esse estado ainda n�o foi encontrado e possuir um custo total
	//menor que o n� atual, o estado � enfileirado e mais nenhum outro movimento � verificado
	Puzzle R = P->getData();
	if (R.moveRight() && seen.search(R) == nullptr && R.getHeuristic() < P->getData().getHeuristic()) {
		R.setDist(0);
		seen.insertEnd(R);
		Node<Puzzle> *newNode = new Node<Puzzle>(R, nullptr, nullptr, P);
		return newNode;
	}

	return nullptr;
}

//destrutor padr�o
solverHillClimb::~solverHillClimb()
{
}
