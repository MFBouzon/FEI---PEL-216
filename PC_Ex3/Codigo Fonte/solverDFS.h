#ifndef SOLVER_DFS_H
#define SOLVER_DFS_H
#include "puzzleSolver.h"

//defini��o da classe solverDFS que herda os atributos da classe puzzleSolver
//implementa o m�todo Solve() utilizando abordagem de busca em profundidade
class solverDFS : public puzzleSolver
{
private:
	Stack<Node<Puzzle> *>  S; //Pilha que guarda ponteiros de n�s do tipo Puzzle, armazenando os elementos que ser�o visitados

	void movePieces(Node<Puzzle>*); //m�todo para movimentar as pe�as do puzzle
public:
	solverDFS(Node<Puzzle>); //construtor
	solverDFS(Puzzle); //sobrecarga do construtor
	bool Solve(); //m�todo que resolve o puzzle

	~solverDFS(); //destrutor padr�o
};

#endif