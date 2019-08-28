#ifndef FUNCTION_H
#define FUNCTION_H


//Definição da classe abstrata function
class Function
{
private:
	double x0; //valor de x atual
	double beta; //taxa de aprendizado
	double epsilon; //taxa de erro aceitável

public:
	Function(double = 2.0, double = 1.0, double = 0.001); //construtor padrão

	void setX0(double); //define o valor de x atual
	void setBeta(double); //define o valor da taxa de aprendizado
	void setEpsilon(double); //define o valor da taxa de erro aceitável

	double getX0(); // retorna o valor de x atual
	double getBeta(); // retorna o valor da taxa de aprendizado
	double getEpsilon(double); // retorna a taxa de erro aceitável

	virtual double Solve(); //método abstrato que retorna a f(x)
	virtual double solveDerivative(); // método abstrato que retorna f'(x)
	double Newton_Raphson(); //Método de Newton-Raphson para encontrar a raiz da função
	double GradientDescent(); //Método de Descida de Gradiente para encontrar o mínimo da função

	~Function(); //destrutor padrão
};

#endif