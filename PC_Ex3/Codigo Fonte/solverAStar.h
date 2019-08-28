#ifndef SOLVER_ASTAR_H
#define SOLVER_ASTAR_H
#include "puzzleSolver.h"
#include "Heap.h"

//defini��o da classe solverAStar que herda os atributos da classe puzzleSolver
//implementa o m�todo Solve() utilizando abordagem de busca heuristica A-estrela
class solverAStar : public puzzleSolver
{
private:
	Heap<Puzzle> H; //Heap bin�rio de m�nimo que armazena os puzzles que ser�o visitados, priorizando os que possuem um custo total menor

	void movePieces(Node<Puzzle>*); //m�todo para movimentar as pe�as do puzzle
public:
	solverAStar(Node<Puzzle>); //construtor
	solverAStar(Puzzle); //sobrecarga do construtor
	bool Solve(); //m�todo que resolve o puzzle

	~solverAStar(); //destrutor padr�o
};

#endif