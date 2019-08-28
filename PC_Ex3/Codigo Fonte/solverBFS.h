#ifndef SOLVER_BFS_H
#define SOLVER_BFS_H
#include "puzzleSolver.h"

//definição da classe solverBFS que herda os atributos da classe puzzleSolver
//implementa o método Solve() utilizando abordagem de busca em largura
class solverBFS : public puzzleSolver
{
private:
	Queue <Node<Puzzle> *> Q; //Fila que guarda ponteiros de nós do tipo puzzle, sendo a fila de elementos que serão visitados

	void movePieces(Node<Puzzle>*); //método para movimentar as peças do puzzle
public:
	solverBFS(Node<Puzzle>); //construtor
	solverBFS(Puzzle); //sobrecarga do construtor
	bool Solve(); //método que resolve o puzzle
	 
	~solverBFS(); //destrutor padrão
};

#endif
