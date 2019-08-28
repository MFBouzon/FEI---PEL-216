#ifndef SOLVER_HILL_CLIMB_H
#define SOLVER_HILL_CLIMB_H
#include "puzzleSolver.h"

//defini��o da classe solverHillClimb que herda os atributos da classe puzzleSolver
//implementa o m�todo Solve() utilizando abordagem de busca heuristica subida de encosta
class solverHillClimb : public puzzleSolver
{
private:
	Node<Puzzle>* movePieces(Node<Puzzle>*); //m�todo para movimentar as pe�as do puzzle
public:
	solverHillClimb(Node<Puzzle>); //construtor
	solverHillClimb(Puzzle); //sobrecarga do construtor
	bool Solve(); //m�todo que resolve o puzzle

	~solverHillClimb(); //destrutor padr�o
};

#endif