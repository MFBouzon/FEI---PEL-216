#include "Puzzle.h"

//construtor padrão
Puzzle::Puzzle()
{
}

//construtor que recebe uma matriz p do tipo int com as posições das peças do puzzle
// um int d com o valor da distância do puzzle até o puzzle inicial
Puzzle::Puzzle(int p[][3], int d)
{
	
	dist = d;
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			pieces[i][j] = p[i][j];
			if (p[i][j] == 0) { //armazena os índices do espaço vazio
				emptyIndR = i;
				emptyIndC = j;
			}
		}
	
	solvable = checkSolvable();

	heuristic = calculateHeuristic();

	totalCost = dist + heuristic;
}

//calcula o peso do puzzle utilizando a heuristica distância de manhattan
// fazendo a soma da diferença entre a linha e a coluna da posição da peça no puzzle
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

// retorna um variavel booleana que representa se o puzzle é resolvível ou não
// calculando o número de inversões presentes no puzzle
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
			if (verif[i] > verif[j]) //uma inversão ocorre quando um elemento na posição i é menor que um elemento da posição j, sendo i < j
				inv++;

	if (inv % 2 != 0) // se o número de inversões é impar, o puzzle não tem solução
		return false;
	else //senão o puzzle é resolvível
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

//retorna a distância para o puzzle inicial
int Puzzle::getDist()
{
	return dist;
}

//retorna o custo total
int Puzzle::getTotalCost()
{
	return totalCost;
}

//retorna se a variável solvable
bool Puzzle::getSolvable()
{
	return solvable;
}

//método que retorna true se foi possível movimentar a peça acima do espaço vazio
// ou false se não foi possível
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

//método que retorna true se foi possível movimentar a peça abaixo do espaço vazio
// ou false se não foi possível

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

//método que retorna true se foi possível movimentar a peça a esquerda do espaço vazio
// ou false se não foi possível
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

//método que retorna true se foi possível movimentar a peça a direita do espaço vazio
// ou false se não foi possível
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
// ou false caso ainda não esteja
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

//sobrecarga do operador "==" para verificar se dois puzzles são iguais
bool Puzzle::operator==(const Puzzle P)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (pieces[i][j] != P.pieces[i][j])
				return false;

	return true;
}

//sobrecarga do operador "!=" para verificar se dois puzzles são diferentes
bool Puzzle::operator!=(const Puzzle P)
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (pieces[i][j] != P.pieces[i][j])
				return true;

	return false;
}

//sobrecarga do operador "<" para verificar se o custo de um puzzle é menor
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

//sobrecarga do operador "<<" para imprimir as peças do puzzle
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

//destrutor padrão
Puzzle::~Puzzle()
{
}


