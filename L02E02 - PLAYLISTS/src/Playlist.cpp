#include "Playlist.hpp"

Playlist::Playlist(): _nome("")
{
}

Playlist::Playlist(string nome): _nome(nome)
{
}

void Playlist::adicionar_filme(string nome, string genero, int duracao)
{
	Filme filme(nome, genero, duracao);
	_filmes.insert(pair<string, Filme>(nome, filme));
}

void Playlist::remover_filme_por_nome(string nome)
{
	if(_filmes.find(nome) != _filmes.end())
		_filmes.erase(nome);
	else // "Filme nao encontrado: NOME!"
		cout << "Filme nao encontrado: " << nome << "!" << endl; 
}

void Playlist::imprimir_playlist(int tipo_ordenacao)
{
	// imprime a coleção de filmes da playlist de acordo com o tipo de ordenação informado.
	// Tipo=0 (ordem alfabética do nome),
	// Tipo=1 (ordenado pela duração, do menor para o maior).
	// Ao final, deve-se imprimir: "Tempo total: TTh", seguido de quebra de linha,
	// onde TT representa o tempo total dos filmes no formato HH:MM (horas:minutos).
	// Você deve pensar como fazer a conversão de minutos para esse formato.
	// Se não houver filmes cadastrados, imprimir: "Nenhum filme cadastrado na playlist: NOME!"

	// se nao houver filmes cadastrados
	if(_filmes.size() == 0)
	{
		cout << "Nenhum filme cadastrado na playlist: " << _nome << "!" << endl;
		return;
	}

	int total_minutos = 0;
	if(tipo_ordenacao == 0) // ordem alfabética do nome
	{
		map<string, Filme, less<string>> filmes_ordenados;
		filmes_ordenados = _filmes;
		// para cada filme, imprime os dados e soma o total minutos
		for(auto filme : filmes_ordenados)
		{
			filme.second.imprimir_dados();
			total_minutos += filme.second._duracao;
		}
	}
	else if(tipo_ordenacao == 1) // ordenado pela duração, do menor para o maior
	{
		map<int, Filme, less<int>> filmes_ordenados;
		// para cada filme, insere no map ordenado pela duração
		for(auto filme : _filmes)
		{
			filmes_ordenados[filme.second._duracao] = filme.second;
		}
		// para cada filme, imprime os dados e soma o total minutos
		for(auto filme : filmes_ordenados)
		{
			filme.second.imprimir_dados();
			total_minutos += filme.second._duracao;
		}
	}

	// calcula o tempo total
	int horas = total_minutos / 60;
	int minutos = total_minutos % 60;

	// se horas ou minutos forem menores que 10, imprime com 0 na frente
	if(horas < 10)
		if(minutos < 10)
			cout << "Tempo total: 0" << horas << ":0" << minutos << "h" << endl;
		else
			cout << "Tempo total: 0" << horas << ":" << minutos << "h" << endl;
	else
		if(minutos < 10)
			cout << "Tempo total: " << horas << ":0" << minutos << "h" << endl;
		else
			cout << "Tempo total: " << horas << ":" << minutos << "h" << endl;
}