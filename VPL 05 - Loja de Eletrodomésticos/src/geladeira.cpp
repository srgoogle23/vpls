#ifndef GELADEIRA_CPP
#define GELADEIRA_CPP

#include "geladeira.hpp"

Geladeira::Geladeira(int capacidade_em_litros, int numero_de_portas):
	capacidade_em_litros(capacidade_em_litros),
	numero_de_portas(numero_de_portas) {}
	
Geladeira::Geladeira():
	capacidade_em_litros(0),
	numero_de_portas(0) {}

int Geladeira::get_capacidade_em_litros()
{
	return capacidade_em_litros;
}

int Geladeira::get_numero_de_portas()
{
	return numero_de_portas;
}
#endif
