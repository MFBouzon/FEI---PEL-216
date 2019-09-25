#ifndef FUNCTION_H
#define FUNCTION_H


//Defini��o da classe Function
class Function
{
private:
	double a; //intervalo inferior
	double b; //intervalo superior

public:
	Function(double = 0.0, double = 1.0); //construtor padr�o

	void setA(double); //define o valor de a
	void setB(double); //define o valor de b

	double getA(); // retorna o valor de a
	double getB(); // retorna o valor de b

	double f(double); //m�todo abstrato que retorna o valor de f(x)
	double derivativeNthOrder(double x, int n); //m�todo para retornar a derivada de ordem N de f(x)
	double Midpoint(int, int); //Regra do ponto m�dio para resolver a integral
	double Trapezoidal(int, int); //Regra do trap�zio para resolver a integral
	double Simpson(int, int); //Regra de Simpson para resolver a integral

	double MidpointError(int); //M�todo para calcular o erro da regra do ponto m�dio
	double TrapezoidalError(int); //M�todo para calcular o erro da regra do trap�zio
	double SimpsonError(int); //M�todo para calcular o erro da regra de Simpson

	int adaptiveMidpoint(double); //M�todo de quadratura adaptativa para a regra do ponto m�dio
	int adaptiveTrapezoidal(double); //M�todo de quadratura adaptativa para a regra do trap�zio
	int adaptiveSimpson(double); //M�todo de quadratura adaptativa para a regra de Simpson


	~Function(); //destrutor padr�o
};


#endif