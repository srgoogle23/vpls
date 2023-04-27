#include "CadastroUsuario.hpp"

void CadastroUsuario::adicionar_playlist(string nome)
{
	Playlist playlist(nome);
	_playlists[nome] = playlist;
}

void CadastroUsuario::adicionar_filme(string nome_playlist, string nome_filme, string genero_filme, int duracao_filme)
{
	// se a playlist não existir, cria uma nova
	if(_playlists.find(nome_playlist) == _playlists.end())
	{
		Playlist playlist(nome_playlist);
		_playlists.insert(pair<string, Playlist>(nome_playlist, playlist));
	}
	// adiciona o filme na playlist
	_playlists[nome_playlist].adicionar_filme(nome_filme, genero_filme, duracao_filme);
}

void CadastroUsuario::remover_filme_por_nome(string nome_playlist, string nome_filme)
{
	// se a playlist existir, remove o filme
	if(_playlists.find(nome_playlist) != _playlists.end())
	{
		_playlists[nome_playlist].remover_filme_por_nome(nome_filme);
	}
	else // "Playlist nao encontrada: NOMEPLAYLIST!"
	{
		cout << "Playlist nao encontrada: " << nome_playlist << "!" << endl;
	}
}

void CadastroUsuario::imprimir_detalhes_playlist(string nome_playlist, int tipo_ordenacao)
{
	// e nenhuma playlist foi cadastrada anteriormente, imprimir: "Nenhuma playlist cadastrada!" (com quebra de linha ao final).
	if(_playlists.size() == 0)
	{
		cout << "Nenhuma playlist cadastrada!" << endl;
		return;
	}


	// se a playlist existir, imprime os detalhes
	if(_playlists.find(nome_playlist) != _playlists.end())
	{
		_playlists[nome_playlist].imprimir_playlist(tipo_ordenacao);
	}
	else 
	{
		// Playlist nao encontrada: NOMEPLAYLIST!
		cout << "Playlist nao encontrada: " << nome_playlist << "!" << endl;
	}
}

void CadastroUsuario::imprimir_informacoes_gerais()
{
	if(_playlists.size() == 0)
	{
		cout << "Nenhuma playlist cadastrada!" << endl;
		return;
	}
	// imprime as informações de todas as playlists
	for(auto it = _playlists.begin(); it != _playlists.end(); it++)
	{

		// Playlist: nome
		cout << "Playlist: " << it->first << endl;
		imprimir_detalhes_playlist(it->first, 0);
	}
}