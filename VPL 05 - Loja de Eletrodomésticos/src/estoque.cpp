#ifndef ESTOQUE_CPP
#define ESTOQUE_CPP

#include "fogao.hpp"
#include "geladeira.hpp"
#include "estoque.hpp"

Estoque::Estoque(){}

void Estoque::armazena_geladeira(int capacidade, int portas)
{
	Geladeira geladeira(capacidade, portas);
	geladeiras.push_back(geladeira);
}

void Estoque::vende_geladeira(int capacidade, int portas)
{
	for (unsigned int i = 0; i < geladeiras.size(); i++)
	{
		if (geladeiras[i].get_capacidade_em_litros() == capacidade && geladeiras[i].get_numero_de_portas() == portas)
		{
			geladeiras.erase(geladeiras.begin() + i);
			return;
		}
	}
}

void Estoque::armazena_fogao(int queimadores, int capacidade)
{
	Fogao fogao(queimadores, capacidade);
	fogoes.push_back(fogao);
}

void Estoque::vende_fogao(int queimadores, int capacidade)
{
	for (unsigned int i = 0; i < fogoes.size(); i++)
	{
		if (fogoes[i].get_numero_de_queimadores() == queimadores && fogoes[i].get_capacidade_forno() == capacidade)
		{
			fogoes.erase(fogoes.begin() + i);
			return;
		}
	}
}

void Estoque::exibe_geladeiras()
{
	for (unsigned int i = 0; i < geladeiras.size(); i++)
	{
		std::cout << "G " << geladeiras[i].get_capacidade_em_litros() << " ";
		std::cout << geladeiras[i].get_numero_de_portas() << std::endl;
	}
}

void Estoque::exibe_fogoes()
{
	for (unsigned int i = 0; i < fogoes.size(); i++)
	{
		std::cout << "F " << fogoes[i].get_numero_de_queimadores() << " ";
		std::cout << fogoes[i].get_capacidade_forno() << std::endl;
	}
}

int Estoque::quantidade_geladeiras()
{
	return geladeiras.size();
}

int Estoque::quantidade_fogoes()
{
	return fogoes.size();
}

#endif
