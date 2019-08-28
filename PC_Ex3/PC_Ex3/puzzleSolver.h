#ifndef PUZZLE_SOLVER_H
#define PUZZLE_SOLVER_H

#include "Stack.h"
#include "Puzzle.h"
#include "Queue.h"

//defini��o da classe puzzle solver
class puzzleSolver
{
protected:
	Node<Puzzle> start; //N� que guarda o estado inicial do puzzle
	Node<Puzzle> *result; //N� que aponta para o resultado final do puzzle
	
	doublyList<Puzzle> seen; //Lista que armazena os estados ja foram visitados


	void getResultPath(doublyList<Puzzle>&); //m�todo para obter os movimentos realizados para resolver o puzzle
	virtual void movePieces(); //m�todo abstrato para movimentar as pe�as do puzzle
public:
	puzzleSolver(Node<Puzzle>); //construtor
	puzzleSolver(Puzzle); //sobrecarga do construtor
	
	virtual bool Solve(); //m�todo abstrato para resolver o puzzle
	
	void printResult(); //m�todo para imprimir os movimentos realizados para resolver o puzzle

	~puzzleSolver(); //destrutor padr�o
};

#endif