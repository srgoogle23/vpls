#ifndef __PESQUISA_HPP__
#define __PESQUISA_HPP__

#include "arquivo.hpp"
#include "utils.hpp"

#include <sstream>

class Pesquisa
{
	private:
		Arquivo arquivo;
	public:
		Pesquisa();
		Pesquisa(Arquivo arquivo);
		map<string, int, less<string>> pesquisaRelavancia(string frase);
		set<string> normalizaPesquisa(string frase);
		set<string> procuraNomeArquivos(map<string, set<string>> words);
		bool relavante(map<string, set<string>> words, set<string> palavras, string arquivo);
};

#endif