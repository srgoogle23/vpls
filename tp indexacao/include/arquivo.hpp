#ifndef __ARQUIVO_HPP__
#define __ARQUIVO_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Arquivo
{
	private:
		string nome;
		vector<string> palavras;
		map<string, set<string>, less<string>> formatedWords;

	public:
		Arquivo();
		Arquivo(string nome);
		void setNome(string nome);
		string getNome();
		void lePalavras();
		void lerArquivo();
		void substituiCaracteres();
		void imprimir();
		map<string, set<string>> getWords();
		void setWords(map<string, set<string>> words);
		void mesclarWords(map<string, set<string>> words, string nome);
};

#endif

// how to see code coverage done in doctest c