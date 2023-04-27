#include "PokemonEletrico.hpp"

PokemonEletrico::PokemonEletrico() : Pokemon() {}
PokemonEletrico::PokemonEletrico(string nome, string tipo_ataque, double forca_ataque, double potencia_raio) : Pokemon(nome, tipo_ataque, forca_ataque)
{
	_potencia_raio = potencia_raio;
}

void PokemonEletrico::falar_tipo_ataque()
{
	// sobrescrita do método da superclasse. Além de escrever o tipo do ataque também escreve "Bzzzz!" (seguido de quebra de linha).
	cout << _tipo_ataque << "!" << endl;
	cout << "Bzzzz!" << endl;
}

double PokemonEletrico::calcular_dano()
{
	return ataque_eletrico();
}

double PokemonEletrico::ataque_eletrico()
{
	// calcula e retorna o valor do dano do ataque específico. Calculado da seguinte forma: forca_ataque * potencia_raio.
	return _forca_ataque * _potencia_raio;
}