#ifndef PUZZLE_H
#define PUZZLE_H

#include <cmath>
#include <iostream>
using namespace std;

//defini��o da classe Puzzle

class Puzzle
{
private:
	int pieces[3][3]; //matriz que representa a posi��o das pe�as do puzzle
	int totalCost; //custo total do puzzle
	int dist; //n�mero de movimentos realizados a partir do puzzle inicial
	int heuristic; //valor calculado da heur�stica

	int emptyIndR; //�ndice da linha do espa�o vazio
	int emptyIndC; //�ndice da coluna do espa�o vazio

	bool solvable; //vari�vel booleana representando se o puzzle tem solu��o
public:
	Puzzle(); // construtor padr�o 
	Puzzle(int p[][3], int d = 0); //construtor padr�o
	int calculateHeuristic(); //m�todo que calcula a heur�stica do puzzle
	bool checkSolvable(); //m�todo que verifica se o puzzle � resolv�vel
	void setDist(int);
	
	int getHeuristic(); //m�todo que retorna o valor da heuristica
	int getDist(); //m�todo que retorna a dist�ncia do puzzle para o puzzle inicial
	int getTotalCost(); //m�todo que retorna o custo total do puzzle
	bool getSolvable(); //m�todo que retorna a vari�vel booleana solvable

	bool moveUp(); //m�todo para movimentar a pe�a acima do espa�o vazio
	bool moveDown(); //m�todo para movimentar a pe�a abaixo do espa�o vazio
	bool moveLeft(); //m�todo para movimentar a pe�a a esquerda do espa�o vazio
	bool moveRight(); //m�todo para movimentar a pe�a a direita do espa�o vazio

	bool isSolved(); //m�todo que retorna se o puzzle est� resolvido

	Puzzle& operator =(Puzzle P); //sobrecarga do operador "="
	friend ostream & operator<< (ostream &out, const Puzzle P); // sobrecarga do operador "<<'
	bool operator ==(const Puzzle P); //sobrecarga do operador "=="
	bool operator !=(const Puzzle P); //sobrecarga do operador "!="
	bool operator <(const Puzzle P); //sobrecarga do operador "<"

	~Puzzle(); // destrutor padr�o
};

#endif