#ifndef PUZZLE_SOLVER_H
#define PUZZLE_SOLVER_H

#include "Stack.h"
#include "Puzzle.h"
#include "Queue.h"

//definição da classe puzzle solver
class puzzleSolver
{
protected:
	Node<Puzzle> start; //Nó que guarda o estado inicial do puzzle
	Node<Puzzle> *result; //Nó que aponta para o resultado final do puzzle
	
	doublyList<Puzzle> seen; //Lista que armazena os estados ja foram visitados


	void getResultPath(doublyList<Puzzle>&); //método para obter os movimentos realizados para resolver o puzzle
	virtual void movePieces(); //método abstrato para movimentar as peças do puzzle
public:
	puzzleSolver(Node<Puzzle>); //construtor
	puzzleSolver(Puzzle); //sobrecarga do construtor
	
	virtual bool Solve(); //método abstrato para resolver o puzzle
	
	void printResult(); //método para imprimir os movimentos realizados para resolver o puzzle

	~puzzleSolver(); //destrutor padrão
};

#endif