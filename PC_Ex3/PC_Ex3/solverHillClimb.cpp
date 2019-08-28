#include "solverHillClimb.h"




//construtor que recebe um node de puzzle e inicializa o nó inicial
solverHillClimb::solverHillClimb(Node<Puzzle> P) : puzzleSolver(P)
{
}

//construtor que recebe um Puzzle e inicializa o nó inicial
solverHillClimb::solverHillClimb(Puzzle P) : puzzleSolver(P)
{
}

//método que resolve o puzzle utilizando a abordagem Subida na encosta (Hill Climbing)
bool solverHillClimb::Solve()
{
	//se o puzzle não tiver solução, retorna falso
	if (!start.getData().getSolvable())
		return false;

	//enfileira o nó inicial
	Node<Puzzle> *u = &start;
	seen.insertBegin(start.getData());

	//enquanto a fila não estiver vazia, desenfileira o nó da fila e verifica se ele é solução
	////se a solução não foi encontrada, movimenta as peças do puzzle armazenado pelo nó visitado
	while (u != nullptr) {
		if (u->getData().isSolved()) { //se o nó atual é a solução, armazena o resultado e retorna true
			result = u;
			return true;
		}

		u = movePieces(u);
	}

	//se a fila estiver fazia, o puzzle não tem solução
	return false;
}



//método para movimentar as peças e enfileirar o primeiro movimento que possuir um custo menor que o nó sendo visitado
//Recebe um ponteiro para o nó que armazena o puzzle que será movimentado
Node<Puzzle>* solverHillClimb::movePieces(Node<Puzzle>* P)
{
	//se for possível movimentar a peça abaixo do espaço vazio, esse estado ainda não foi encontrado e possuir um custo total
	//menor que o nó atual, o estado é enfileirado e mais nenhum outro movimento é verificado
	Puzzle D = P->getData();
	if (D.moveDown() && seen.search(D) == nullptr && D.getHeuristic() < P->getData().getHeuristic()) {
		D.setDist(0);
		seen.insertEnd(D);
		Node<Puzzle> *newNode = new Node<Puzzle>(D, nullptr, nullptr, P);
		return newNode;
	}

	//se for possível movimentar a peça acima do espaço vazio, esse estado ainda não foi encontrado e possuir um custo total
	//menor que o nó atual, o estado é enfileirado e mais nenhum outro movimento é verificado
	Puzzle U = P->getData();
	if (U.moveUp() && seen.search(U) == nullptr && U.getHeuristic() < P->getData().getHeuristic()) {
		U.setDist(0);
		seen.insertEnd(U);
		Node<Puzzle> *newNode = new Node<Puzzle>(U, nullptr, nullptr, P);
		return newNode;
	}

	//se for possível movimentar a peça a esquerda do espaço vazio, esse estado ainda não foi encontrado e possuir um custo total
	//menor que o nó atual, o estado é enfileirado e mais nenhum outro movimento é verificado
	Puzzle L = P->getData();
	if (L.moveLeft() && seen.search(L) == nullptr && L.getHeuristic() < P->getData().getHeuristic()) {
		L.setDist(0);
		seen.insertEnd(L);
		Node<Puzzle> *newNode = new Node<Puzzle>(L, nullptr, nullptr, P);
		return newNode;
	}

	//se for possível movimentar a peça a direita do espaço vazio, esse estado ainda não foi encontrado e possuir um custo total
	//menor que o nó atual, o estado é enfileirado e mais nenhum outro movimento é verificado
	Puzzle R = P->getData();
	if (R.moveRight() && seen.search(R) == nullptr && R.getHeuristic() < P->getData().getHeuristic()) {
		R.setDist(0);
		seen.insertEnd(R);
		Node<Puzzle> *newNode = new Node<Puzzle>(R, nullptr, nullptr, P);
		return newNode;
	}

	return nullptr;
}

//destrutor padrão
solverHillClimb::~solverHillClimb()
{
}
