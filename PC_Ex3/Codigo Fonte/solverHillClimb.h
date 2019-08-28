#ifndef SOLVER_HILL_CLIMB_H
#define SOLVER_HILL_CLIMB_H
#include "puzzleSolver.h"

//definição da classe solverHillClimb que herda os atributos da classe puzzleSolver
//implementa o método Solve() utilizando abordagem de busca heuristica subida de encosta
class solverHillClimb : public puzzleSolver
{
private:
	Node<Puzzle>* movePieces(Node<Puzzle>*); //método para movimentar as peças do puzzle
public:
	solverHillClimb(Node<Puzzle>); //construtor
	solverHillClimb(Puzzle); //sobrecarga do construtor
	bool Solve(); //método que resolve o puzzle

	~solverHillClimb(); //destrutor padrão
};

#endif