#ifndef POKEMON_EXPLOSIVO_HPP
#define POKEMON_EXPLOSIVO_HPP

#include "Pokemon.hpp"

using namespace std;

class PokemonExplosivo : public Pokemon
{
	public:
		double _temperatura_explosao;
		PokemonExplosivo();
		PokemonExplosivo(std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao);
		void falar_tipo_ataque();
		double calcular_dano();
		double ataque_aquatico();
};

#endif