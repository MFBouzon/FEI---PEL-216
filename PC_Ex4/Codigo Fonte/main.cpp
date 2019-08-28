/*
Autor: Murillo Freitas Bouzon
Linguagem: C++
Criado em: 10/08/2019
Modificado em: 13/08/2019

Exercício 4 da disciplina PEL 216 - Programação Científica
Projeto: Implementação dos métodos numéricos Newton-Raphson e Descida de Gradiente

*/



#include<iostream>
#include "A.h"
#include "B.h"
using namespace std;
int main() {
	//teste do método Newton-Raphson variando a taxa de aprendizado de 0.1 até 1.0
	// para as funções A(x) e B(x)
	for (double i = 0.1; i <= 1.0; i = i + 0.1) {
		A f1(2.0, i);
		cout << "Newton-Raphson Funcao A - Beta = " << i << endl << "x = " << f1.Newton_Raphson() << endl;
		B f2(2.0, i);
		cout << "Newton-Raphson Funcao B - Beta = " << i << endl << "x = " << f2.Newton_Raphson() << endl;
	}

	//teste do método Descida de Gradiente variando a taxa de aprendizado de 0.1 até 1.0
	// para as funções A(x) e B(x)
	for (double i = 0.1; i <= 1.0; i = i + 0.1) {
		A f1(2.0, i);
		cout <<"Descida de Gradiente Funcao A - Beta = "<<i<<endl<<"x = "<< f1.GradientDescent() << endl;

		B f2(2.0, i);
		cout << "Descida de Gradiente Funcao B - Beta = " << i << endl << "x = " << f2.GradientDescent() << endl;
	}


	system("PAUSE");
}