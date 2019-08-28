/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 10/08/2019
Modificado em: 13/08/2019

Exerc�cio 4 da disciplina PEL 216 - Programa��o Cient�fica
Projeto: Implementa��o dos m�todos num�ricos Newton-Raphson e Descida de Gradiente

*/



#include<iostream>
#include "A.h"
#include "B.h"
using namespace std;
int main() {
	//teste do m�todo Newton-Raphson variando a taxa de aprendizado de 0.1 at� 1.0
	// para as fun��es A(x) e B(x)
	for (double i = 0.1; i <= 1.0; i = i + 0.1) {
		A f1(2.0, i);
		cout << "Newton-Raphson Funcao A - Beta = " << i << endl << "x = " << f1.Newton_Raphson() << endl;
		B f2(2.0, i);
		cout << "Newton-Raphson Funcao B - Beta = " << i << endl << "x = " << f2.Newton_Raphson() << endl;
	}

	//teste do m�todo Descida de Gradiente variando a taxa de aprendizado de 0.1 at� 1.0
	// para as fun��es A(x) e B(x)
	for (double i = 0.1; i <= 1.0; i = i + 0.1) {
		A f1(2.0, i);
		cout <<"Descida de Gradiente Funcao A - Beta = "<<i<<endl<<"x = "<< f1.GradientDescent() << endl;

		B f2(2.0, i);
		cout << "Descida de Gradiente Funcao B - Beta = " << i << endl << "x = " << f2.GradientDescent() << endl;
	}


	system("PAUSE");
}