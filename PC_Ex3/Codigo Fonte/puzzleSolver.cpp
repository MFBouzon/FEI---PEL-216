
#include "puzzleSolver.h"


//construtor que recebe um n� do tipo Puzzle que � definido como o estado inicial
puzzleSolver::puzzleSolver(Node<Puzzle> S)
{
	start = S;
}

//construtor que recebe um Puzzle P que � definido com o estado inicial
puzzleSolver::puzzleSolver(Puzzle P)
{
	start.setData(P);
}


//m�todo abstrato
bool puzzleSolver::Solve()
{
	return false;
}

//m�todo abstrato
void puzzleSolver::movePieces()
{
}

//preenche uma lista com os movimentos feitos para chegar at� o resultado
void puzzleSolver::getResultPath(doublyList<Puzzle>& paths)
{
	Node<Puzzle>* ptr = result;
	while (ptr != nullptr) {
		paths.insertBegin(ptr->getData());
		ptr = ptr->getPrev();
	}
}

//imprime o resultado do puzzle se ele puder ser resolvido
void puzzleSolver::printResult()
{
	if (Solve()) {

		doublyList<Puzzle> result;
		getResultPath(result);
		Puzzle P = result.getLast()->getData();
		
		printf("Movimentos realizados:\n\n");
		result.print();

		printf("Puzzle resolvido com %d movimento(s).\n", P.getDist());
		printf("Foram explorados %d nos.\n", seen.getSize());
	}
	else
		printf("Nao foi possivel encontrar a solucao.\n");
}


//destrutor padr�o
puzzleSolver::~puzzleSolver()
{
	delete result;
}
