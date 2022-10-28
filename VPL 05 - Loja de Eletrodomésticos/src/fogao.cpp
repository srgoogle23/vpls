#ifndef FOGAO_CPP
#define FOGAO_CPP

#include "fogao.hpp"

Fogao::Fogao(int numero_de_queimadores, int capacidade_forno):
	numero_de_queimadores(numero_de_queimadores),
	capacidade_forno(capacidade_forno) {}

Fogao::Fogao():
	numero_de_queimadores(0),
	capacidade_forno(0) {}

int Fogao::get_numero_de_queimadores()
{
	return numero_de_queimadores;
}

int Fogao::get_capacidade_forno()
{
	return capacidade_forno;
}
#endif
