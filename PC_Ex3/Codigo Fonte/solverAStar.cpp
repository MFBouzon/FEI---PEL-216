#include "solverAStar.h"



//construtor que recebe um node de puzzle e inicializa o nó inicial
solverAStar::solverAStar(Node<Puzzle> P) : puzzleSolver(P)
{
}

//construtor que recebe um Puzzle e inicializa o nó inicial
solverAStar::solverAStar(Puzzle P) : puzzleSolver(P)
{
}

//método que resolve o puzzle utilizando a abordagem A-estrela (A*)
bool solverAStar::Solve()
{
	//se o puzzle não tiver solução, retorna falso
	if (!start.getData().getSolvable())
		return false;

	//insere o nó inicial
	H.Push(&start);
	seen.insertBegin(start.getData());

	//enquanto o Heap não estiver vazio, remove o nó do heap e verifica se ele é solução
	////se a solução não foi encontrada, movimenta as peças do puzzle armazenado pelo nó visitado
	while (!H.Empty()) {
		Node<Puzzle> *u = H.Pop();
		if (u->getData().isSolved()) { //se o nó atual é a solução, armazena o resultado e retorna true
			result = u;
			return true;
		}

		movePieces(u);
	}

	//se a fila estiver fazia, o puzzle não tem solução
	return false;
}

//método para movimentar as peças e inserir os movimentos possíveis no Heap de nós que serão visitados
//Recebe um ponteiro para o nó que armazena o puzzle que será movimentado
void solverAStar::movePieces(Node<Puzzle>* P)
{
	//se for possível movimentar a peça abaixo do espaço vazio e esse estado ainda não foi encontrado, ele é inserido
	Puzzle D = P->getData();
	if (D.moveDown() && seen.search(D) == nullptr) {
		seen.insertEnd(D);
		Node<Puzzle> *newNode = new Node<Puzzle>(D, nullptr, nullptr, P);
		H.Push(newNode);
	}

	//se for possível movimentar a peça acima do espaço vazio e esse estado ainda não foi encontrado, ele é inserido
	Puzzle U = P->getData();
	if (U.moveUp() && seen.search(U) == nullptr) {
		seen.insertEnd(U);
		Node<Puzzle> *newNode = new Node<Puzzle>(U, nullptr, nullptr, P);
		H.Push(newNode);
	}

	//se for possível movimentar a peça a esquerda do espaço vazio e esse estado ainda não foi encontrado, ele é inserido
	Puzzle L = P->getData();
	if (L.moveLeft() && seen.search(L) == nullptr) {
		seen.insertEnd(L);
		Node<Puzzle> *newNode = new Node<Puzzle>(L, nullptr, nullptr, P);
		H.Push(newNode);
	}

	//se for possível movimentar a peça a direita do espaço vazio e esse estado ainda não foi encontrado, ele é inserido
	Puzzle R = P->getData();
	if (R.moveRight() && seen.search(R) == nullptr) {
		seen.insertEnd(R);
		Node<Puzzle> *newNode = new Node<Puzzle>(R, nullptr, nullptr, P);
		H.Push(newNode);
	}
}

//destrutor padrão
solverAStar::~solverAStar()
{
}
