#include "Puzzle.h"

//construtor padr�o
Puzzle::Puzzle()
{
}

//construtor que recebe uma matriz p do tipo int com as posi��es das pe�as do puzzle
// um int d com o valor da dist�ncia do puzzle at� o puzzle inicial
Puzzle::Puzzle(int p[][3], int d)
{
	
	dist = d;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			pieces[i][j] = p[i][j];
			if (p[i][j] == 0) { //armazena os �ndices do espa�o vazio
				emptyIndR = i;
				emptyIndC = j;
			}
		}
	
	solvable = checkSolvable();

	heuristic = calculateHeuristic();

	totalCost = dist + heuristic;
}

//calcula o peso do puzzle utilizando a heuristica dist�ncia de manhattan
// fazendo a soma da diferen�a entre a linha e a coluna da posi��o da pe�a no puzzle
// com a sua respectiva no resultado final
int Puzzle::calculateHeuristic()
{
	int R[][3] = 
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0}
	};

	int h = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) 
			for(int k = 0; k < 3; k++)
				for (int w = 0; w < 3; w++) {
					if (pieces[i][j] == R[k][w] && pieces[i][j] != 0)
						h += abs(i - k) + abs(j - w);
				}
	return h;
}

// retorna um variavel booleana que representa se o puzzle � resolv�vel ou n�o
// calculando o n�mero de invers�es presentes no puzzle
bool Puzzle::checkSolvable()
{
	int verif[8];
	int indV = 0;
	int inv = 0;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (pieces[i][j] != 0) {
				verif[indV] = pieces[i][j];
				indV++;
			}
		}

	for (int i = 0; i < 8; i++)
		for (int j = i + 1; j < 8; j++)
			if (verif[i] > verif[j]) //uma invers�o ocorre quando um elemento na posi��o i � menor que um elemento da posi��o j, sendo i < j
				inv++;

	if (inv % 2 != 0) // se o n�mero de invers�es � impar, o puzzle n�o tem solu��o
		return false;
	else //sen�o o puzzle � resolv�vel
		return true;

}

void Puzzle::setDist(int d)
{
	dist = d;
	totalCost = d + heuristic;
}


//retorna o valor calculado pela heuristica
int Puzzle::getHeuristic()
{
	return heuristic;
}

//retorna a dist�ncia para o puzzle inicial
int Puzzle::getDist()
{
	return dist;
}

//retorna o custo total
int Puzzle::getTotalCost()
{
	return totalCost;
}

//retorna se a vari�vel solvable
bool Puzzle::getSolvable()
{
	return solvable;
}

//m�todo que retorna true se foi poss�vel movimentar a pe�a acima do espa�o vazio
// ou false se n�o foi poss�vel
bool Puzzle::moveUp()
{
	if (emptyIndR != 0) {
		pieces[emptyIndR][emptyIndC] = pieces[emptyIndR-1][emptyIndC];
		pieces[emptyIndR - 1][emptyIndC] = 0;
		emptyIndR -= 1;
		heuristic = calculateHeuristic();
		dist++;
		totalCost = heuristic + dist;
		return true;
	}
	

	return false;
}

//m�todo que retorna true se foi poss�vel movimentar a pe�a abaixo do espa�o vazio
// ou false se n�o foi poss�vel

bool Puzzle::moveDown()
{
	if (emptyIndR != 2) {
		pieces[emptyIndR][emptyIndC] = pieces[emptyIndR + 1][emptyIndC];
		pieces[emptyIndR + 1][emptyIndC] = 0;
		emptyIndR += 1;
		heuristic = calculateHeuristic();
		dist++;
		totalCost = heuristic + dist;
		return true;
	}

	return false;
}

//m�todo que retorna true se foi poss�vel movimentar a pe�a a esquerda do espa�o vazio
// ou false se n�o foi poss�vel
bool Puzzle::moveLeft()
{
	if (emptyIndC != 0) {
		pieces[emptyIndR][emptyIndC] = pieces[emptyIndR][emptyIndC - 1];
		pieces[emptyIndR][emptyIndC - 1] = 0;
		emptyIndC -= 1;
		heuristic = calculateHeuristic();
		dist++;
		totalCost = heuristic + dist;
		return true;
	}

	return false;
}

//m�todo que retorna true se foi poss�vel movimentar a pe�a a direita do espa�o vazio
// ou false se n�o foi poss�vel
bool Puzzle::moveRight()
{
	if (emptyIndC != 2) {
		pieces[emptyIndR][emptyIndC] = pieces[emptyIndR][emptyIndC + 1];
		pieces[emptyIndR][emptyIndC + 1] = 0;
		emptyIndC += 1;
		heuristic = calculateHeuristic();
		dist++;
		totalCost = heuristic + dist;
		return true;
	}
	return false;
}

//retorn true se o puzzle estiver resolvido
// ou false caso ainda n�o esteja
bool Puzzle::isSolved()
{
	if (heuristic == 0)
		return true;
	else
		return false;
}

//sobrecarga do operador "=" para atribuir o valor de um puzzle P
// para um novo objeto puzzle
Puzzle& Puzzle::operator=(Puzzle P)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			pieces[i][j] = P.pieces[i][j];
	dist = P.dist;
	heuristic = P.heuristic;
	totalCost = P.totalCost;
	emptyIndR = P.emptyIndR;
	emptyIndC = P.emptyIndC;
	solvable = P.solvable;

	return *this;
}

//sobrecarga do operador "==" para verificar se dois puzzles s�o iguais
bool Puzzle::operator==(const Puzzle P)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (pieces[i][j] != P.pieces[i][j])
				return false;

	return true;
}

//sobrecarga do operador "!=" para verificar se dois puzzles s�o diferentes
bool Puzzle::operator!=(const Puzzle P)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (pieces[i][j] != P.pieces[i][j])
				return true;

	return false;
}

//sobrecarga do operador "<" para verificar se o custo de um puzzle � menor
// que o custo de um outro Puzzle P
bool Puzzle::operator<(const Puzzle P)
{
	if (totalCost < P.totalCost)
		return true;
	else if (totalCost == P.totalCost) {
		if (heuristic < P.heuristic)
			return true;
	}
	else
		return false;
}

//sobrecarga do operador "<<" para imprimir as pe�as do puzzle
ostream & operator<<(ostream & out, const Puzzle P)
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			out << " " << P.pieces[i][j];
		}
		out << endl;
	}
	return out;
}

//destrutor padr�o
Puzzle::~Puzzle()
{
}


