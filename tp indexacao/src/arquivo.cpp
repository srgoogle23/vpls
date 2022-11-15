#include "arquivo.hpp"
#include "utils.hpp"

void Arquivo::mesclarWords(map<string, set<string>> words, string nome)
{
	map<string, set<string>, less<string>> wordsFinal = this->getWords();
	for (auto &word : words)
	{
		// se word ja existe no wordsFinal
		if (wordsFinal.find(word.first) != wordsFinal.end())
		{
			// adiciona o nome no set
			wordsFinal[word.first].insert(nome);
		}
		else
		{
			wordsFinal[word.first].insert(nome);
		}
	}

	setWords(wordsFinal);

}

void Arquivo::setWords(map<string, set<string>> words)
{
	this->formatedWords = words;
}

map<string, set<string>> Arquivo::getWords()
{
	return formatedWords;
}

void Arquivo::setNome(string nome)
{
	this->nome = nome;
}

void Arquivo::imprimir()
{
	for (auto &word : formatedWords)
	{
		cout << word.first << " ";
		for (auto &file : word.second)
		{
			cout << file << " ";
		}
		cout << endl;
	}
}

Arquivo::Arquivo()
{
}

Arquivo::Arquivo(string nome)
{
	this->nome = nome;
}

string Arquivo::getNome()
{
	return this->nome;
}

void Arquivo::lePalavras()
{
	ifstream arquivo(this->nome.c_str());
	string palavra1;
	string palavra2;
	while (arquivo >> palavra2)
	{
		// converte string para string
		palavra1.assign(palavra2.begin(), palavra2.end());
		this->palavras.push_back(palavra1);
	}
	arquivo.close();
}

void Arquivo::substituiCaracteres()
{
	for (unsigned int i = 0; i < this->palavras.size(); i++)
	{
		this->palavras[i] = Utils::removerAcentos(this->palavras[i]);
	}
}

void Arquivo::lerArquivo()
{
	lePalavras();
	substituiCaracteres();
	for (unsigned int i = 0; i < this->palavras.size(); i++)
		this->formatedWords[this->palavras[i]].insert(getNome());
}