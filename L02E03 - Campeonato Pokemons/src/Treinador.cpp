#include "Treinador.hpp"

Treinador::Treinador()
{
	_nome = "";
}

Treinador::Treinador(string nome)
{
	_nome = nome;
}

void Treinador::cadastrar_pokemon_eletrico(string nome, string tipo_ataque, double forca_ataque, double potencia_raio)
{
	Pokemon *pk = new PokemonEletrico(nome, tipo_ataque, forca_ataque, potencia_raio);
	_pokemons.push_back(pk);
}

void Treinador::cadastrar_pokemon_aquatico(string nome, string tipo_ataque, double forca_ataque, double litros_jato)
{
	Pokemon *pk = new PokemonAquatico(nome, tipo_ataque, forca_ataque, litros_jato);
	_pokemons.push_back(pk);
}

void Treinador::cadastrar_pokemon_explosivo(string nome, string tipo_ataque, double forca_ataque, double temperatura_explosao)
{
	Pokemon *pk = new PokemonExplosivo(nome, tipo_ataque, forca_ataque, temperatura_explosao);
	_pokemons.push_back(pk);
}

Pokemon *Treinador::usar_pokemon(int idpk) // retorna um pokemon específico a partir do índice informado.
{
	return _pokemons[idpk];
}

void Treinador::imprimir_informacoes()
{
	// Se nenhum Pokemon foi cadastrado
	if (_pokemons.size() == 0)
	{
		// Nome: NOME
		// ----------
		// Nenhum Pokemon cadastrado!
		// ----------
		cout << "Nome: " << _nome << endl;
		cout << "----------" << endl;
		cout << "Nenhum Pokemon cadastrado!" << endl;
		cout << "----------" << endl;
	}
	else // Caso contrário imprime as informações dos Pokemons 
	{
		//Nome: NOME
		//----------
		//Pokemon: Pikachu
		//Tipo ataque: Relampago
		//Dano: 10
		//Energia: 100
		//----------
		//(Informações Pokemon 1)
		//----------
		cout << "Nome: " << _nome << endl;
		cout << "----------" << endl;
		for (unsigned int i = 0; i < _pokemons.size(); i++)
		{
			cout << "Pokemon: " << _pokemons[i]->_nome << endl;
			cout << "Tipo ataque: " << _pokemons[i]->_tipo_ataque << endl;
			cout << "Dano: " << _pokemons[i]->calcular_dano() << endl;
			cout << "Energia: " << _pokemons[i]->_energia << endl;
			cout << "----------" << endl;
		}
	}
}