#include "Campeonato.hpp"

Campeonato::Campeonato()
{
}

void Campeonato::cadastrar_treinador(std::string nome)
{
	_treinadores.push_back(new Treinador(nome));
}

void Campeonato::cadastrar_pokemon_eletrico(int idt, string nome, string tipo_ataque, double forca_ataque, double potencia_raio)
{
	_treinadores[idt]->cadastrar_pokemon_eletrico(nome, tipo_ataque, forca_ataque, potencia_raio);
}

void Campeonato::cadastrar_pokemon_aquatico(int idt, string nome, string tipo_ataque, double forca_ataque, double litros_jato)
{
	_treinadores[idt]->cadastrar_pokemon_aquatico(nome, tipo_ataque, forca_ataque, litros_jato);
}

void Campeonato::cadastrar_pokemon_explosivo(int idt, string nome, string tipo_ataque, double forca_ataque, double temperatura_explosao)
{
	_treinadores[idt]->cadastrar_pokemon_explosivo(nome, tipo_ataque, forca_ataque, temperatura_explosao);
}

void Campeonato::imprimir_informacoes_treinador(int idt)
{
	// método que imprime as informações de um determinado treinador (de acordo com o índice).
	_treinadores[idt]->imprimir_informacoes();
}

void Campeonato::executar_batalha(int idt1, int idpk1, int idt2, int idpk2)
{
	// ### Batalha ###
	// TREINADOR1 (POKEMON1) vs. TREINADOR2 (POKENON2)
	// - Chamar método atacar (nesse caso, POKEMON1 ataca o POKEMON2)
	// - Imprimir o status do pokemon atacado (nesse caso, POKEMON2)
	// #########

	cout << "### Batalha ###" << endl;
	cout << _treinadores[idt1]->_nome << " (" << _treinadores[idt1]->usar_pokemon(idpk1)->_nome << ") vs. " << _treinadores[idt2]->_nome << " (" << _treinadores[idt2]->usar_pokemon(idpk2)->_nome << ")" << endl;
	_treinadores[idt1]->usar_pokemon(idpk1)->atacar(_treinadores[idt2]->usar_pokemon(idpk2));
	_treinadores[idt2]->usar_pokemon(idpk2)->imprimir_status();
	cout << "#########" << endl;
}