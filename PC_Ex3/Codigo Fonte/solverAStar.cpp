#include "solverAStar.h"



//construtor que recebe um node de puzzle e inicializa o n� inicial
solverAStar::solverAStar(Node<Puzzle> P) : puzzleSolver(P)
{
}

//construtor que recebe um Puzzle e inicializa o n� inicial
solverAStar::solverAStar(Puzzle P) : puzzleSolver(P)
{
}

//m�todo que resolve o puzzle utilizando a abordagem A-estrela (A*)
bool solverAStar::Solve()
{
	//se o puzzle n�o tiver solu��o, retorna falso
	if (!start.getData().getSolvable())
		return false;

	//insere o n� inicial
	H.Push(&start);
	seen.insertBegin(start.getData());

	//enquanto o Heap n�o estiver vazio, remove o n� do heap e verifica se ele � solu��o
	////se a solu��o n�o foi encontrada, movimenta as pe�as do puzzle armazenado pelo n� visitado
	while (!H.Empty()) {
		Node<Puzzle> *u = H.Pop();
		if (u->getData().isSolved()) { //se o n� atual � a solu��o, armazena o resultado e retorna true
			result = u;
			return true;
		}

		movePieces(u);
	}

	//se a fila estiver fazia, o puzzle n�o tem solu��o
	return false;
}

//m�todo para movimentar as pe�as e inserir os movimentos poss�veis no Heap de n�s que ser�o visitados
//Recebe um ponteiro para o n� que armazena o puzzle que ser� movimentado
void solverAStar::movePieces(Node<Puzzle>* P)
{
	//se for poss�vel movimentar a pe�a abaixo do espa�o vazio e esse estado ainda n�o foi encontrado, ele � inserido
	Puzzle D = P->getData();
	if (D.moveDown() && seen.search(D) == nullptr) {
		seen.insertEnd(D);
		Node<Puzzle> *newNode = new Node<Puzzle>(D, nullptr, nullptr, P);
		H.Push(newNode);
	}

	//se for poss�vel movimentar a pe�a acima do espa�o vazio e esse estado ainda n�o foi encontrado, ele � inserido
	Puzzle U = P->getData();
	if (U.moveUp() && seen.search(U) == nullptr) {
		seen.insertEnd(U);
		Node<Puzzle> *newNode = new Node<Puzzle>(U, nullptr, nullptr, P);
		H.Push(newNode);
	}

	//se for poss�vel movimentar a pe�a a esquerda do espa�o vazio e esse estado ainda n�o foi encontrado, ele � inserido
	Puzzle L = P->getData();
	if (L.moveLeft() && seen.search(L) == nullptr) {
		seen.insertEnd(L);
		Node<Puzzle> *newNode = new Node<Puzzle>(L, nullptr, nullptr, P);
		H.Push(newNode);
	}

	//se for poss�vel movimentar a pe�a a direita do espa�o vazio e esse estado ainda n�o foi encontrado, ele � inserido
	Puzzle R = P->getData();
	if (R.moveRight() && seen.search(R) == nullptr) {
		seen.insertEnd(R);
		Node<Puzzle> *newNode = new Node<Puzzle>(R, nullptr, nullptr, P);
		H.Push(newNode);
	}
}

//destrutor padr�o
solverAStar::~solverAStar()
{
}
