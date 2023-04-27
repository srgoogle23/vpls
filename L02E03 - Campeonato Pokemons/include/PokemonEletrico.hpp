#ifndef POKEMON_ELETRICO_HPP
#define POKEMON_ELETRICO_HPP

#include "Pokemon.hpp"

using namespace std;

class PokemonEletrico : public Pokemon
{
	public:
		double _potencia_raio;
		PokemonEletrico();
		PokemonEletrico(string nome, string tipo_ataque, double forca_ataque, double potencia_raio);
		void falar_tipo_ataque();
		double calcular_dano();
		double ataque_eletrico();
};

#endif