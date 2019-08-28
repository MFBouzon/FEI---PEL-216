#ifndef SOLVER_DFS_H
#define SOLVER_DFS_H
#include "puzzleSolver.h"

//definição da classe solverDFS que herda os atributos da classe puzzleSolver
//implementa o método Solve() utilizando abordagem de busca em profundidade
class solverDFS : public puzzleSolver
{
private:
	Stack<Node<Puzzle> *>  S; //Pilha que guarda ponteiros de nós do tipo Puzzle, armazenando os elementos que serão visitados

	void movePieces(Node<Puzzle>*); //método para movimentar as peças do puzzle
public:
	solverDFS(Node<Puzzle>); //construtor
	solverDFS(Puzzle); //sobrecarga do construtor
	bool Solve(); //método que resolve o puzzle

	~solverDFS(); //destrutor padrão
};

#endif