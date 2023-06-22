#ifndef PESQUISA_HPP
#define PESQUISA_HPP

#include "arquivo.hpp"
#include "utils.hpp"

#include <map>
#include <vector>
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
	std::vector<std::string> ajustarPesquisaFrase(const std::string &frase);
	std::vector<std::string> nomesDosArquivos(const std::map<std::string, std::vector<std::string>> &words);
	bool seraQueEhRelevante(const std::map<std::string, std::vector<std::string>> &words, const std::vector<std::string> &palavras, const std::string &arquivo);
	int quantidadeRelevancia(const std::map<std::string, std::vector<std::string>> &words, const std::vector<std::string> &palavras, const std::string &arquivo, std::map<std::string, std::map<std::string, int>> contadorPalavras);
};

#endif // PESQUISA_HPP
