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
		this->palavrasFormatadas[this->palavras[i]].push_back(pegarNome());
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

std::map<std::string, std::vector<std::string>> Arquivo::pegarPalavrasFormatadas()
{
	return palavrasFormatadas;
}

void Arquivo::configurarPalavrasFormatadas(std::map<std::string, std::vector<std::string>> words)
{
	this->palavrasFormatadas = words;
}

void Arquivo::misturarPalavrasFormatadas(std::map<std::string, std::vector<std::string>> words, std::string nomeArquivo)
{
	for (const auto &word : words)
	{
		for (const auto &file : word.second)
		{
			if (this->contadorPalavras[word.first].find(file) != this->contadorPalavras[word.first].end())
			{
				this->contadorPalavras[word.first][file] += 1;
			}
			else
			{
				this->contadorPalavras[word.first][file] = 1;
			}
		}
	}

	std::map<std::string, std::vector<std::string>> wordsFinal = this->pegarPalavrasFormatadas();
	for (auto &word : words)
	{
		if(wordsFinal.find(word.first) != wordsFinal.end())
		{
			wordsFinal[word.first].push_back(nomeArquivo);
		}
		else
		{
			wordsFinal[word.first].push_back(nomeArquivo);
		}
	}

	configurarPalavrasFormatadas(wordsFinal);
}

std::map<std::string, std::map<std::string, int>> Arquivo::pegarContadorPalavras(){
	return this->contadorPalavras;
}