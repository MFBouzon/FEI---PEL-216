#ifndef FUNCTION_H
#define FUNCTION_H


//Definição da classe Function
class Function
{
private:
	double a; //intervalo inferior
	double b; //intervalo superior

public:
	Function(double = 0.0, double = 1.0); //construtor padrão

	void setA(double); //define o valor de a
	void setB(double); //define o valor de b

	double getA(); // retorna o valor de a
	double getB(); // retorna o valor de b

	double f(double); //método abstrato que retorna o valor de f(x)
	double derivativeNthOrder(double x, int n); //método para retornar a derivada de ordem N de f(x)
	double Midpoint(int, int); //Regra do ponto médio para resolver a integral
	double Trapezoidal(int, int); //Regra do trapézio para resolver a integral
	double Simpson(int, int); //Regra de Simpson para resolver a integral

	double MidpointError(int); //Método para calcular o erro da regra do ponto médio
	double TrapezoidalError(int); //Método para calcular o erro da regra do trapézio
	double SimpsonError(int); //Método para calcular o erro da regra de Simpson

	int adaptiveMidpoint(double); //Método de quadratura adaptativa para a regra do ponto médio
	int adaptiveTrapezoidal(double); //Método de quadratura adaptativa para a regra do trapézio
	int adaptiveSimpson(double); //Método de quadratura adaptativa para a regra de Simpson


	~Function(); //destrutor padrão
};


#endif