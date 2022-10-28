#include "Fatura.hpp"
#include <iostream>

using namespace std;


Fatura::Fatura(int id, double valor) : codigo(id), valor(valor) {}

void Fatura::imprimir_dados()
{
	// "id valor"
	cout << " " << codigo << " " << valor << endl;
}

double Fatura::getValor(){
	return valor;
}

int Fatura::getCodigo()
{
	return codigo;
}