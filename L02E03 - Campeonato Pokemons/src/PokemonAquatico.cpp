#include "PokemonAquatico.hpp"

PokemonAquatico::PokemonAquatico()
{
	_litros_jato = 0.0;
}

PokemonAquatico::PokemonAquatico(string nome, string tipo_ataque, double forca_ataque, double litros_jato) : Pokemon(nome, tipo_ataque, forca_ataque)
{
	_litros_jato = litros_jato;
}

void PokemonAquatico::falar_tipo_ataque()
{
	// sobrescrita do método da superclasse. Além de escrever o tipo do ataque também escreve "Boom!" (seguido de quebra de linha).
	cout << _tipo_ataque << "!" << endl;
	cout << "Splash!" << endl;
}

double PokemonAquatico::calcular_dano()
{
	return ataque_aquatico();
}

double PokemonAquatico::ataque_aquatico()
{
	return _forca_ataque + _litros_jato;
}