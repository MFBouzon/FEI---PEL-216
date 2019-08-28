#ifndef SOLVER_ASTAR_H
#define SOLVER_ASTAR_H
#include "puzzleSolver.h"
#include "Heap.h"

//definição da classe solverAStar que herda os atributos da classe puzzleSolver
//implementa o método Solve() utilizando abordagem de busca heuristica A-estrela
class solverAStar : public puzzleSolver
{
private:
	Heap<Puzzle> H; //Heap binário de mínimo que armazena os puzzles que serão visitados, priorizando os que possuem um custo total menor

	void movePieces(Node<Puzzle>*); //método para movimentar as peças do puzzle
public:
	solverAStar(Node<Puzzle>); //construtor
	solverAStar(Puzzle); //sobrecarga do construtor
	bool Solve(); //método que resolve o puzzle

	~solverAStar(); //destrutor padrão
};

#endif