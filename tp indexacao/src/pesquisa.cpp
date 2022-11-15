#include "pesquisa.hpp"

bool Pesquisa::relavante(map<string, set<string>> words, set<string> palavras, string arquivo)
{
	map<string, string> wordsOfFile;
	for (auto &word : words)
		for (auto &file : word.second)
			if (file == arquivo)
				wordsOfFile[word.first] = file;
	unsigned int qtdWords = palavras.size();
	unsigned int counter = 0;
	for (auto &wordsOfFile: wordsOfFile)
		for (auto &palavra: palavras)
			if (wordsOfFile.first == palavra)
				counter++;

	return counter == qtdWords;
}

map<string, int, less<string>> Pesquisa::pesquisaRelavancia(string frase)
{
	map<string, set<string>, less<string>> words = arquivo.getWords();
	set<string> palavrasFrase = normalizaPesquisa(frase);
	set<string> arquivos = procuraNomeArquivos(words);
	map<string, int, less<string>> arquivosPesquisa;
	for (auto &arquivo : arquivos)
		arquivosPesquisa[arquivo] = 0;

	for(auto &arquivo: arquivosPesquisa)
		if (relavante(words, palavrasFrase, arquivo.first))
			arquivo.second++;

	for (auto &arquivo: arquivosPesquisa)
		if(arquivo.second > 0)
			cout << arquivo.first << " " << arquivo.second << endl;

	return arquivosPesquisa;
}

set<string>  Pesquisa::procuraNomeArquivos(map<string, set<string>> words)
{
	set<string> arquivos;
	for (auto &word : words)
	{
		for (auto &file : word.second)
		{
			arquivos.insert(file);
		}
	}
	return arquivos;
}

set<string> Pesquisa::normalizaPesquisa(string frase)
{
	set<string> palavrasFrase;
	stringstream ss(frase);
	string palavra;
	while (ss >> palavra)
		palavrasFrase.insert(Utils::removerAcentos(palavra));
	return palavrasFrase;
}

Pesquisa::Pesquisa()
{
}

Pesquisa::Pesquisa(Arquivo arquivo)
{
	this->arquivo = arquivo;
}
