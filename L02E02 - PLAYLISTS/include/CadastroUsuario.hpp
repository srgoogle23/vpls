#ifndef CADASTRO_USUARIO_HPP
#define CADASTRO_USUARIO_HPP

#include "Playlist.hpp"

using namespace std;

class CadastroUsuario
{
    public:
		map<string, Playlist> _playlists;
		void adicionar_playlist(string nome);
		void adicionar_filme(string nome_playlist, string nome_filme, string genero_filme, int duracao_filme);
		void remover_filme_por_nome(string nome_playlist, string nome_filme);
		void imprimir_detalhes_playlist(string nome_playlist, int tipo_ordenacao);
		void imprimir_informacoes_gerais();
};

#endif