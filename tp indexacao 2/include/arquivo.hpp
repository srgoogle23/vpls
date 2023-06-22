#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <vector>

class Arquivo
{
private:
	std::string nomeArquivo;
	std::vector<std::string> palavras;
	std::map<std::string, std::vector<std::string>> palavrasFormatadas;
	std::map<std::string, std::map<std::string, int>> contadorPalavras;

public:
	Arquivo();
	Arquivo(std::string nomeArquivo);
	void configurarNome(std::string nomeArquivo);
	std::map<std::string, std::map<std::string, int>> pegarContadorPalavras();
	std::string pegarNome();
	void pegarPalavras();
	void pegarArquivo();
	void mudarLetras();
	void mostrar();
	std::map<std::string, std::vector<std::string>> pegarPalavrasFormatadas();
	void configurarPalavrasFormatadas(std::map<std::string, std::vector<std::string>> words);
	void misturarPalavrasFormatadas(std::map<std::string, std::vector<std::string>> words, std::string nomeArquivo);
};

#endif