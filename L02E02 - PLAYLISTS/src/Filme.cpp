#include "Filme.hpp"

Filme::Filme(): _nome(""), _genero(""), _duracao(0)
{
}

Filme::Filme(string nome, string genero, int duracao) : _nome(nome), _genero(genero), _duracao(duracao)
{
}

void Filme::imprimir_dados()
{
	// "NOME (GENERO) Xmin" (X é a duração), com uma quebra de linha ao final (com tab separando a duração e o gênero).
	cout << _nome << " (" << _genero << ")\t" << _duracao << "min" << endl;
}