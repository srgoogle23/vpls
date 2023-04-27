#include "PokemonExplosivo.hpp"

PokemonExplosivo::PokemonExplosivo()
{
	_temperatura_explosao = 0.0;
}

PokemonExplosivo::PokemonExplosivo(std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao) : Pokemon(nome, tipo_ataque, forca_ataque)
{
	_temperatura_explosao = temperatura_explosao;
}

void PokemonExplosivo::falar_tipo_ataque()
{
	// sobrescrita do método da superclasse. Além de escrever o tipo do ataque também escreve "Boom!" (seguido de quebra de linha).
	cout << _tipo_ataque << "!" << endl;
	cout << "Boom!" << endl;
}

double PokemonExplosivo::calcular_dano()
{
	return ataque_aquatico();
}

double PokemonExplosivo::ataque_aquatico()
{
	return _forca_ataque / _temperatura_explosao;
}