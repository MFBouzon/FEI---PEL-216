#ifndef SOLVER_BFS_H
#define SOLVER_BFS_H
#include "puzzleSolver.h"

//defini��o da classe solverBFS que herda os atributos da classe puzzleSolver
//implementa o m�todo Solve() utilizando abordagem de busca em largura
class solverBFS : public puzzleSolver
{
private:
	Queue <Node<Puzzle> *> Q; //Fila que guarda ponteiros de n�s do tipo puzzle, sendo a fila de elementos que ser�o visitados

	void movePieces(Node<Puzzle>*); //m�todo para movimentar as pe�as do puzzle
public:
	solverBFS(Node<Puzzle>); //construtor
	solverBFS(Puzzle); //sobrecarga do construtor
	bool Solve(); //m�todo que resolve o puzzle
	 
	~solverBFS(); //destrutor padr�o
};

#endif
