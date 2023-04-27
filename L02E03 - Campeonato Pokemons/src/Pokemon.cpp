#include "Pokemon.hpp"

Pokemon::Pokemon() : _nome(""), _tipo_ataque(""), _forca_ataque(0)
{
}

Pokemon::Pokemon(string nome, string tipo_ataque, double forca_ataque) : _nome(nome), _tipo_ataque(tipo_ataque), _forca_ataque(forca_ataque)
{
}

void Pokemon::falar_nome()
{
	//imprime o nome do pokemon no formato: "Nome!" (seguido de quebra de linha).
	cout << _nome << "!" << endl;
}

void Pokemon::falar_tipo_ataque()
{
	// imprime o tipo do ataque no formato: "Tipo!" (seguido de quebra de linha).
	cout << _tipo_ataque << "!" << endl;
}

void Pokemon::imprimir_status()
{
	//Nome!
	//Energia: Y
	falar_nome();
	cout << "Energia: " << _energia << endl;
}

void Pokemon::imprimir_informacoes()
{
	//Pokemon: NOME
	//Tipo ataque: TIPO
	//Dano: X
	//Energia: Y
	cout << "Pokemon: " << _nome << endl;
	cout << "Tipo ataque: " << _tipo_ataque << endl;
	cout << "Dano: " << calcular_dano() << endl;
	cout << "Energia: " << _energia << endl;
}

void Pokemon::atacar(Pokemon *outro_pokemon)
{
	// - Fala o próprio nome
	// - Fala o tipo do ataque
	// - Calcula o dano e imprime: "Dano: X"
	// - Aplica o dano no outro Pokemon

	falar_nome();
	falar_tipo_ataque();
	cout << "Dano: " << calcular_dano() << endl;
	outro_pokemon->receber_dano(calcular_dano());
}

void Pokemon::receber_dano(double valor_dano)
{
	// O valor do dano informado deve ser subtraído da energia atual do pokemon. A energia nunca deve ficar negativa, sendo o menor valor válido 0. Caso a energia seja zerada, deve-se imprimir a mensagem: "NOME morreu!" (seguido de quebra de linha).
	_energia -= valor_dano;
	if (_energia <= 0)
	{
		cout << _nome << " morreu!" << endl;
		_energia = 0;
	}
}