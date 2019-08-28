#ifndef FUNCTION_H
#define FUNCTION_H


//Defini��o da classe abstrata function
class Function
{
private:
	double x0; //valor de x atual
	double beta; //taxa de aprendizado
	double epsilon; //taxa de erro aceit�vel

public:
	Function(double = 2.0, double = 1.0, double = 0.001); //construtor padr�o

	void setX0(double); //define o valor de x atual
	void setBeta(double); //define o valor da taxa de aprendizado
	void setEpsilon(double); //define o valor da taxa de erro aceit�vel

	double getX0(); // retorna o valor de x atual
	double getBeta(); // retorna o valor da taxa de aprendizado
	double getEpsilon(double); // retorna a taxa de erro aceit�vel

	virtual double Solve(); //m�todo abstrato que retorna a f(x)
	virtual double solveDerivative(); // m�todo abstrato que retorna f'(x)
	double Newton_Raphson(); //M�todo de Newton-Raphson para encontrar a raiz da fun��o
	double GradientDescent(); //M�todo de Descida de Gradiente para encontrar o m�nimo da fun��o

	~Function(); //destrutor padr�o
};

#endif