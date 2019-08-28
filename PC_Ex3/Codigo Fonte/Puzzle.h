#ifndef PUZZLE_H
#define PUZZLE_H

#include <cmath>
#include <iostream>
using namespace std;

//definição da classe Puzzle

class Puzzle
{
private:
	int pieces[3][3]; //matriz que representa a posição das peças do puzzle
	int totalCost; //custo total do puzzle
	int dist; //número de movimentos realizados a partir do puzzle inicial
	int heuristic; //valor calculado da heurística

	int emptyIndR; //índice da linha do espaço vazio
	int emptyIndC; //índice da coluna do espaço vazio

	bool solvable; //variável booleana representando se o puzzle tem solução
public:
	Puzzle(); // construtor padrão 
	Puzzle(int p[][3], int d = 0); //construtor padrão
	int calculateHeuristic(); //método que calcula a heurística do puzzle
	bool checkSolvable(); //método que verifica se o puzzle é resolvível
	void setDist(int);
	
	int getHeuristic(); //método que retorna o valor da heuristica
	int getDist(); //método que retorna a distância do puzzle para o puzzle inicial
	int getTotalCost(); //método que retorna o custo total do puzzle
	bool getSolvable(); //método que retorna a variável booleana solvable

	bool moveUp(); //método para movimentar a peça acima do espaço vazio
	bool moveDown(); //método para movimentar a peça abaixo do espaço vazio
	bool moveLeft(); //método para movimentar a peça a esquerda do espaço vazio
	bool moveRight(); //método para movimentar a peça a direita do espaço vazio

	bool isSolved(); //método que retorna se o puzzle está resolvido

	Puzzle& operator =(Puzzle P); //sobrecarga do operador "="
	friend ostream & operator<< (ostream &out, const Puzzle P); // sobrecarga do operador "<<'
	bool operator ==(const Puzzle P); //sobrecarga do operador "=="
	bool operator !=(const Puzzle P); //sobrecarga do operador "!="
	bool operator <(const Puzzle P); //sobrecarga do operador "<"

	~Puzzle(); // destrutor padrão
};

#endif