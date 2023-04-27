#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include "Filme.hpp"
#include <map>

using namespace std;

class Playlist
{
    public:
        string _nome;
		map<string, Filme> _filmes;

		Playlist();
		Playlist(string nome);
		void adicionar_filme(string nome, string genero, int duracao);
		void remover_filme_por_nome(string nome);
		void imprimir_playlist(int tipo_ordenacao);
};

#endif