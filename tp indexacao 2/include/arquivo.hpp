#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <set>

class Arquivo
{
private:
	std::string nomeArquivo;
	std::vector<std::string> palavras;
	std::map<std::string, std::set<std::string>> palavrasFormatadas;

public:
	Arquivo();
	Arquivo(std::string nomeArquivo);
	void configurarNome(std::string nomeArquivo);
	std::string pegarNome();
	void pegarPalavras();
	void pegarArquivo();
	void mudarLetras();
	void mostrar();
	std::map<std::string, std::set<std::string>> pegarPalavrasFormatadas();
	void configurarPalavrasFormatadas(std::map<std::string, std::set<std::string>> words);
	void misturarPalavrasFormatadas(std::map<std::string, std::set<std::string>> words, std::string nomeArquivo);
};

#endif