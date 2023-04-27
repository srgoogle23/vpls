#ifndef POKEMON_AQUATICO_HPP
#define POKEMON_AQUATICO_HPP

#include "Pokemon.hpp"

using namespace std;

class PokemonAquatico : public Pokemon
{
	public:
		double _litros_jato;
		PokemonAquatico();
		PokemonAquatico(string nome, string tipo_ataque, double forca_ataque, double litros_jato);
		void falar_tipo_ataque();
		double calcular_dano();
		double ataque_aquatico();
};

#endif