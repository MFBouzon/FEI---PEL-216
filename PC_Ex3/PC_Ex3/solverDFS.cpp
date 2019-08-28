#include "solverDFS.h"



//construtor que recebe um node de puzzle e inicializa o nó inicial
solverDFS::solverDFS(Node<Puzzle> P) : puzzleSolver(P)
{
}

//construtor que recebe um Puzzle e inicializa o nó inicial
solverDFS::solverDFS(Puzzle P) : puzzleSolver(P)
{
}


//método que resolve o puzzle utilizando a abordagem DFS (Depth-First Search)
bool solverDFS::Solve()
{
	//se o puzzle não tiver solução, retorna falso
	if (!start.getData().getSolvable())
		return false;

	//empilha o nó inicial
	S.Push(&start);
	seen.insertBegin(start.getData());

	//enquanto a pilha não estiver vazia, desempilha o nó da fila e verifica se ele é solução.
	//se a solução não foi encontrada, movimenta as peças do puzzle armazenado pelo nó visitado
	while (!S.Empty()) {
		Node<Puzzle> *u = S.Pop();
		if (u->getData().isSolved()) { //se o nó atual é a solução, armazena o resultado e retorna true
			result = u;
			return true;
		}

		movePieces(u);
	}

	//se a fila estiver fazia, o puzzle não tem solução
	return false;
}

//método para movimentar as peças e empilhar os movimentos possíveis na pilha de nós que serão visitados
//Recebe um ponteiro para o nó que armazena o puzzle que será movimentado
void solverDFS::movePieces(Node<Puzzle>* P)
{
	//se for possível movimentar a peça abaixo do espaço vazio e esse estado ainda não foi encontrado, ele é empilhado
	Puzzle D = P->getData();
	if (D.moveDown() && seen.search(D) == nullptr) {
		seen.insertEnd(D);
		Node<Puzzle> *newNode = new Node<Puzzle>(D, nullptr, nullptr, P);
		S.Push(newNode);
	}

	//se for possível movimentar a peça acima do espaço vazio e esse estado ainda não foi encontrado, ele é empilhado
	Puzzle U = P->getData();
	if (U.moveUp() && seen.search(U) == nullptr) {
		seen.insertEnd(U);
		Node<Puzzle> *newNode = new Node<Puzzle>(U, nullptr, nullptr, P);
		S.Push(newNode);
	}

	//se for possível movimentar a peça a esquerda do espaço vazio e esse estado ainda não tenha foi encontrado, ele é empilhado
	Puzzle L = P->getData();
	if (L.moveLeft() && seen.search(L) == nullptr) {
		seen.insertEnd(L);
		Node<Puzzle> *newNode = new Node<Puzzle>(L, nullptr, nullptr, P);
		S.Push(newNode);
	}

	//se for possível movimentar a peça a direita do espaço vazio e esse estado ainda não tenha foi encontrado, ele é empilhado
	Puzzle R = P->getData();
	if (R.moveRight() && seen.search(R) == nullptr) {
		seen.insertEnd(R);
		Node<Puzzle> *newNode = new Node<Puzzle>(R, nullptr, nullptr, P);
		S.Push(newNode);
	}
}

//destrutor padrão
solverDFS::~solverDFS()
{
}
