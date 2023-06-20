#ifndef PESQUISA_HPP
#define PESQUISA_HPP

#include "arquivo.hpp"
#include "utils.hpp"

#include <map>
#include <set>
#include <string>
#include <sstream>

class Pesquisa
{
private:
	Arquivo arquivo;

public:
	Pesquisa();
	explicit Pesquisa(const Arquivo &arquivo);
	std::map<std::string, int> retornarRelevanciaFrase(const std::string &frase);
	std::set<std::string> ajustarPesquisaFrase(const std::string &frase);
	std::set<std::string> nomesDosArquivos(const std::map<std::string, std::set<std::string>> &words);
	bool seraQueEhRelevante(const std::map<std::string, std::set<std::string>> &words, const std::set<std::string> &palavras, const std::string &arquivo);
};

#endif // PESQUISA_HPP
