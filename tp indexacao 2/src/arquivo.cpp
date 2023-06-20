#include "arquivo.hpp"
#include "utils.hpp"

Arquivo::Arquivo() {}

Arquivo::Arquivo(std::string nomeArquivo)
{
	this->nomeArquivo = nomeArquivo;
}

void Arquivo::configurarNome(std::string nomeArquivo)
{
	this->nomeArquivo = nomeArquivo;
}

std::string Arquivo::pegarNome()
{
	return this->nomeArquivo;
}

void Arquivo::pegarPalavras()
{
	std::ifstream arquivo(this->nomeArquivo);
	std::string palavra;
	while (arquivo >> palavra)
	{
		this->palavras.push_back(palavra);
	}
	arquivo.close();
}

void Arquivo::mudarLetras()
{
	for (unsigned int i = 0; i < this->palavras.size(); i++)
	{
		this->palavras[i] = Utils::removerDetalhesPalavras(this->palavras[i]);
	}
}

void Arquivo::pegarArquivo()
{
	pegarPalavras();
	mudarLetras();
	for (unsigned int i = 0; i < this->palavras.size(); i++)
	{
		this->palavrasFormatadas[this->palavras[i]].insert(pegarNome());
	}
}

void Arquivo::mostrar()
{
	for (const auto &word : palavrasFormatadas)
	{
		std::cout << word.first << " ";
		for (const auto &file : word.second)
		{
			std::cout << file << " ";
		}
		std::cout << std::endl;
	}
}

std::map<std::string, std::set<std::string>> Arquivo::pegarPalavrasFormatadas()
{
	return palavrasFormatadas;
}

void Arquivo::configurarPalavrasFormatadas(std::map<std::string, std::set<std::string>> words)
{
	this->palavrasFormatadas = words;
}

void Arquivo::misturarPalavrasFormatadas(std::map<std::string, std::set<std::string>> words, std::string nomeArquivo)
{
	std::map<std::string, std::set<std::string>> wordsFinal = this->pegarPalavrasFormatadas();
	for (const auto &word : words)
	{
		if (wordsFinal.find(word.first) != wordsFinal.end())
		{
			wordsFinal[word.first].insert(nomeArquivo);
		}
		else
		{
			wordsFinal[word.first].insert(nomeArquivo);
		}
	}
	configurarPalavrasFormatadas(wordsFinal);
}